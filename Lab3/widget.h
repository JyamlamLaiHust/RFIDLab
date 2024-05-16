#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>
#include "borrow_return.h"
#include "usermanage.h"
#include "booksmanage.h"
#include "record.h"
#include "sqlite.h"
#include "uhf_thread.h"

#define COMBOBOX_COUNT 2 //下拉列表个数
#define CONNECT_BUTTON_COUNT 2 //控制区域按钮个数

enum Connect_Button_INDEX{ Connect = 0, Disconnect}; //控制区域按钮数组下标 连接 取消连接
enum ComboBox_INDEX{ Serial = 0, Baud }; //下拉列表数组下标 串口 波特率
enum Tab{ Borrow, Return, User, Books }; //标签索引 借书 还书 用户管理 书籍管理

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);    
    void Init_Connect_Operation_Box(); //初始化连接
    void getSerialName(QStringList *list);//获取可用串口名
    void Set_Title();//设置标题
    void Set_Tab();//设置标签
    void setSlot();//设置槽函数
    ~Widget();

signals:

public slots:
    void Uhf_Connect_Button_Click(); //UHF连接按钮单击事件
    void Uhf_Disconnect_Button_Click(); //UHF断开按钮单击事件    
    void Get_Info(QByteArray Info);//获取读卡信息函数
    void Get_User_Info();//发送获取读卡命令
    void RefreshWidget(int index);//切换标签时刷新界面

private:
    QPushButton *Connect_PushButton[CONNECT_BUTTON_COUNT]; //连接区域按钮
    QComboBox *ComboBox[COMBOBOX_COUNT]; //连接区域下拉列表
    QLabel *Title;//标题
    QTabWidget *Tab;//选项卡
    QGroupBox *ConnectGroupBox;//连接区域
    Borrow_Return *borrow_return;//借还书界面
    Record *record;//记录界面
    UserManage *user_manage;//用户管理界面
    BooksManage *books_manage;//图书管理界面
    Sqlite *sql;//数据库相关操作类对象
    UHF_Thread *uhf;//UHF线程对象
};

#endif // WIDGET_H
