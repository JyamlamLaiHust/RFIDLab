#ifndef TABLEINFOPAGES_H
#define TABLEINFOPAGES_H

#include "database/dbmanager.h"
#include "serialThread/serialportthread.h"
#include "inc/m1356dll.h"
#include <QWidget>
#include <QDebug>


namespace Ui {
class TableInfoPages;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述:表格查询
***************************************/
class TableInfoPages : public QWidget
{
    Q_OBJECT

public:
    explicit TableInfoPages(QWidget *parent = 0,SerialPortThread *serial = 0);
    ~TableInfoPages();

private slots:
    void on_btn_Query_clicked();//查询按钮点击事件

    void currentAction(QAction *action);//QAction接收槽

    void updateTableView(QSqlTableModel *model);//更新表TableView视图

    void on_comboBox_currentIndexChanged(const QString &text);//combox索引发生改变时调用

    void on_btn_Enventory_clicked();//识别

    void on_tagIdReceived(QString tagId);//卡号接收槽

private:
    Ui::TableInfoPages *ui;

    QSqlTableModel *currentModel;//用于存放当前的model

    SerialPortThread *serial;//串口线程

     M1356Dll *m1356dll;//13.56MHz模块的库类
};

#endif // TABLEINFOPAGES_H
