#include "usermanage.h"

UserManage::UserManage(QWidget *parent) : QWidget(parent)
{
    QString LabelName[] = {"卡号：", "姓名：", "性别：", "年龄："}; //标签文本
    QString ButtonName[] = {"添加", "删除", "修改", "搜索"}; //按钮文本

    //布局
    QVBoxLayout *MainLayout = new QVBoxLayout();//主布局
    QHBoxLayout *ButtonLayout = new QHBoxLayout();//按钮布局
    QHBoxLayout *EditLayout = new QHBoxLayout();//文本框布局
    QHBoxLayout *TableLayout = new QHBoxLayout();//表格布局

    QGroupBox *UserTable = new QGroupBox();//用户表格组合框
    QGroupBox *UserInfo = new QGroupBox();//用户信息组合框

    sql = new Sqlite();//数据库操作相关的对象

    //初始化文本框和标签
    for(int i = 0; i < Edit_Count_USER; i++)
    {
        Edit[i] = new QLineEdit();
        Label[i] = new QLabel(LabelName[i]);
        EditLayout->addWidget(Label[i]);//标签添加到布局中
        EditLayout->addWidget(Edit[i]);//文本框添加到布局中
    }

    QRegExp regExp("[A-Fa-f9-0]*");
    Edit[ID_User]->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[\u4e00-\u9fa5]*");
    Edit[Name_User]->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[男女]");
    Edit[Gender_User]->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[9-0]{2}");
    Edit[Age_User]->setValidator(new QRegExpValidator(regExp, this));

    UserInfo->setLayout(EditLayout);//用户信息组合框设置布局

    //初始化按钮
    for(int i = 0; i < Button_Count_USER; i++)
    {
        Button[i] = new QPushButton();
        Button[i]->setText(ButtonName[i]);
        ButtonLayout->addWidget(Button[i]);//按钮添加到布局中
    }
    ButtonLayout->addStretch(0);
    ButtonLayout->setSpacing(20);

    Table = new QTableWidget();
    Table->setColumnCount(Table_Column_USER);//设置表格列
    Table->setSelectionBehavior ( QAbstractItemView::SelectRows);//选中整行
    Table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//不可编辑
    Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽度自适应
    TableLayout->addWidget(Table);
    UserTable->setTitle("用户列表");
    UserTable->setLayout(TableLayout);

    MainLayout->addWidget(UserInfo);
    MainLayout->addLayout(ButtonLayout);
    MainLayout->addWidget(UserTable);
    MainLayout->setSpacing(10);
    this->setLayout(MainLayout);
    SetSlot();//设置槽函数
}

void UserManage::SetSlot()
{
    connect(Button[Add_User],SIGNAL(clicked()),this,SLOT(add_user()));//添加按钮连接槽函数
    connect(Button[Delete_User],SIGNAL(clicked()),this,SLOT(delete_user()));//删除按钮连接槽函数
    connect(Button[Updata_User],SIGNAL(clicked()),this,SLOT(updata_user()));//修改按钮连接槽函数
    connect(Button[Select_User],SIGNAL(clicked()),this,SLOT(select_user()));//搜索按钮连接槽函数
    connect(Table,SIGNAL(cellClicked(int,int)),this,SLOT(get_table_line(int, int)));//表格点击连接槽函数
}

