#include "widget.h"
#include "inc/m1356dll.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //布局
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QHBoxLayout *TopLayout = new QHBoxLayout();

    //组合框
    ConnectGroupBox = new QGroupBox();
    ConnectGroupBox->setFixedWidth(350);


    uhf = new UHF_Thread();
    sql = new Sqlite();
    sql->Connect();
    Set_Title();//设置标题
    Set_Tab();//设置标签框

    Init_Connect_Operation_Box();//设置连接操作组合框中内容

    TopLayout->addStretch(0);
    TopLayout->addWidget(Title);
    TopLayout->addStretch(0);
    TopLayout->addWidget(ConnectGroupBox);

    MainLayout->addLayout(TopLayout);
    MainLayout->addWidget(Tab);

    this->setLayout(MainLayout);
    setSlot();//设置槽函数
}

void Widget::Set_Tab()
{
    borrow_return = new Borrow_Return();
    record = new Record();
    user_manage = new UserManage();
    books_manage = new BooksManage();
    Tab = new QTabWidget();
    Tab->setDisabled(true);
    Tab->addTab(borrow_return,"借/还书");//添加新选项卡
    Tab->addTab(record,"借书列表");//添加新选项卡
    Tab->addTab(user_manage,"用户管理");//添加新选项卡
    Tab->addTab(books_manage,"图书管理");//添加新选项卡
}

void Widget::Set_Title()
{
    Title = new QLabel("图书馆管理系统");
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

void Widget::Init_Connect_Operation_Box()
{
    char Connect_Button_Name[][50] = {"连接", "断开"};   //连接区域按钮名称
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
    ComboBox[Baud]->setCurrentIndex(6);

    for(int i = 0; i < CONNECT_BUTTON_COUNT; i++)
    {
        Connect_PushButton[i] = new QPushButton();//实例化连接区域按钮
        Connect_Operation_Layout->addWidget(Connect_PushButton[i]);//按钮添加到连接区域
        Connect_PushButton[i]->setText(Connect_Button_Name[i]);//设置按钮名称
    }
    Connect_PushButton[Connect]->setEnabled(true);
    Connect_PushButton[Disconnect]->setDisabled(true);

    ConnectGroupBox->setLayout(Connect_Operation_Layout); //连接布局添加连接区域
    ConnectGroupBox->setTitle("连接控制"); //连接区域设置标题
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

void Widget::setSlot()
{
    connect(Connect_PushButton[Connect], SIGNAL(clicked()), this, SLOT(Uhf_Connect_Button_Click()));  //连接按钮单击事件连接Uhf_Connect_Button_Click()函数
    connect(Connect_PushButton[Disconnect], SIGNAL(clicked()), this, SLOT(Uhf_Disconnect_Button_Click()));//断开按钮单击事件连接Uhf_Disconnect_Button_Click()函数
    connect(uhf, SIGNAL(receivedMsg(QByteArray)), this, SLOT(Get_Info(QByteArray)), Qt::BlockingQueuedConnection);//刷卡响应连接到槽函数Get_Info()
    connect(uhf, SIGNAL(cycle()), this, SLOT(Get_User_Info()), Qt::BlockingQueuedConnection);//刷卡响应连接到槽函数Get_User_Info()
    connect(Tab, SIGNAL(currentChanged(int)), this, SLOT(RefreshWidget(int)));//选项卡改变事件连接到槽函数RefreshWidget()
}

//刷卡响应的槽函数
void Widget::Get_Info(QByteArray Info)
{
    M1356Dll Dll;
    M1356_RspFrame_t data;//读卡数据结构体类型
    data = Dll.M1356_RspFrameConstructor(Info);//将QByteArray转结构体类型
    if(Dll.RC632_AnalysisFrame((uint8*)(Info.data()),RC632_CMD_ISO15693_INVENTORY16) != 0xff)//判断是否是读卡命令
    {
        if(Dll.RC632_UartCalcFCS(((uint8*)(Info.data()+4)),BUILD_UINT8(Info.at(3),Info.at(2))-1) == Info.at(Info.length() -1))//判断检验和
        {
            QString cardID = data.vdata.replace(" ","");//去掉空格
            switch(Tab->currentIndex())//获取当前选项卡索引值
            {
            case 0:
                borrow_return->SetInfo(cardID);//借还书界面
                break;
            case 1:
                record->SetCard(cardID);//记录界面设置卡号
                break;
            case 2:
                user_manage->SetCard(cardID);//调用用户管理的设置卡号函数
                break;
            case 3:
                books_manage->SetCard(cardID);//调用图书管理的设置卡号函数
                break;
            default:
                break;
            }
        }
    }

}

//获取卡号
void Widget::Get_User_Info()
{
    uhf->ReadCardID();//向串口发送读卡命令
}

//连接串口
void Widget::Uhf_Connect_Button_Click()
{
    uhf->nRunFlag = true;
    uhf->UART_Connect(ComboBox[Serial]->currentText(),ComboBox[Baud]->currentText().toInt());
    uhf->start();//启动线程
    uhf->InitUhf();//初始化UHF
    Tab->setEnabled(true);
    Connect_PushButton[Disconnect]->setEnabled(true);
    Connect_PushButton[Connect]->setDisabled(true);
}
//断开连接
void Widget::Uhf_Disconnect_Button_Click()
{
    uhf->nRunFlag = false;
    uhf->UART_Disconnect();//断开连接
    Tab->setDisabled(true);
    Connect_PushButton[Connect]->setEnabled(true);
    Connect_PushButton[Disconnect]->setDisabled(true);
}

//选项卡切换槽函数
void Widget::RefreshWidget(int index)
{
    //切换时清空页面内容
    switch(index)
    {
    case 0:
        borrow_return->Clear();
        break;
    case 1:
        record->Clear();
        break;
    case 2:
        user_manage->Clear();
        break;
    case 3:
        books_manage->Clear();
        break;
    }
}

Widget::~Widget()
{

}
