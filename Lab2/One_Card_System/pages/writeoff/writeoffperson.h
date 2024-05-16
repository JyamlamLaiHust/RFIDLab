#ifndef WRITEOFFPERSON_H
#define WRITEOFFPERSON_H

#include <QDialog>
#include "serialThread/serialportthread.h"
#include "database/dbmanager.h"
#include "inc/m1356dll.h"

namespace Ui {
class WriteOffPerson;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 用户注销
***************************************/
class WriteOffPerson : public QDialog
{
    Q_OBJECT

public:
    explicit WriteOffPerson(QWidget *parent = 0,SerialPortThread *serialPortThread = 0);
    ~WriteOffPerson();

private slots:
    void on_btn_LogOff_clicked();//注销按钮点击事件

    void on_btn_Return_clicked();//返回按钮点击事件

    void on_btn_Inventory_clicked();//识别按钮点击事件

    void on_tagIdReceived(QString tagId);//卡号接收槽

private:
    Ui::WriteOffPerson *ui;

    SerialPortThread *serialPortThread;//串口线程

    M1356Dll *m1356dll;//13.56MHz模块库
};

#endif // WRITEOFFPERSON_H
