#ifndef RECHARGEDIALOG_H
#define RECHARGEDIALOG_H

#include <QDialog>
#include "tools/tools.h"
#include "serialThread/serialportthread.h"
#include "inc/m1356dll.h"
#include <QMessageBox>
//float和字节之间的转化
typedef union
{
  float value_f;
  char  value_b[4];
} Float2Bytes;

namespace Ui {
class RechargeDialog;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 充值对话框
***************************************/
class RechargeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RechargeDialog(QWidget *parent = 0,SerialPortThread *serialPortThread = 0);

    ~RechargeDialog();

    void authentication();//授权

protected:
    bool eventFilter(QObject *obj, QEvent *event);//事件过滤器

public slots:
    void on_cardIdReceived(QString tagId);//卡号接收槽

private slots:
    void on_btn_recharge_clicked();//充值

    void on_btn_return_clicked();//返回

    void on_btn_clear_clicked();//清除

    void on_btn_inventory_clicked();//识别

    void on_readValue(float);//读取到余额是调用

    void onDecodeFrame(QByteArray bytes);//串口接收到响应帧后解码输出

signals:
       void calcOps(float); //计算操作

private:
    Ui::RechargeDialog *ui;

    M1356Dll *m1356dll; //13.56MHz模块库的类

    SerialPortThread *serialPortThread;//串口线程

    QMessageBox *messageBox;

    int currentOps;//记录当前的操作

    float last_value;//最终值
};

#endif // RECHARGEDIALOG_H
