#include "serialportthread.h"
#include <qdebug.h>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 单独对串口进行处理的线程,主要提供对串口的读写操作接口
***************************************/
SerialPortThread::SerialPortThread(QObject *parent) : QThread(parent)
{
    serialIsOpen = false;
    Stop = false;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onError()));
    connect(this,SIGNAL(hasResponse()),this,SLOT(stopTimer()));
}
SerialPortThread::~SerialPortThread()
{
}
/**
 * @brief SerialPortThread::stopTimer
 * 停止定时器
 */
void SerialPortThread::stopTimer()
{
    if(timer->isActive())
    {
        timer->stop();
    }
}
/**
 * @brief SerialPortThread::onError
 * 当发送出错时发送错误信号
 */
void SerialPortThread::onError()
{
    QString error = serialPort->errorString();
    if(error == "Unknown error")
        emit wirteMsgError("No Response!");
    else
        emit wirteMsgError(error);
    this->stopTimer();
}
/**
 * @brief SerialPortThread::stopThread
 * 停止串口线程
 */
void SerialPortThread::stopThread()
{
    this->stopTimer();
    this->Stop = true;
    this->destroyed();
}
/**
 * @brief SerialPortThread::setRetryTimes
 * @param times
 * 设置串口重复读取数据
 */
void SerialPortThread::setRetryTimes(ReadRetryTimes times)
{
    this->retryTimes = times;
}
/**
 * @brief SerialPortThread::writeData
 * @param data 要发送的数据
 * @param frameLen 一帧数据的长度
 * @param echo 用于控制是否回显
 * 发送数据
 */
void SerialPortThread::writeData(char * data, int frameLen, bool echo)
{
    int count = 0 ;
    SendingMsg = CharStringtoHexString(tr(" "),data,frameLen);
    qDebug() << "SendMessage: "<< SendingMsg;
    if(echo)
        emit sendMsg(data,frameLen);
    while (frameLen > 0) {
        frameLen -= serialPort->write(data,frameLen);
        count ++;
        if(count > 15)
            break;
    }
    if(!timer->isActive())
        timer->start(2000);
    delete [] data;
}
/**
 * @brief SerialPortThread::serialPortIsOpen
 * @return  如果打开了返回true，否则返回false
 * 判断串口是否打开
 */
bool SerialPortThread::serialPortIsOpen()
{
  return serialIsOpen;
}
/**
 * @brief SerialPortThread::run
 * 线程实体run
 */
void SerialPortThread::run()
{
    int count = retryTimes;
    QByteArray bytes;
    //控制线程循环
    while (!Stop) {
        if(serialPort->isOpen())
        {
            if(serialPort->bytesAvailable() >= 4)
            {
                emit hasResponse();
                bytes = serialPort->readAll();
                if(bytes.at(0) != (char) 0xAA && bytes.at(1) != (char)0xBB)
                    continue;
                qint16 waitforReadLen = (qint16)((bytes.at(2) & 0x00FF) + ((bytes.at(3) & 0x00FF) << 8)) + 4;
                while ((waitforReadLen - bytes.length()) > 0 && count -- > 0)
                {
                    if(serialPort->bytesAvailable() == 0)
                        QThread::usleep(10);
                    else
                    {
                        bytes += serialPort->readAll();
                        count = retryTimes;
                    }
                }
                count = retryTimes;
                for(int i = 0 ; i < bytes.length() ; i ++)
                {
                    if(bytes.at(i) == (char)0xAA && bytes.at(i+1) == (char)0x00)
                    {
                        bytes.remove(i + 1,1);
                    }
                }
                qDebug() << "RecMessage: "<< CharStringtoHexString(tr(" "),bytes.data(),bytes.length());;
                emit receivedMsg(bytes);
            }
        }
        QThread::msleep(20);
    }
}
/**
 * @brief SerialPortThread::setSerialPort
 * @param serialport
 * 设置串口实体类
 */
void SerialPortThread::setSerialPort( QSerialPort *serialport)
{
    this->serialPort = serialport;
    serialIsOpen = serialport->isOpen();
}
