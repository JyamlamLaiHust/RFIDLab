#include "uhf_thread.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>

UHF_Thread::UHF_Thread(QObject *parent) : QThread(parent)
{    
    serialport = new QSerialPort();
    Dll = new M900Dll();//dll链接库
}
UHF_Thread::~UHF_Thread()
{

}
void UHF_Thread::run()
{
    char data[1024];
    //帧的标志，数据的长度，长度，指令，状态，数据数组下标
    int flag = UHF_RPC_SOF, length=0, len=0, cmd=0, status=0, index = 0;
    while(nRunFlag)
    {
        char ch;
        if(serialport->bytesAvailable())//如果可以读取
        {
            if(!serialport->read(&ch,1) || (ch&0xff) == 0xff)//如果没有读到数据 或者 读到的是0xff 退出本次循环
                continue;
            switch(flag)
            {
            case UHF_RPC_SOF://头
                /*初始化长度、数组和数组下标*/
                len = 0;
                index = 0;
                memset(data,0,sizeof(data));
                if((ch&0xff) == UHF_SOF)
                    flag = UHF_RPC_LEN;
                break;
            case UHF_RPC_LEN://长度
                len = ch;
                flag = UHF_RPC_CMD;
                break;
            case UHF_RPC_CMD://指令
                cmd = ch;
                flag = UHF_RPC_STA;
                len--;
                break;
            case UHF_RPC_STA://状态
                status = ch;
                flag = UHF_RPC_DAT;
                len--;
                length = len-1;//length 是数据的长度
                break;
            case UHF_RPC_DAT://数据
                len--;
                if(len > 1)
                {
                    data[index++] = ch;
                }else if(len == 1)
                {
                    flag = UHF_RPC_EOF;
                }else if(len <= 0)
                {
                    flag = UHF_RPC_SOF;
                }
                break;
            case UHF_RPC_EOF://尾
                flag = UHF_RPC_SOF;
                if((ch&0xff) == UHF_EOF)
                {
                    Process_data(cmd,data,length,status);//数据处理
                    serialport->clear();
                }
                break;
            default:
                flag = UHF_RPC_SOF;
                break;
            }
        }
        QThread::msleep(10);
    }
}

void UHF_Thread::Process_data(int cmd, char data[], int length, int status)
{
    Tools tools;
    switch(cmd)
    {
    case UHFCMD_GET_STATUS:// 询问状态
        break;
    case UHFCMD_GET_POWER:// 读取功率
        break;
    case UHFCMD_SET_POWER:// 设置功率
        break;
    case UHFCMD_GET_FRE:// 读取频率
        break;
    case UHFCMD_SET_FRE:// 设置频率
        break;
    case UHFCMD_GET_VERSION:// 读取版本信息
        break;
    case UHFCMD_INVENTORY:// 识别标签（单标签识别）
        emit this->cardID(tools.CharStringtoHexString(NULL,data,length));//发送信号cardID（）
        break;
    case UHFCMD_INVENTORY_ANTI:// 识别标签（防碰撞识别）
        break;
    case UHFCMD_STOP_GET:// 停止操作
        break;
    case UHFCMD_READ_DATA:// 读取标签数据
        break;
    case UHFCMD_WRITE_DATA:// 写入标签数据
        break;
    case UHFCMD_ERASE_DATA:// 擦除标签数据
        break;
    case UHFCMD_LOCK_MEM:// 锁定标签
        break;
    case UHFCMD_KILL_TAG:// 销毁标签
        break;
    case UHFCMD_INVENTORY_SINGLE: // 识别标签（单步识别）
        break;
    case UHFCMD_WIEGAND_INVENTORY:// 韦根识别
        break;
    case UHFCMD_SINGLE_READ_DATA:// 读取标签数据（不指定UII）
        break;
    case UHFCMD_SINGLE_WRITE_DATA:// 写入标签数据（不指定UII）
        break;
    default:
        break;
    }
}

bool UHF_Thread::UART_Disconnect()
{
    serialport->close();
    return true;
}

/*连接串口*/
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

bool UHF_Thread::UHF_INIT()//初始化UHF
{
    char *data = (char *)Dll->UHF_Connect();//获取连接发送指令
    int len = serialport->write(data+1,data[0]);//发送数据，data,len
    if(len)
    {
        qDebug("WRITE SUCCESS!");
    }
    else
    {
        qDebug("WRITE FAILED!");
    }
    return true;
}

bool UHF_Thread::Read_CardID()
{
    char *data = (char *)Dll->UHF_Inventory();//获取读卡指令
    if(serialport->write(data+1,data[0]))//data,len
    {
        qDebug("WRITE SUCCESS!");
    }
    else
    {
        qDebug("WRITE FAILED!");
    }
    return true;
}

