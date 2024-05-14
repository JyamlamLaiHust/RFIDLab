#ifndef DIALOGCARDCONFIG_H
#define DIALOGCARDCONFIG_H

#include <QDialog>
#include "inc/m1356dll.h"
#include "serialThread/serialportthread.h"

namespace Ui {
class DialogCardConfig;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 卡初始化
***************************************/
class DialogCardConfig : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCardConfig(QWidget *parent = 0, SerialPortThread *serialPortThread = 0);

    ~DialogCardConfig();

    void authentication();//授权,对M1卡读写需要授权验证密钥A或者B,这里默认密钥A

private slots:
    void on_lineEdit_Pwd_cursorPositionChanged(int arg1, int arg2);//控制密钥输入效果的槽函数

    void on_checkBox_clicked(bool checked);//是否显示密钥

    void on_btn_Init_clicked();//初始化按钮点击事件

    void on_btn_MemData_clicked();//查看内存数据

    void onDecodeFrame(QByteArray bytes);//串口接收到响应帧后解码输出

    void on_btn_Return_clicked();//返回按钮点击事件

protected:
    bool eventFilter(QObject *obj, QEvent *event);//事件过滤器

private:
    Ui::DialogCardConfig *ui;

    SerialPortThread *serialPortThread;//串口线程

    M1356Dll *m1356dll;//13.56Mhz模块库类

    int currentOps; //记录当前的操作
};

#endif // DIALOGCARDCONFIG_H
