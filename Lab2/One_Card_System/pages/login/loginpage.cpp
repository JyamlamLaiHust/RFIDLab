#include "loginpage.h"
#include "ui_loginpage.h"
#include <qdebug.h>
#include "tools/tools.h"
#include "database/dbmanager.h"
#include <QMessageBox>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 登陆页面,用于验证管理员,有些操作需要权限,只有登陆了才能进行操作
***************************************/
LoginPage::LoginPage(QWidget *parent, QString *name) :QDialog(parent),ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->name = name;
    QWidget::setTabOrder(ui->lineEdit_Name, ui->lineEdit_Passwd);
    QWidget::setTabOrder(ui->lineEdit_Passwd, ui->btn_Login);
    QWidget::setTabOrder( ui->btn_Login, ui->btn_Return);
}

LoginPage::~LoginPage()
{
    delete ui;
}
/**
 * @brief LoginPage::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void LoginPage::on_btn_Return_clicked()
{
    this->close();
}
/**
 * @brief LoginPage::on_btn_Login_clicked
 * 登陆按钮点击事件
 */
void LoginPage::on_btn_Login_clicked()
{
    QMessageBox message;
    QString name = ui->lineEdit_Name->text();
    QString pwd = ui->lineEdit_Passwd->text();
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
    if(pwd.toUtf8().length() < 6)
    {
        message.setText(tr("密码长度有问题，长度应该大于等于6个字母的长度。"));
        message.exec();
        return;
    }
    AdminTableModel *adminitable = new AdminTableModel(this);
    adminitable->bindTable();
    if(adminitable->getModel()->rowCount() == 0)
    {
        adminitable->insertRecords(tr("admin"),GetMD5String(tr("123456")),CurrentDateTime());
    }
    QSqlRecord record = adminitable->findRecord(name);
    if(record.count() == 0)
    {
        message.setText(tr("该用户不存在，请重新输入！"));
        message.exec();
        return;
    }
    else
    {
//        qDebug() << GetMD5String(pwd) << record.value(1).toString();
        if(GetMD5String(pwd) == record.value(1).toString())//密码采用简单的MD5加密,在实际的使用中需要结合多种加密技术
        {
            *(this->name) = name;
            this->close();
            return;
        }
        else
        {
            message.setText(tr("您输入的密码有误，请重新输入！"));
            message.exec();
            return;
        }
    }
    delete adminitable;
}
