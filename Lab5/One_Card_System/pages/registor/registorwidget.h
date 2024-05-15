#ifndef REGISTORWIDGET_H
#define REGISTORWIDGET_H

#include <QWidget>
#include <QUuid>
#include "database/dbmanager.h"
#include "serialThread/serialportthread.h"
#include "inc/m1356dll.h"
#include <QMessageBox>

namespace Ui {
class RegistorWidget;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 用户注册
***************************************/
class RegistorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegistorWidget(QWidget *parent = 0,SerialPortThread *serial = 0);
    ~RegistorWidget();

private slots:
    void on_btn_Register_clicked();//注册

    void on_btn_Reset_clicked(); //重置

    void on_btn_Inventory_clicked();//识别

    void on_btn_Refresh_clicked();//刷新

    void on_comboBox_UserType_currentIndexChanged(const QString &arg1);//用户类型修改响应槽

    void on_tagIdReceived(QString tagId);//卡号接收槽

private:
    Ui::RegistorWidget *ui;

    QUuid *uuid;//UUID,用于给用户产生唯一UID

    SerialPortThread *serialThread;//串口线程

    M1356Dll *m1356dll;//13.56MHz模块库类

    CardTableModel *cardTableModel; // 房间表的model

    RegisterTableModel *registerTableModel;//注册表的model

    PersonTableModel *personTableModel;//人员表的model
};

#endif // REGISTORWIDGET_H
