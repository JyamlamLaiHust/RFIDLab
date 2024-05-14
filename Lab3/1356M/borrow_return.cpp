#include "borrow_return.h"

//借书界面
Borrow_Return::Borrow_Return(QWidget *parent) : QWidget(parent)
{
    QString LabelNameUser[] = {"卡号：", "姓名：", "性别：", "年龄："}; //标签文本

    //布局
    QGridLayout *MainLayout = new QGridLayout();//主布局
    QVBoxLayout *UserLayout = new QVBoxLayout();//用户区域布局
    QVBoxLayout *RightLayout = new QVBoxLayout();//右侧布局
    QHBoxLayout *ButtonLayout = new QHBoxLayout();//右侧布局

    //组合框
    QGroupBox *BooksGroupBox = new QGroupBox();
    QGroupBox *UserGroupBox = new QGroupBox();

    sql = new Sqlite();

    //初始化文本框和标签 将文本框和标签添加到布局中
    for(int i = 0; i < Edit_Count_BORROW_RETURN; i++)
    {
        QHBoxLayout *Layout = new QHBoxLayout();
        Edit_User[i] = new QLineEdit();
        Label_User[i] = new QLabel(LabelNameUser[i]);
        Edit_User[i]->setFocusPolicy(Qt::NoFocus); //设置为禁止编辑
        Layout->addWidget(Label_User[i]);
        Layout->addWidget(Edit_User[i]);
        UserLayout->addLayout(Layout);
    }

    //借还书单选按钮
    Borrow = new QRadioButton("借书");
    Return = new QRadioButton("还书");
    Borrow->setChecked(true);
    Function = new QButtonGroup();
    Function->addButton(Borrow);//单选按钮加入按钮组
    Function->addButton(Return);

    ButtonLayout->addWidget(Borrow);
    ButtonLayout->addWidget(Return);
    UserLayout->addLayout(ButtonLayout);
    UserGroupBox->setTitle("用户信息");//设置标题
    UserGroupBox->setLayout(UserLayout);
    UserGroupBox->setFixedSize(200,300);//设置大小

    Table = new QTableWidget();//表格
    Table->setColumnCount(Table_Column_BORROW_RETURN);//设置列数
    Table->setSelectionBehavior ( QAbstractItemView::SelectRows);//选择方式为选中整行
    Table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//不可编辑
    Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽度自适应

    RightLayout->addWidget(Table);

    BooksGroupBox->setTitle("借书列表");//设置组合框标题
    BooksGroupBox->setLayout(RightLayout);

    /*设置图片*/
    QLabel *Picture = new QLabel();
    QImage *jpg = new QImage(":/img/img/book.jpg");
    Picture->setPixmap(QPixmap::fromImage(*jpg));

    MainLayout->addWidget(UserGroupBox,0,0,1,1);
    MainLayout->addWidget(BooksGroupBox,0,1,2,1);
    MainLayout->addWidget(Picture,1,0,1,1);
    MainLayout->setSpacing(20);
    this->setLayout(MainLayout);
}
//表格显示
void Borrow_Return::ShowTable(QSqlQuery query)
{
    //设置表格表头
    Table->setHorizontalHeaderLabels(QStringList()<<"卡号"<<"书名"<<"作者"<<"出版社"<<"总数（本）"<<"剩余（本）");
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

//设置用户信息(卡ID)
void Borrow_Return::SetInfo(QString cardID)
{
    //将用户信息显示到文本框中
    QSqlQuery query = sql->SelectUser(cardID);
    if(query.next())//如果是用户
    {
        for(int i=0; i < Edit_Count_BORROW_RETURN; i++)
        {
            Edit_User[i]->setText(query.value(i).toString());
        }
        //将书信息显示到表格中
        ShowTable(sql->SelectBooksOfBorrow(cardID));//显示表格内容
        return;
    }
    query = sql->SelectBooks(cardID);
    if(query.next())//如果是书
    {
        if(Edit_User[CardId_User_Borrow]->text().isEmpty())
        {
            return;
        }
        if(Borrow->isChecked())
        {
            if(sql->SelectRecord(Edit_User[CardId_User_Borrow]->text(), query.value(0).toString()).next())
            {
                return;
            }
            if(query.value(5).toInt() <= 0)
            {
                return;
            }
            if(sql->InsertRecord(Edit_User[CardId_User_Borrow]->text(), query.value(0).toString()))//将用户ID和书籍编号添加到数据表中
            {
                //书籍的剩余数量-1
                sql->UpdataBooks(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt()-1);
            }
        }
        else
        {
            if(!sql->SelectRecord(Edit_User[CardId_User_Borrow]->text(), query.value(0).toString()).next())
            {
                return;
            }
            if(sql->DeleteRecord(Edit_User[CardId_User_Borrow]->text(), query.value(0).toString()))//将用户ID和书籍编号添加到数据表中
            {
                //书籍的剩余数量+1
                sql->UpdataBooks(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt()+1);
            }
        }
        ShowTable(sql->SelectBooksOfBorrow(Edit_User[0]->text()));//显示表格内容
    }
}

//清空文本框和刷新表格

void Borrow_Return::Clear()
{
    for(int i = 0; i < Edit_Count_BORROW_RETURN; i++)
    {
        Edit_User[i]->clear();
    }
    ShowTable(sql->SelectBooksOfBorrow(Edit_User[0]->text()));//显示表格内容
}
