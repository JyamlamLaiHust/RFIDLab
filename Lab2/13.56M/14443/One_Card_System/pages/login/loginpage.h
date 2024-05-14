#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class LoginPage;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 登陆页面
***************************************/
class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0,QString *name = 0);
    ~LoginPage();

private slots:
    void on_btn_Return_clicked();//返回

    void on_btn_Login_clicked();//登陆

private:
    Ui::LoginPage *ui;
    QString *name;//用户名
};

#endif // LOGINPAGE_H
