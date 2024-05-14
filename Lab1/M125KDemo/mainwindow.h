#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "tools.h"
#include "inc/m125dll.h"
#include "recordtablemodel.h"
#include <QSerialPort>
#include "database.h"

namespace Ui {
class MainWindow;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-30
 *描述: 门禁管理系统
***************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //私有成员方法
private slots:
    void on_btn_connect_clicked();//连接

    void on_btn_disconnect_clicked();//断开连接

    void on_btn_refresh_clicked();//刷新

    void checkCustomBaudRatePolicy(int idx);//波特率下拉框改变时调用

    void readData();//串口读取接口槽函数

    void handleError(QSerialPort::SerialPortError error);//串口错误槽函数

private:
    void fillPortsParameters(QComboBox *box);//填充参数

private:
    Ui::MainWindow *ui;

    QSerialPort *serialPort;//串口实例

    QIntValidator *intValidator;

    M125Dll *m125dll; //125K的库函数

    RecordTableModel *model; //记录表的Model

    Database *db;//数据库对象
};

#endif // MAINWINDOW_H
