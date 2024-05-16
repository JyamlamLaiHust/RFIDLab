#ifndef CONSUMEPAGE_H
#define CONSUMEPAGE_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include "tools/tools.h"
#include "serialThread/serialportthread.h"
#include "inc/m1356dll.h"
typedef union
{
  float value_f;
  char  value_b[4];
} ReadValue;//float和字节数组之间的转化

typedef struct {
    QString time;
    QString addr;
    QString readerId;
    float value;
    QString cardId;
    QString remark;
} SendData_t;//消费信息

namespace Ui {
class ConsumePage;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 模拟消费
***************************************/
class ConsumePage : public QWidget
{
    Q_OBJECT

public:
    explicit ConsumePage(QWidget *parent = 0,SerialPortThread *serialPortThread = 0);
    ~ConsumePage();
    void authentication();//授权

protected:
    bool eventFilter(QObject *obj, QEvent *event);//事件过滤器

public slots:
    void updateTime();//更新时间

    void on_cardIdReceived(QString tagId);//卡号接收槽

    void onDecodeFrame(QByteArray bytes);//串口接收到信息后解码输出槽

signals:
       void calcOps(float);//消费计算

private slots:
    void on_btn_OK_clicked();//结账按钮点击槽1

    void readCardId(bool clicked);//识别按钮点击事件

    void on_comboBox_supermarket_currentIndexChanged(int index);//超市下拉框索引发生改变时的接收槽

    void on_btn_OK2_clicked();//结账按钮点击槽2

    void on_btn_OK1_clicked();//结账按钮点击槽3

    void on_btn_OK3_clicked();//结账按钮点击槽4

    void on_readValue(float value, QString cardId);//读取卡内余额信息处理槽

    void on_comboBox_foodName_currentIndexChanged(int index);//食物名称索引发生改变时的接收槽

    void on_comboBox_goodsName_currentIndexChanged(int index);//商品....

    void on_comboBox_castType_currentIndexChanged(int index);//消费类别....

private: //functions
    void handleConnect();//处理连接

    void initViews();//初始化View

    void fillSendData(QString time,QString readerId,
                      QString value,QString cardId,QString remark);//填充消费信息

    bool checkDataValid();//监测数据合法性

private://member
    Ui::ConsumePage *ui;

    QTimer *timer;//定时器,用于更新时间

    QPushButton *currentEnventoryButton;//记录当前点击的是哪个识别按钮

    M1356Dll *m1356dll;//13.56MHz模块库的类

    SerialPortThread *serialPortThread;//串口线程

    //用于存放超市名称,食物名称,商品名称,消费类别名称
    QStringList supermarketName,foodName,goodsName,castName;
    //用于存放对应的地址信息
    QStringList supermarketAddr,cafeteriaAddr,vendorAddr,castAddr;

    int currentOps;//记录当前的操作

    SendData_t sendData;//缓存当前的消费信息

    QMessageBox *messageBox;

    float last_value;//最终值
};

#endif // CONSUMEPAGE_H
