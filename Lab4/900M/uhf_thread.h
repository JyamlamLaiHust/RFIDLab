#ifndef UHF_THREAD_H
#define UHF_THREAD_H
#include <QObject>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "tools.h"
/*添加dll链接库头文件
* pro文件中添加：LIBS += -L D:\QtProject\900M\lib -l M900Dll*/
#include "inc/m900dll.h"
#include "inc/m900dll_global.h"

class UHF_Thread:public QThread
{
    Q_OBJECT
public:
    explicit UHF_Thread(QObject *parent = 0);
    ~UHF_Thread();
    bool UART_Connect(QString ComName, int Baudrate);
    bool UART_Disconnect();
    bool UHF_INIT();
    bool Read_CardID();
    void Process_data(int cmd, char data[], int length, int status);
    bool nRunFlag;
private:    
    M900Dll *Dll;//dll链接库
    QSerialPort *serialport;
signals:
    void cardID(QString cardid);
protected:
    void run();
};

#endif // UHF_THREAD_H
