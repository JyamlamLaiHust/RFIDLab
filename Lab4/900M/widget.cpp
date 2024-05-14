#include "widget.h"
#include <QDebug>
#include "widget_text.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Init();
}

void Widget::Init()
{
    for(int i = 0; i < GROUPBOX_COUNT; i++) //实例化组合框数组
    {
        GroupBox[i] = new QGroupBox();
    }
    SetTitile(); //设置标题
    SetLocation();//收费站位置
    Init_Connect_Operation_Box(); //初始化控制区域
    Init_UHF_Box(); //初始化UHF区域
    Init_TableView_Box(); //初始化表格区域
    Timer = new QTimer();

    GroupBox[ConnectBox]->setFixedSize(500,60); //固定连接区域尺寸
    GroupBox[UHF]->setFixedSize(300,240); //固定UHF区域尺寸
    GroupBox[UHF]->setDisabled(true); //设置UHF区域初始时不可操作
    GroupBox[TableView]->setDisabled(true); //设置表格区域初始时不可操作

    Connect_PushButton[Disconnect]->setDisabled(true); //断开连接设置为不可编辑

    uhf = new UHF_Thread(this);
    setWidgetLayout(); //设置总体布局
    setSlot(); //设置连接槽函数
    sqlite = new Sqlite();
    if(!sqlite->connect()) //连接数据库
    {
        QMessageBox::warning(NULL, "warning", "数据库连接失败！", QMessageBox::Yes, QMessageBox::Yes);
    }
}

void Widget::setWidgetLayout()
{
    QVBoxLayout *mainlayout = new QVBoxLayout();  //主布局
    QHBoxLayout *TopLayout = new QHBoxLayout(); //顶部布局
    QHBoxLayout *BottomLayout = new QHBoxLayout();//底部布局
    QHBoxLayout *Location_layout = new QHBoxLayout(); //收费站位置布局
    QVBoxLayout *Title_layout = new QVBoxLayout();//标题部分布局
    QVBoxLayout *Uhf_layout = new QVBoxLayout(); //Uhf布局

    /*设置图片*/
    Picture = new QLabel();
    open_jpg.load(":/img/img/open.jpg");
    close_jpg.load(":/img/img/close.jpg");
    Picture->setPixmap(QPixmap::fromImage(close_jpg));

    //设置收费站位置布局
    Location_layout->addWidget(In);
    Location_layout->addWidget(Out);
    Location_layout->addWidget(Distance_Label);
    Location_layout->addWidget(Distance);
    Location_layout->addWidget(unit);

    Title_layout->addWidget(Title);
    Title_layout->addLayout(Location_layout);

    /*UHF区域和图片添加到UHF布局中*/
    Uhf_layout->addWidget(GroupBox[UHF]);
    Uhf_layout->addStretch(1);
    Uhf_layout->addWidget(Picture);

    /*UHF布局和表格区域添加到底部布局*/
    BottomLayout->addWidget(GroupBox[TableView]);
    BottomLayout->addLayout(Uhf_layout);

    /*标题和连接区域添加到顶部布局*/
    TopLayout->addLayout(Title_layout);
    TopLayout->addStretch(1);
    TopLayout->addWidget(GroupBox[ConnectBox]);

    /*顶部布局和底部布局添加到主布局*/
    mainlayout->addLayout(TopLayout);
    mainlayout->addLayout(BottomLayout);
    mainlayout->setMargin(20);//边缘间距20
    this->setLayout(mainlayout);
}



void Widget::setSlot()
{
    connect(Connect_PushButton[Connect], SIGNAL(clicked()), this, SLOT(Uhf_Connect_Button_Click()));  //连接按钮单击事件连接Uhf_Connect_Button_Click()函数
    connect(Connect_PushButton[Disconnect], SIGNAL(clicked()), this, SLOT(Uhf_Disconnect_Button_Click()));//断开按钮单击事件连接Uhf_Disconnect_Button_Click()函数
    connect(Uhf_PushButton[Regist], SIGNAL(clicked()), this, SLOT(Uhf_Regist_Button_Click()));//注册按钮单击事件连接Uhf_Update_Button_Click()函数
    connect(Uhf_PushButton[TOP_UP], SIGNAL(clicked()), this, SLOT(Uhf_TOP_UP_Button_Click()));//充值按钮单击事件连接Uhf_Update_Button_Click()函数
    connect(Uhf_PushButton[Delete], SIGNAL(clicked()), this, SLOT(Uhf_Delete_Button_Click()));//删除按钮单击事件连接Uhf_Delete_Button_Click() 函数
    connect(Clear_Table, SIGNAL(clicked()), this, SLOT(Clear_Table_Data()));//清空表数据
    connect(Delete_Table, SIGNAL(clicked()), this, SLOT(Delete_Table_Data()));//删除表数据
    connect(In, SIGNAL(clicked()), this, SLOT(In_Click()));//入口单选按钮
    connect(Out, SIGNAL(clicked()), this, SLOT(Out_Click()));//出口单选按钮
    connect(uhf, SIGNAL(cardID(QString)), this, SLOT(Get_Info(QString)), Qt::BlockingQueuedConnection);//刷卡响应
    connect(Timer,SIGNAL(timeout()),this, SLOT(Time_Out()));//定时器超时
}

