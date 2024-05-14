#ifndef SERIALPORTTHREAD_H
#define SERIALPORTTHREAD_H
#include <QThread>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include "tools/tools.h"
enum ReadRetryTimes
{
    NO_RETRY = 0,
    RETRY_5 = 5,
    RETRY_10 = 10,
    RETRY_15 = 15 ,
    RETRY_20 = 20,
    RETRY_25 = 25,
    RETRY_30 = 30,
    RETRY_35 = 35,
    RETRY_40 = 40,
    RETRY_45 = 45
};//重试次数的枚举类
class SerialPortThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialPortThread(QObject *parent = 0);
    ~SerialPortThread();

    void setSerialPort(QSerialPort *serialport); //设置串口实体

    void stopThread(); //停止线程

    void setRetryTimes(ReadRetryTimes times); //设置读取重试次数

    void writeData(char *data, int frameLen,bool echo = true);//从串口写入数据,echo默认为true,可以将发送的消息打印到您想打印的位置

    bool serialPortIsOpen();//判断串口是否已经打开
private:
    bool Stop; //标志,循环体是否退出

    QSerialPort *serialPort; //串口类

    int retryTimes; //重试次数

    QTimer *timer; //定时器

    QString SendingMsg; //发送的消息

    bool serialIsOpen; //标志串口是否打开

protected:
    void run(void); //循环体

signals:

    void sendMsg(char * data,int frameLen);//发送消息

    void receivedMsg(QByteArray data);//接收消息

    void wirteMsgError(QString msg);//写发生错误消息

    void hasResponse();//串口是否有响应

public slots:

    void onError(); //发送错误信息

    void stopTimer();//停止定时器

};

#endif // SERIALPORTTHREAD_H
