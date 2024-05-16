#include "regist_widget.h"
#include <QMessageBox>
#include <QDebug>

Regist_Widget::Regist_Widget(QWidget *parent) : QWidget(parent)
{
    /*注册账号界面 按钮和标签的文本*/
    char Button_Name[][50] = {"提交","重置","取消"};
    char Label_Name[][50] = {"卡号：","车牌号：", "金额：", "车型："};

    QVBoxLayout *label_layout = new QVBoxLayout();//标签的布局
    /*实例化标签，将标签添加到布局中*/
    for(int i = 0; i < LABEL_COUNT_REGIST; i++)
    {
        Label[i] = new QLabel();
        Label[i]->setText(Label_Name[i]);
        label_layout->addWidget(Label[i]);
    }
    label_layout->setSpacing(30);

    QVBoxLayout *edit_layout = new QVBoxLayout();//文本框的布局
    /*实例化文本框， 将文本框添加到布局中*/
    for(int i = 0; i < EDIT_COUNT_REGIST; i++)
    {
        Edit[i] = new QLineEdit();
        edit_layout->addWidget(Edit[i]);
    }
    QString pattern("[9-0]{3}");
    QRegExp regExp(pattern);
    Edit[Balance_Regist]->setValidator(new QRegExpValidator(regExp, this));
    pattern = "[\u4e00-\u9fa5]{1}[A-Fa-f]{1}[9-0]{5}";
    regExp.setPattern(pattern);
    Edit[Plate_number_Regist]->setValidator(new QRegExpValidator(regExp, this));

    /*实例化车类型下拉列表*/
    Types = new QComboBox();
    /*将类型添加到列表中*/
    QStringList types_text;
    types_text<<"一类车"<<"二类车"<<"三类车"<<"四类车"<<"五类车";
    Types->addItems(types_text);
    /*将列表添加到布局中*/
    edit_layout->addWidget(Types);

    /*说明标签*/
    instruction = new QLabel("一类车:0.5元/公里 二类车:1元/公里 \n三类车:1.5/公里   四类车:1.8/公里 \n五类车:2/公里");

    edit_layout->setSpacing(30);//设置间距

    /*按钮布局*/
    QHBoxLayout *button_layout = new QHBoxLayout();

    /*实例化按钮，将按钮添加到布局中*/
    for(int i = 0; i< BUTTON_COUNT_REGIST; i++)
    {
        PushButton[i] = new QPushButton();
        PushButton[i]->setText(Button_Name[i]);
        button_layout->addWidget(PushButton[i]);
    }
    button_layout->setSpacing(30);

    /*设置总体布局*/
    QGridLayout *mainlayout = new QGridLayout();
    mainlayout->addLayout(label_layout,0,0,1,1);
    mainlayout->addLayout(edit_layout,0,1,1,1);
    mainlayout->addWidget(instruction, 1,1,1,2);
    mainlayout->addLayout(button_layout,2,0,1,2);

    this->setLayout(mainlayout);

    /*按钮的单机事件连接槽*/
    connect(PushButton[Regist_Regist], SIGNAL(clicked()), this, SLOT(Uhf_Regist_Button_Click()));  //连接按钮单击事件连接Uhf_Connect_Button_Click()函数
    connect(PushButton[Rese_Registt], SIGNAL(clicked()), this, SLOT(Uhf_Rese_Button_Click()));//断开按钮单击事件连接Uhf_Disconnect_Button_Click()函数
    connect(PushButton[Cancel_Regist], SIGNAL(clicked()), this, SLOT(Uhf_Cancel_Button_Click()));//注册按钮单击事件连接Uhf_Update_Button_Click()函数
}

void Regist_Widget::Uhf_Regist_Button_Click()
{
    //标签中显示的文本，用于在提示框中显示
    char Label_Name[][50] = {"卡号：","车牌号：", "金额：", "车型："};

    /*如果文本框中存在空，则提示不能为空*/
    for(int i = 0; i < EDIT_COUNT_REGIST; i++)
    {
        if(Edit[i]->text().isEmpty())
        {
            char warning[256];
            sprintf(warning,"%s不能为空",Label_Name[i]);
            QMessageBox::warning(NULL, "warning", warning, QMessageBox::Yes, QMessageBox::Yes);
            return;
        }
    }

    Sqlite sql;
    QSqlQuery Sqlite;
    /*查询卡号是否已经存在*/
    char where[256];
    sprintf(where,"cardID = '%s'",Edit[ID_Regist]->text().toUtf8().data());
    Sqlite = sql.select("user", where);
    if(Sqlite.next())
    {
        QMessageBox::warning(NULL, "warning", "已存在此卡", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    /*将文本框中的信息添加到数据库*/
    sql.add_user(Edit[ID_Regist]->text().toUtf8().data(), Edit[Plate_number_Regist]->text().toUtf8().data(), Types->currentText().toUtf8().data(), Edit[Balance_Regist]->text().toInt());
    QMessageBox::warning(NULL, "warning", "注册成功", QMessageBox::Yes, QMessageBox::Yes);

    /*清空文本框*/
    for(int i = 0; i < EDIT_COUNT_REGIST; i++)
    {
        Edit[i]->clear();
    }
}
void Regist_Widget::Uhf_Rese_Button_Click()
{
    /*清空文本框*/
    for(int i = 0; i < EDIT_COUNT_REGIST; i++)
    {
        Edit[i]->clear();
    }
}
void Regist_Widget::Uhf_Cancel_Button_Click()
{
    /*关闭窗口*/
    this->close();
}
void Regist_Widget::Set_CardID(QString Card_id)
{
    Edit[0]->setText(Card_id);
}