void Widget::SetTitile()
{
    Title = new QLabel(); // 初始化标题标签
    Title->setText("高速收费站");

    /*设置字体*/
    QFont font;
    font.setFamily("黑体");
    font.setPointSize(24);
    Title->setFont(font);

    /*设置字体颜色*/
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    Title->setPalette(pa);
}

void Widget::SetLocation()//设置收费站为入口还是出口的界面布局
{
    In = new QRadioButton("入口");
    Out = new QRadioButton("出口");
    In->setChecked(true);
    Location = new QButtonGroup();
    Distance_Label = new QLabel("距入口");
    unit = new QLabel("公里");
    Distance = new QLineEdit();//入口和出口的距离
    Location->addButton(In);//单选按钮加入按钮组
    Location->addButton(Out);
    Distance_Label->setEnabled(false);
    unit->setEnabled(false);
    Distance->setEnabled(false);
}

void Widget::Init_Connect_Operation_Box()
{
    QHBoxLayout *Connect_Operation_Layout = new QHBoxLayout(); // 连接控制布局

    for(int i = 0; i < COMBOBOX_COUNT; i++)
    {
        //实例化下拉列表
        ComboBox[i] = new QComboBox();
        Connect_Operation_Layout->addWidget(ComboBox[i]);//将下拉列表添加到连接控制布局
    }
    QStringList baud,serial; //串口、波特率 字符串列表
    getSerialName(&serial); //获取可用串口列表
    //设置波特率列表
    baud<<"110"<<"300"<<"1200"<<"2400"<<"4800"<<"9600"<<"19200"<<"38400"<<"57600"<<"115200"<<"230400"<<"460800"<<"921600";
    //下拉列表添加选项
    ComboBox[Baud]->addItems(baud);
    ComboBox[Serial]->addItems(serial);
    ComboBox[Baud]->setCurrentIndex(8);

    for(int i = 0; i < CONNECT_BUTTON_COUNT; i++)
    {        
        Connect_PushButton[i] = new QPushButton();//实例化连接区域按钮
        Connect_Operation_Layout->addWidget(Connect_PushButton[i]);//按钮添加到连接区域
        Connect_PushButton[i]->setText(Connect_Button_Name[i]);//设置按钮名称
    }

    GroupBox[ConnectBox]->setLayout(Connect_Operation_Layout); //连接布局添加连接区域
    GroupBox[ConnectBox]->setTitle(GroupBox_Name[ConnectBox]); //连接区域设置标题
}

void Widget::getSerialName(QStringList *list)
{
    QStringList temp;
    /*查找可用串口*/
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
      {
          QSerialPort serial;
          serial.setPort(info);
          //如果可以打开串口
          if (serial.open(QIODevice::ReadWrite))
          {
              /*字符串列表中没有则添加*/
              if(! list->contains(info.portName(),Qt::CaseSensitive))
                  list->insert(0,info.portName());
              serial.close();
              temp << info.portName();
          }
      }
    for(int i = 0 ; i < list->size() ; i ++)
    {
        if(!temp.contains(list->at(i)))
            list->removeAt(i);
    }
}


