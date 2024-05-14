#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include "database/dbmanager.h"
#include "tools/tools.h"
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 修改密码页面(只有管理员)
***************************************/
ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    //设置TAB键的顺序
    QWidget::setTabOrder(ui->lineEdit_Name, ui->lineEdit_Pwd);
    QWidget::setTabOrder(ui->lineEdit_Pwd, ui->lineEdit_NewPwd);
    QWidget::setTabOrder( ui->lineEdit_NewPwd, ui->lineEdit_EnsureNewPwd);
    QWidget::setTabOrder( ui->lineEdit_EnsureNewPwd, ui->btn_Modify);
    QWidget::setTabOrder(ui->btn_Modify,ui->btn_Return);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}
/**
 * @brief ChangePassword::on_btn_Modify_clicked
 * 修改按钮点击事件
 */
void ChangePassword::on_btn_Modify_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString oldPwd = ui->lineEdit_Pwd->text();
    QString newPwd = ui->lineEdit_NewPwd->text();
    QString ensurePaswd = ui->lineEdit_EnsureNewPwd->text();

    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);
    //校验用户名的长度，采用utf8编码，汉语占用2个字符的宽度
    if(name.toUtf8().length() < 4)
    {
        message.setText(tr("用户名长度有问题，长度应该大于等于两个汉字的长度。"));
        message.exec();
        return;
    }
    if(oldPwd.toUtf8().length() < 6)
    {
        message.setText(tr("密码长度有问题，长度应该大于等于6个字母的长度。"));
        message.exec();
        return;
    }
    if(newPwd.toUtf8().length() < 6)
    {
        message.setText(tr("新密码长度有问题，长度应该大于等于6个字母的长度。"));
        message.exec();
        return;
    }
    if(ensurePaswd.toUtf8().length() < 6)
    {
        message.setText(tr("确认新密码长度有问题，长度应该大于等于6个字母的长度。"));
        message.exec();
        return;
    }
    if(newPwd != ensurePaswd)
    {
        message.setText(tr("两次输入的密码不一致，请重新输入。"));
        message.exec();
        ui->lineEdit_EnsureNewPwd->clear();
        ui->lineEdit_NewPwd->clear();
        return;
    }
    AdminTableModel *adminitable = new AdminTableModel(this);
    adminitable->bindTable();
    QSqlRecord record = adminitable->findRecord(name);
    if(record.count() == 0)
    {
        message.setText(tr("该用户不存在，请重新输入！"));
        message.exec();
        delete adminitable;
        return;
    }
    else
    {
        if(GetMD5String(oldPwd) == record.value(1).toString())
        {
            if(adminitable->updateRecords(name,GetMD5String(ensurePaswd),CurrentDateTime()))
            {
                message.setText(tr("密码更新成功！"));
                message.exec();
                this->close();
            }
            else {
                message.setText(tr("密码更新失败！"));
                message.exec();
            }
        }
        else
        {
            message.setText(tr("您输入的密码有误，请重新输入！"));
            message.exec();
        }
        delete adminitable;
    }
}
/**
 * @brief ChangePassword::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void ChangePassword::on_btn_Return_clicked()
{
    this->close();
}
