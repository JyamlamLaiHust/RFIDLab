#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTableWidget>
#include <QtSql/QSqlQueryModel>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMutex>
#include <QRadioButton>
#include <QButtonGroup>
#include <QHeaderView>
#include <QTimer>
#include "regist_widget.h"
#include "sqlite.h"
#include "uhf_thread.h"

#define EDIT_COUNT 5 //文本框个数
#define COMBOBOX_COUNT 2 //下拉列表个数
#define CONNECT_BUTTON_COUNT 2 //控制区域按钮个数
#define UHF_BUTTON_COUNT 3 //UHF区域个数
#define LABEL_COUNT 5 //标签个数
#define GROUPBOX_COUNT 3 //组合框个数

enum Connect_Button_INDEX{ Connect = 0, Disconnect}; //控制区域按钮数组下标
enum Uhf_Button_INDEX{ Regist = 0, TOP_UP, Delete}; //UHF区域按钮数组下标
enum ComboBox_INDEX{ Serial = 0, Baud }; //下拉列表数组下标
enum EDIT_INDEX{ ID = 0, Plate_number, Type, Balance, Top_up};//文本框数组下标
enum GroupBox_INDEX{ ConnectBox = 0, TableView, UHF } ;//组合框数组下标
enum Types{ Type1 = 0, Type2, Type3, Type4, Type5};

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void Uhf_Regist_Button_Click(); //UHF区域注册按钮单击事件
    void Uhf_TOP_UP_Button_Click(); //UHF区域修改按钮单击事件
    void Uhf_Delete_Button_Click(); //UHF区域删除按钮单击事件
    void Uhf_Connect_Button_Click(); //连接按钮单击事件
    void Uhf_Disconnect_Button_Click(); //断开按钮单击事件
    void Get_Info(QString cardID);
    void In_Click();//入口单选按钮单击事件
    void Out_Click();//出口单选按钮单击事件
    void Clear_Table_Data();//清空表数据
    void Delete_Table_Data();//删除表数据
    void Time_Out();

public:
    Widget(QWidget *parent = 0);
    void Init(); //初始化
    void Init_Connect_Operation_Box(); //初始化连接区域
    void Init_TableView_Box(); //初始化表区域
    void Init_UHF_Box(); //初始化UHF区域
    void SetTitile();    //设置标题
    bool Show_Table(); //显示数据库内容到表格中
    void getSerialName(QStringList *list); //获取可用串口名称    
    void SetLocation();//设置收费站位置布局
    void setWidgetLayout();//设置整体布局
    void setSlot();//设置连接槽
    void In_station(QString id, QString plate_number, QString time, float balance);//进站处理
    void Out_station(QString id, QString plate_number, QString time, float consumption, float balance);//出站处理
    ~Widget();
private:
    QPushButton *Connect_PushButton[CONNECT_BUTTON_COUNT]; //连接区域按钮
    QComboBox *ComboBox[COMBOBOX_COUNT]; //连接区域下拉列表
    QPushButton *Uhf_PushButton[UHF_BUTTON_COUNT]; //UHF区域按钮
    QLabel *Label[LABEL_COUNT], *Title, *Picture; //UHF区域标签 标题 图片
    QImage open_jpg, close_jpg;//开关闸机图片
    QGroupBox *GroupBox[GROUPBOX_COUNT]; //区域组合框
    QLineEdit *Edit[EDIT_COUNT]; //UHF区域文本框
    QTableWidget *Uhf_Table; //表
    QPushButton *Clear_Table,*Delete_Table; // 清空表和删除表格数据
    QRadioButton *In,*Out; //收费站位置
    QButtonGroup *Location; //收费站位置
    QLabel *Distance_Label,*unit;//距离标签
    QLineEdit *Distance;//入口和出口的距离
    UHF_Thread *uhf;//uhf读取线程对象
    Sqlite *sqlite; //数据库操作类对象
    QTimer *Timer;//计时器
    QMutex mutex;//锁
    Regist_Widget *regist_widget;//注册界面对象
    QString CardID;
};

#endif // WIDGET_H
