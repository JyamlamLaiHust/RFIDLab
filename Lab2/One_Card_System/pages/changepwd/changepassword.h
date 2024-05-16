#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class ChangePassword;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 修改密码
***************************************/
class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    ~ChangePassword();

private slots:
    void on_btn_Modify_clicked();//修改

    void on_btn_Return_clicked();//返回

private:
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