//添加用户槽函数
void UserManage::add_user()
{
    QString LabelName[] = {"卡号：", "姓名：", "性别：", "年龄："};
     for(int i = 0; i < Edit_Count_USER; i++)
     {
         if(Edit[i]->text().isEmpty())
         {
             QMessageBox::warning(NULL, "warning", LabelName[i]+"不能为空！", QMessageBox::Yes, QMessageBox::Yes);
             return;
         }
     }

     if (sql->SelectBooks(Edit[ID_User]->text()).next())
     {
         QMessageBox::warning(NULL, "warning", "卡号已经注册为书籍！", QMessageBox::Yes, QMessageBox::Yes);
         return;
     }
    int ret = sql->InsertUser(Edit[ID_User]->text(),Edit[Name_User]->text(),Edit[Gender_User]->text(),Edit[Age_User]->text().toInt());
    if(!ret)
    {
        QMessageBox::warning(NULL, "warning", "添加失败，编号已存在！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    QMessageBox::warning(NULL, "warning", "添加成功！", QMessageBox::Yes, QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectUser());
}

//删除用户槽函数
void UserManage::delete_user()
{
    if (!Edit[ID_User]->text().isEmpty() && sql->SelectBooks(Edit[ID_User]->text()).next())
    {
        QMessageBox::warning(NULL, "warning", "卡号已经注册为书籍！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    if (!Edit[ID_User]->text().isEmpty() && !sql->SelectUser(Edit[ID_User]->text()).next())
    {
        QMessageBox::warning(NULL, "warning", "卡号不存在！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    int Age;
    if(Edit[Age_User]->text().isEmpty())
        Age = -1;
    else
        Age = Edit[Age_User]->text().toInt();

    int ret = sql->DeleteUser(Edit[ID_User]->text(),Edit[Name_User]->text(),Edit[Gender_User]->text(),Age);
    if(!ret)
    {
        QMessageBox::warning(NULL, "warning", "删除失败！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    QMessageBox::warning(NULL, "warning", "删除成功！", QMessageBox::Yes, QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectUser());
}

//修改用户信息槽函数
void UserManage::updata_user()
{
    if (!Edit[ID_User]->text().isEmpty() && sql->SelectBooks(Edit[ID_User]->text()).next())
    {
        QMessageBox::warning(NULL, "warning", "卡号已经注册为书籍！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    if (!Edit[ID_User]->text().isEmpty() && !sql->SelectUser(Edit[ID_User]->text()).next())
    {
        QMessageBox::warning(NULL, "warning", "卡号不存在！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    int ret = sql->UpdataUser(Edit[ID_User]->text(),Edit[Name_User]->text(),Edit[Gender_User]->text(),Edit[Age_User]->text().toInt());
    if(!ret)
    {
        QMessageBox::warning(NULL, "warning", "修改失败！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    QMessageBox::warning(NULL, "warning", "修改成功！", QMessageBox::Yes, QMessageBox::Yes);

    ClearEdit();
    ShowTable(sql->SelectUser());
}

//搜索用户槽函数
void UserManage::select_user()
{
    QSqlQuery query;
    if(Edit[Age_User]->text().isEmpty())//如果年龄为空 调用SelectUser时 不传入年龄  默认年龄为-1
        query = sql->SelectUser(Edit[ID_User]->text(),Edit[Name_User]->text(),Edit[Gender_User]->text());
    else
        query = sql->SelectUser(Edit[ID_User]->text(),Edit[Name_User]->text(),Edit[Gender_User]->text(),Edit[Age_User]->text().toInt());
    ShowTable(query);
}

//表格显示数据
void UserManage::ShowTable(QSqlQuery query)
{
    //设置表头
    Table->setHorizontalHeaderLabels(QStringList()<<"卡号"<<"姓名"<<"性别"<<"年龄");
    if(!query.next())
    {
        Table->setRowCount(0);//表格设置行数
        return;
    }
    /*计算record表中数据行数*/
    query.last();//跳转到最后一条数据
    int nRow = query.at() + 1;//取所在行数
    Table->setRowCount(nRow);//表格设置行数
    int row = 0;
    query.first();//返回第一条数据
    do
    {
        for (int col = 0; col<7; col++)//按字段添加数据
        {
            //表格中添加数据库中的数据
            Table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;//行数增加
    }while(query.next());
}

//获取表格中某一行数据 显示在文本框内
void UserManage::get_table_line(int row, int col)
{
    for(int i = 0; i < Edit_Count_USER; i++)
    {
        Edit[i]->setText(Table->item(row,i)->text());
    }
}
//这是卡号
void UserManage::SetCard(QString cardID)
{
    Edit[ID_User]->setText(cardID);
}
//清空文本框
void UserManage::ClearEdit()
{
    for(int i = 0; i < Edit_Count_USER; i++)
    {
        Edit[i]->clear();
    }
}

//清空文本框和刷新表格
void UserManage::Clear()
{
    ClearEdit();
    ShowTable(sql->SelectUser());
}
