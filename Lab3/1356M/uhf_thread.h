#ifndef UHF_THREAD_H
#define UHF_THREAD_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include "inc/m1356dll.h"
#include "inc/m1356dll_global.h"

class UHF_Thread : public QThread //UHF读卡线程类
{
    Q_OBJECT
public:
    explicit UHF_Thread(QObject *parent = 0);
    bool UART_Connect(QString ComName, int Baudrate);//串口连接
    bool UART_Disconnect();//串口关闭
    bool ReadCardID();//发送读卡命令
    bool InitUhf();//发送初始化UHF命令
    bool nRunFlag;//线程run函数中的循环标志 为false时停止run函数中的循环
signals:
    void receivedMsg(QByteArray);//发送接收的数据
    void cycle();//循环读取卡号
public slots:

private:
    QSerialPort *serialport;//串口操作类
    M1356Dll *Dll;//dll库中类的对象

protected:
    void run();
};

#endif // UHF_THREAD_H