void Widget::Init_TableView_Box()
{
    QVBoxLayout *TableView_Layout = new QVBoxLayout(); //表格布局
    QHBoxLayout *Button = new QHBoxLayout();//按钮布局

    Clear_Table = new QPushButton("清空");
    Delete_Table = new QPushButton("删除");
    Button->addWidget(Clear_Table); //添加清空按钮
    Button->addWidget(Delete_Table); //添加删除按钮

    Uhf_Table = new QTableWidget(); //实例化表格
    Uhf_Table->setColumnCount(6); //设置列数
    Uhf_Table->setSelectionBehavior ( QAbstractItemView::SelectRows);//选中整行
    Uhf_Table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//不可编辑
    Uhf_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽度自适应

    TableView_Layout->addWidget(Uhf_Table);//表格添加到表格布局
    TableView_Layout->addLayout(Button); //添加按钮布局

    GroupBox[TableView]->setLayout(TableView_Layout); //表格区域设置布局
    GroupBox[TableView]->setTitle(GroupBox_Name[TableView]);//表格区域标题
}

void Widget::Init_UHF_Box()
{
    QGridLayout *Uhf_Layout = new QGridLayout(); //UHF布局
    for(int i = 0; i < LABEL_COUNT; i++)
    {
        Label[i] = new QLabel();//实例化标签
        Label[i]->setText(Label_Name[i]);//设置标签文本
        Edit[i] = new QLineEdit();//实例化文本框        
        Edit[i]->setFocusPolicy(Qt::NoFocus); //设置为禁止编辑
        Uhf_Layout->addWidget(Label[i],i,0,1,1);//标签添加到UHF布局
        Uhf_Layout->addWidget(Edit[i],i,1,1,4);//文本添加到UHF布局
    }
    Edit[Top_up]->setFocusPolicy(Qt::ClickFocus);

    QString pattern("[9-0]{3}");
    QRegExp regExp(pattern);
    Edit[Top_up]->setValidator(new QRegExpValidator(regExp, this));

    for(int i = 0; i < UHF_BUTTON_COUNT; i++)
    {
        Uhf_PushButton[i] = new QPushButton();//初始化UHF区域按钮
        Uhf_Layout->addWidget(Uhf_PushButton[i],LABEL_COUNT,i+1,1,1); //按钮添加到UHF布局
        Uhf_PushButton[i]->setText(Uhf_Button_Name[i]);//设置按钮文本
    }

    GroupBox[UHF]->setLayout(Uhf_Layout);//UHF区域设置布局
    GroupBox[UHF]->setTitle(GroupBox_Name[UHF]);//UHF区域设置标题
}

