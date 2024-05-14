#include "uhf_thread.h"

UHF_Thread::UHF_Thread(QObject *parent) : QThread(parent)
{
    serialport = new QSerialPort();
    Dll = new M1356Dll();
}
void UHF_Thread::run()
{
    int retryTimes = 45;//超时
    int count = retryTimes;
    enum {UHF_RPC_SOF = 0, UHF_RPC_LEN, UHF_RPC_dev_id, UHF_RPC_CMD, UHF_RPC_STA, UHF_RPC_DAT, UHF_RPC_EOF};
    //帧的标志，数据的长度，长度，指令，状态，数据数组下标
    QByteArray data;
    while(nRunFlag)
    {
        if(serialport->bytesAvailable() >= 4) //只有串口中数据有4个字节时才开始读取
        {
            data = serialport->readAll();//读取全部数据
            if(data.at(0) != (char) 0xAA && data.at(1) != (char)0xBB)//AABB是一帧开始标记
                continue;
            qint16 waitforReadLen = (qint16)((data.at(2) & 0x00FF) + ((data.at(3) & 0x00FF) << 8)) + 4;//计算长度
            while ((waitforReadLen - data.length()) > 0 && count -- > 0 )//count超时时间
            {
                if(serialport->bytesAvailable() == 0)//读不到数据时等待一下，数据到来，继续读取数据
                     QThread::usleep(10);
                else
                {
                    data += serialport->readAll();//读取全部数据
                    count = retryTimes;//超时时间重新计时
                }
            }
            count = retryTimes;//超时时间重新计时
            for(int i = 0 ; i < data.length() ; i ++)
            {
                if(data.at(i) == (char)0xAA && data.at(i+1) == (char)0x00)//0xAA在传输过程中需要加上0x00 读取时需要将0x00去掉
                {
                    data.remove(i + 1,1);
                }
            }

            emit receivedMsg(data);
        }
        QThread::msleep(100);
        emit cycle();//循环读取数据
    }
}


bool UHF_Thread::ReadCardID()
{
    uint16 cmd = RC632_CMD_ISO15693_INVENTORY16;
    char *data = (char *)Dll->RC632_SendCmdReq(cmd,NULL,0);//获取读卡指令
    if(serialport->write(data+2,data[0]))//data,len
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool UHF_Thread::InitUhf()
{
    uint8 data = RC632_WORK_MODEL_15693;
    uint16 cmd = RC632_CMD_CONFIG_ISOTYPE;
    char *senddata = (char *)Dll->RC632_SendCmdReq(cmd,&data,1);//设置为15693类型
    for(int i = 0;i<15;i++)
    {
        qDebug("%x",senddata[i]);
    }

    if(serialport->write(senddata+2,senddata[0]))//data,len
    {
        qDebug("WRITE SUCCESS!");
    }
    else
    {
        qDebug("WRITE FAILED!");
    }
    return true;
}

bool UHF_Thread::UART_Disconnect()
{
    serialport->close();
    return true;
}

//连接串口
bool UHF_Thread::UART_Connect(QString ComName,int Baudrate)
{
    serialport->setPortName(ComName);    //端口号
    serialport->setBaudRate(Baudrate);    //波特率
    serialport->setDataBits(QSerialPort::Data8);//数据位
    serialport->setParity(QSerialPort::NoParity);//奇偶校验
    serialport->setStopBits(QSerialPort::OneStop);//停止位
    serialport->setFlowControl(QSerialPort::NoFlowControl);//流控制
    if (serialport->open(QIODevice::ReadWrite))//以读写方式打开
    {
        qDebug("OPNE SUCCESS!");
        return true;
    }
    else
    {
        qDebug("OPNE FAILED!");
        return false;
    }
}