bool Widget::Show_Table()
{    
    Uhf_Table->setHorizontalHeaderLabels(QStringList()<<"卡号"<<"车牌号"<<"进入时间"<<"离开时间"<<"计费"<<"余额");
    mutex.lock();//上锁
    QSqlQuery query = sqlite->select("record_900M");//获取查询record表的结果
    if(!query.next())
    {        
        Uhf_Table->setRowCount(0);//表格设置行数
        mutex.unlock();
        return false;
    }

    /*计算record表中数据行数*/
    query.last();//跳转到最后一条数据
    int nRow = query.at() + 1;//取所在行数
    Uhf_Table->setRowCount(nRow);//表格设置行数
    int row = 0;
    query.first();//返回第一条数据
    do
    {
        for (int col = 0; col<7; col++)//按字段添加数据
        {
            //表格中添加数据库中的数据
            Uhf_Table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;//行数增加
    }while(query.next());
    mutex.unlock();//解锁
    return true;
}

void Widget::Clear_Table_Data()//清空表中数据
{
    if(!mutex.tryLock(1000))//1秒内未能获得锁返回
    {
        return;
    }
    sqlite->del("record_900M"); //删除record表中全部数据
    mutex.unlock();//解锁
    Uhf_Table->clear();//清空tablewidget
    Show_Table();
}

void Widget::Delete_Table_Data()//删除表中数据
{
    QList<QTableWidgetItem*>items=Uhf_Table->selectedItems();//获取选中行
    if(items.isEmpty())//选中的为空则返回
        return;
    QString id = items.at(0)->text(); //第一列 卡ID
    QString plate_number = items.at(1)->text();//第二列 车牌号
    QString intime = items.at(2)->text();//第三列 进入时间
    QString outtime = items.at(3)->text();//第四列 离开时间
    if(!mutex.tryLock(1000))//1秒内未能获得锁返回
    {
        return;
    }
    char where[256];
    sprintf(where, "cardId = '%s' and plate_number = '%s' and inTime = '%s' and outTime = '%s'", id.toUtf8().data(), plate_number.toUtf8().data(), intime.toUtf8().data(), outtime.toUtf8().data());
    sqlite->del("record_900M",where);//删除数据库中符合条件的数据。
    mutex.unlock();//解锁
    Show_Table();//更新tablewidget显示
}

void Widget::In_Click()
{
    Distance_Label->setEnabled(false);
    unit->setEnabled(false);
    Distance->setEnabled(false);
}
void Widget::Out_Click()
{
    Distance_Label->setEnabled(true);
    unit->setEnabled(true);
    Distance->setEnabled(true);
}

void Widget::Uhf_Regist_Button_Click()
{
    regist_widget = new Regist_Widget();
    regist_widget->Set_CardID(Edit[ID]->text());
    regist_widget->show();
}

void Widget::Uhf_TOP_UP_Button_Click()
{
    /*文本为空*/
    if(Edit[Plate_number]->text().isEmpty())
    {
        QMessageBox::warning(NULL, "warning", "卡号未注册！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    if(Edit[Top_up]->text().isEmpty())
    {
        QMessageBox::warning(NULL, "warning", "请输入充值金额！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    if(!mutex.tryLock(1000))//1秒内未能获得锁返回
    {
        return;
    }
    /*修改user表中的数据*/
    float balance = Edit[Balance]->text().toFloat()+Edit[Top_up]->text().toFloat();
    bool ret = sqlite->update_user(Edit[ID]->text().toUtf8().data(), Edit[Plate_number]->text().toUtf8().data(), balance);
    if(!ret)
    {
        QMessageBox::warning(NULL, "warning", "充值错误", QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(NULL, "warning", "充值成功", QMessageBox::Yes, QMessageBox::Yes);
        Edit[Balance]->setText(QString::number(balance));
        Edit[Top_up]->clear();
    }
    mutex.unlock();//解锁
}

void Widget::Uhf_Delete_Button_Click()
{
    if(!mutex.tryLock(1000))//1秒内未能获得锁返回
    {
        return;
    }
    char where[256];//删除条件
    sprintf(where,"cardID = '%s'",Edit[ID]->text().toUtf8().data());
    bool ret = sqlite->del("user_900M",where); // 删除cardID等于ID文本框内容的数据
    if(!ret)
    {
        QMessageBox::warning(NULL, "warning", "删除失败", QMessageBox::Yes, QMessageBox::Yes);
        mutex.unlock();
        return;
    }
    QMessageBox::warning(NULL, "warning", "删除成功", QMessageBox::Yes, QMessageBox::Yes);
    /*清空文本框*/
    for(int i = 0; i < EDIT_COUNT; i++)
    {
        Edit[i]->setText("");
    }
    mutex.unlock();
}
void Widget::Uhf_Connect_Button_Click()
{
    uhf->nRunFlag = true;
    uhf->UART_Connect(ComboBox[Serial]->currentText(),ComboBox[Baud]->currentText().toInt());
    uhf->start();//启动线程
    uhf->UHF_INIT();
    uhf->Read_CardID();//读卡
    Connect_PushButton[Disconnect]->setEnabled(true);
    Connect_PushButton[Connect]->setDisabled(true);
    GroupBox[UHF]->setEnabled(true);
    GroupBox[TableView]->setEnabled(true);
    Show_Table();//显示表格内容
}
void Widget::Uhf_Disconnect_Button_Click()
{
    uhf->nRunFlag = false;
    uhf->UART_Disconnect();//断开连接
    Connect_PushButton[Connect]->setEnabled(true);
    Connect_PushButton[Disconnect]->setDisabled(true);
    GroupBox[UHF]->setDisabled(true);
    GroupBox[TableView]->setDisabled(true);
}

void Widget::Get_Info(QString cardID)//刷卡响应
{
    float consumption,balance;//消费、余额
    QString id, plate_number, time;//卡号、车牌号、当前时间
    /*清空显示*/
    for(int i = 0; i < EDIT_COUNT; i++)
    {
        Edit[i]->clear();
    }

    mutex.lock();//上锁
    char where[256];
    sprintf(where, "cardID = '%s'", cardID.toUtf8().data());
    QSqlQuery query = sqlite->select("user_900M",where);//获取查询user表中卡的信息的结果
    if(!query.next())
    {
        mutex.unlock();
        if(CardID!=cardID)
        {
            QMessageBox::warning(NULL, "warning", "卡号未注册！", QMessageBox::Yes, QMessageBox::Yes);
            CardID = cardID;
        }
        Edit[0]->setText(cardID);
        return ;
    }

    /*取 卡号、车牌号、余额、当前时间*/
    id = query.value(0).toString();
    plate_number = query.value(1).toString();
    time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"); //获取时间
    balance = query.value(3).toFloat();

    /*当收费站为入口时*/
    if(In->isChecked())
    {
        if( balance <= 0 )
            QMessageBox::warning(NULL, "warning", "余额不足！", QMessageBox::Yes, QMessageBox::Yes);
        else
            In_station(id, plate_number, time, balance);//调用进站处理函数
    }

    /*当收费站为出口时*/
    if(Out->isChecked())
    {
        if(Distance->text().isEmpty())//没有输入距离时
        {
            QMessageBox::warning(NULL, "warning", "请输入距入口的公里数!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else
        {
            /*根据车的类型计算收费*/
            int type = 0;//车的类型
            QString types[] = {"一类车","二类车","三类车","四类车","五类车"};
            for(int i = 0; i < 5; i++)
            {
                if(query.value(2).toString() == types[i])
                {
                    type = i;
                    break;
                }
            }
            float distance = Distance->text().toFloat();//
            if( Distance->text().isEmpty() || distance < 1)
                distance = 1;
            consumption = distance * Charge_standard[type];//消费

            Out_station(id, plate_number, time, consumption, balance);//调用出站处理函数
        }
    }

    mutex.unlock();//解锁

    /*uhf区域显示相关信息*/
    for(int i = 0; i < EDIT_COUNT-1; i++)
    {
        Edit[i]->setText(query.value(i).toString());
    }
    //更新表
    Show_Table();
}

//调用出站处理函数
void Widget::Out_station(QString id, QString plate_number, QString time, float consumption, float balance)
{
    char where[256];
    sprintf(where, "cardID = '%s' and plate_number = '%s'", id.toUtf8().data(), plate_number.toUtf8().data());
    QSqlQuery query = sqlite->select("record_900M",where);//查找record表
    /*查找到第一条没有出站时间的记录*/
    while(query.next())
    {
        if(query.value(3).toString() == "(null)")
        {
            if( balance < consumption )//余额小于收费
                QMessageBox::warning(NULL, "warning", "余额不足！", QMessageBox::Yes, QMessageBox::Yes);
            else
            {
                //开始计时器，图片为开，计时结束，图片为关
                Timer->start(1000);
                Picture->setPixmap(QPixmap::fromImage(open_jpg));
                /*将新的记录和余额重新添加到两个表中*/
                balance -= consumption;
                sqlite->update_record(id.toUtf8().data(),plate_number.toUtf8().data(),query.value(2).toString().toUtf8().data(),time.toUtf8().data(),consumption,balance);
                sqlite->update_user(id.toUtf8().data(),plate_number.toUtf8().data(),balance);
            }
            break;
        }
    }
}

//调用进站处理函数
void Widget::In_station(QString id, QString plate_number, QString time, float balance)
{
    char where[256];
    int nRow;
    sprintf(where, "cardID = '%s' and plate_number = '%s'", id.toUtf8().data(), plate_number.toUtf8().data());
    QSqlQuery query = sqlite->select("record_900M",where);//查找record表
    if(!query.next())
    {
        /*没有找到符合的记录 就直接添加到record表*/
        sqlite->add_record(id.toUtf8().data(),plate_number.toUtf8().data(),time.toUtf8().data(),NULL,0,balance);
        Timer->start(1000);
        Picture->setPixmap(QPixmap::fromImage(open_jpg));
    }
    else
    {
        do
        {
            /*如果已经添加过进入时间了但是没有出站时间 就返回*/
            if(query.value(3).toString() == "(null)")
                return ;
        }while(query.next());

        query.last();//跳转到最后一条数据

        nRow = query.at() + 1;//取所在行数
        if(nRow >= 5) //最多存储5条记录 大于5条记录 则删除符合条件的第一条记录
        {
            query.first();
            memset(where,0,sizeof(where));
            sprintf(where, "cardID = '%s' and inTime = '%s'", id.toUtf8().data(), query.value(2).toString().toUtf8().data());
            sqlite->del("record_900M",where);
        }
        /*开启计时器， 更换图片为打开， 计时结果图片更换为关闭*/
        Timer->start(1000);
        Picture->setPixmap(QPixmap::fromImage(open_jpg));
        /*添加一条进入记录*/
        sqlite->add_record(id.toUtf8().data(),plate_number.toUtf8().data(),time.toUtf8().data(),(char*)0,0,balance);
    }
    return ;
}

void Widget::Time_Out()
{
    Picture->setPixmap(QPixmap::fromImage(close_jpg));
}

Widget::~Widget()
{

}
