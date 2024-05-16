#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools/tools.h"
#include <QMessageBox>
#include <QHBoxLayout>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 应用程序主页面窗口,其他各个页面都通过此页面链接过去
***************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->IsLogin = false;
    serialPortThread = new SerialPortThread(this);
    serialPort = new QSerialPort(this);
    m1356dll = new M1356Dll();
    settingsDialog = new SettingsDialog(this);

    ui->action_Disconnect->setEnabled(false);
    this->setWindowTitle(CURRENT_VERSION);
    ui->stackedWidget->setCurrentIndex(0);

    this->handConnect();
    this->addWidgets();
}
/**
 * @brief MainWindow::~MainWindow
 * 析构函数,用于删除一些变量
 */
MainWindow::~MainWindow()
{
    delete m1356dll;
    delete settingsDialog;
    delete ui;
}
/**
 * @brief MainWindow::addWidgets
 * 添加子页面
 */
void MainWindow::addWidgets()
{
    MainPage *welcom = new MainPage(this);
    ui->stackedWidget->addWidget(welcom);//0
    RegistorWidget *registWidget = new RegistorWidget(this,serialPortThread);
    connect(this,SIGNAL(sendCardId(QString)),registWidget,SLOT(on_tagIdReceived(QString)));
    ui->stackedWidget->addWidget(registWidget);//1
    TableInfoPages *tableInfo = new TableInfoPages(this,serialPortThread);
    connect(this,SIGNAL(sendCardId(QString)),tableInfo,SLOT(on_tagIdReceived(QString)));
    connect(this,SIGNAL(sendAction(QAction*)),tableInfo,SLOT(currentAction(QAction*)));
    ui->stackedWidget->addWidget(tableInfo);//2
    ConsumePage *consumePage = new ConsumePage(this,serialPortThread);
    connect(this,SIGNAL(sendCardId(QString)),consumePage,SLOT(on_cardIdReceived(QString)));
    ui->stackedWidget->addWidget(consumePage);//3
}
/**
 * @brief MainWindow::handConnect
 * 连接槽函数
 */
void MainWindow::handConnect()
{
    connect(settingsDialog,SIGNAL(applySettings()),this,SLOT(updateConnect()));
    connect(ui->action_about,SIGNAL(triggered(bool)),this,SLOT(About()));
    connect(ui->action_changepwd,SIGNAL(triggered(bool)),this,SLOT(ChangePasswd()));
    connect(ui->action_export,SIGNAL(triggered(bool)),this,SLOT(ExportTable()));
    connect(ui->action_login,SIGNAL(triggered(bool)),this,SLOT(Login()));
    connect(ui->action_connect,SIGNAL(triggered(bool)),this,SLOT(Connect()));
    connect(ui->action_Disconnect,SIGNAL(triggered(bool)),this,SLOT(Disconnect()));
    connect(ui->action_persontable,SIGNAL(triggered(bool)),this,SLOT(ViewTables()));
    connect(ui->action_recordtable,SIGNAL(triggered(bool)),this,SLOT(ViewTables()));
    connect(ui->action_register,SIGNAL(triggered(bool)),this,SLOT(Register()));
    connect(ui->action_registtable,SIGNAL(triggered(bool)),this,SLOT(ViewTables()));
    connect(ui->action_writeoff,SIGNAL(triggered(bool)),this,SLOT(WriteOff()));
    connect(ui->action_writeofftable,SIGNAL(triggered(bool)),this,SLOT(ViewTables()));
    connect(ui->action_consume,SIGNAL(triggered(bool)),this,SLOT(ViewConsume()));
    connect(ui->action_mainPage,SIGNAL(triggered(bool)),this,SLOT(viewMainPage()));
    connect(ui->actionquit,SIGNAL(triggered(bool)),this,SLOT(ExitApplication()));
    connect(ui->action_recharge,SIGNAL(triggered(bool)),this,SLOT(Recharge()));
    connect(ui->action_recharges,SIGNAL(triggered(bool)),this,SLOT(ViewTables()));
    connect(serialPortThread,SIGNAL(sendMsg(char*,int)),this,SLOT(onSendMessage(char*,int)));
    connect(serialPortThread,SIGNAL(wirteMsgError(QString)),this,SLOT(onOperationError(QString)));
    connect(serialPortThread,SIGNAL(receivedMsg(QByteArray)),this,SLOT(on_serialMsgreceived(QByteArray)));
}
//窗口关闭响应事件
void MainWindow::closeEvent(QCloseEvent  *event)
{
    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);
    message.setText(tr("您确定要退出吗？"));
    if (message.exec()==QMessageBox::Yes)
    {
        serialPortThread->stopThread();
        DB_Close();
    }
    else
    {
        event->ignore();
    }
}
/**
 * @brief MainWindow::CheckLogin
 * @return 如果已经登陆返回ture,否则false
 * 监测是否登陆
 */
bool MainWindow::CheckLogin()
{
    if(!IsLogin)
        QMessageBox::warning(this,tr("提示"),tr("您尚未登录，无权操作，请先登录！"),QMessageBox::Yes);
    return IsLogin;
}

/**
 * @brief MainWindow::About
 * 关于按钮点击事件
 */
void MainWindow::About()
{
    QString text = tr("软件版本:%1\r\n作者:%2\r\n描述:%3")
            .arg(CURRENT_VERSION)
            .arg(tr("jianghj@up-tech.com"))
            .arg(tr("博创科技为RFID高级教学平台14443A协议开发的应用案例"));
    QMessageBox::information(this,tr("帮助"),text,QMessageBox::Yes);
}
/**
 * @brief MainWindow::ChangePasswd
 * 修改密码按钮点击事件
 */
void MainWindow::ChangePasswd()
{
    if(!CheckLogin())
        return;
    ChangePassword *chagepwd = new ChangePassword(this);
    chagepwd->setWindowTitle("修改管理员密码");
    chagepwd->exec();
    delete chagepwd;
}
/**
 * @brief MainWindow::ExportTable
 * 数据导出按钮点击事件
 */
void MainWindow::ExportTable()
{
    if(!CheckLogin())
        return;
    ExportDatas *exportDatas = new ExportDatas(this);
    exportDatas->setWindowTitle("Choose table to export as CSV text");
    exportDatas->exec();
    delete exportDatas;
}
/**
 * @brief MainWindow::Login
 *登陆按钮点击事件
 */
void MainWindow::Login()
{
    LoginPage *loginpage = new LoginPage(this,&adminName);
    loginpage->setWindowTitle("管理员登录");
    loginpage->exec();
    if(this->adminName.count() >= 4)
    {
        ui->statusBar->showMessage(tr("登录成功,用户名：%1").arg(adminName));
        this->IsLogin = true;
    }
    else
    {
        ui->statusBar->showMessage(tr("登录失败"));
        this->IsLogin = false;
    }
    delete loginpage;
}
/**
 * @brief MainWindow::ViewConsume
 * 显示消费场景页面
 */
void MainWindow::ViewConsume()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->statusBar->showMessage("消费场景模拟");
}
/**
 * @brief MainWindow::viewMainPage
 * 显示welcome页面
 */
void MainWindow::viewMainPage()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusBar->showMessage("返回到主页");
}
/**
 * @brief MainWindow::Recharge
 * 充值
 */
void MainWindow::Recharge()
{
    if(!CheckLogin())
        return;
    RechargeDialog *recharge = new RechargeDialog(this,serialPortThread);
    connect(this,SIGNAL(sendCardId(QString)),recharge,SLOT(on_cardIdReceived(QString)));
    recharge->setWindowTitle(tr("M1卡充值"));
    recharge->exec();
    this->disconnect(recharge);
    delete recharge;
}
/**
 * @brief MainWindow::ViewTables
 * 查询记录响应槽
 */
void MainWindow::ViewTables()
{
    QAction *action = dynamic_cast<QAction*>(QObject::sender());
    emit sendAction(action);
    ui->stackedWidget->setCurrentIndex(2);
    ui->statusBar->showMessage(action->text()+tr("查询"));
    ui->statusBar->showMessage("查询各个环节的信息");
}
/**
 * @brief MainWindow::Register
 * 注册按钮点击事件
 */
void MainWindow::Register()
{
    if(!CheckLogin())
        return;
    ui->stackedWidget->setCurrentIndex(1);
    ui->statusBar->showMessage("用户注册");
}
/**
 * @brief MainWindow::WriteOff
 * 注销用户
 */
void MainWindow::WriteOff()
{
    if(!CheckLogin())
        return;
    WriteOffPerson *writeOffPerson = new WriteOffPerson(this,serialPortThread);
    connect(this,SIGNAL(sendCardId(QString)),writeOffPerson,SLOT(on_tagIdReceived(QString)));
    writeOffPerson->setWindowTitle(tr("用户注销"));
    writeOffPerson->exec();
    delete writeOffPerson;
}
/**
 * @brief MainWindow::Connect
 * 连接菜单点击事件
 */
void MainWindow::Connect()
{
    settingsDialog->setWindowTitle("读卡器连接配置");
    settingsDialog->exec();
}
/**
 * @brief MainWindow::updateConnect
 * 更新串口参数
 */
void MainWindow::updateConnect()
{
    serialPort->setPortName(settingsDialog->settings().name);
    serialPort->setBaudRate(settingsDialog->settings().baudRate);
    serialPort->setDataBits(settingsDialog->settings().dataBits);
    serialPort->setParity(settingsDialog->settings().parity);
    serialPort->setStopBits(settingsDialog->settings().stopBits);
    serialPort->setFlowControl(settingsDialog->settings().flowControl);
    if(serialPort->isOpen())
    {
        serialPort->close();
    }
    if(serialPort->open(QIODevice::ReadWrite))
    {
        ui->action_connect->setEnabled(false);
        ui->action_Disconnect->setEnabled(true);
        serialPortThread->setSerialPort(serialPort);
        serialPortThread->setRetryTimes(RETRY_20);
        serialPortThread->start();
        uint16 frameLen;
        uint8 data[1];
        uint8 *p;
        data[0] = RC632_WORK_MODEL_1443A;
        p = m1356dll->RC632_SendCmdReq(RC632_CMD_CONFIG_ISOTYPE,data,1);
        frameLen = BUILD_UINT16(p[0], p[1]);
        serialPortThread->writeData((char *)(p + 2 ),frameLen);
        ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6 success").arg(
                                       settingsDialog->settings().name).arg(
                                       settingsDialog->settings().baudRate).arg(
                                       settingsDialog->settings().dataBits).arg(
                                       settingsDialog->settings().parity).arg(
                                       settingsDialog->settings().stopBits).arg(
                                       settingsDialog->settings().flowControl));
    }else{
        QMessageBox::critical(this, tr("Error"), serialPort->errorString());
        ui->statusBar->showMessage(tr("Open error"));
    }
}
/**
 * @brief MainWindow::Disconnect
 * 与读卡器断开连接，关闭串口，停止读写线程
 */
void MainWindow::Disconnect()
{
    if(serialPort->isOpen())
    {
        serialPort->close();
        ui->action_connect->setEnabled(true);
        ui->action_Disconnect->setEnabled(false);
        ui->statusBar->showMessage(tr("Close Success"));
    }
}
/**
 * @brief MainWindow::ExitApplication
 * 退出按钮点击事件
 */
void MainWindow::ExitApplication()
{
    this->close();
}
/**
 * @brief MainWindow::onOperationError
 * @param msg 发送的命令
 * 当串口写入数据无响应时调用该方法
 */
void MainWindow::onOperationError(QString msg)
{
     QMessageBox::warning(this,tr("温馨提示"),msg,QMessageBox::Yes);
}
//显示发送消息
void MainWindow::onSendMessage(char *data, int frameLen)
{
    Q_UNUSED(data);
    Q_UNUSED(frameLen);
    //这里没用到,这里就是提供一个接口,方便您在学习后使用
}
/**
 * @brief MainWindow::on_serialMsgreceived
 * @param bytes 接收到的数据字节数组
 * 串口接收消息后的处理槽函数
 */
void MainWindow::on_serialMsgreceived(QByteArray bytes){
        M1356_RspFrame_t frame = m1356dll->M1356_RspFrameConstructor(bytes);
         if(frame.status.left(2) == "00")
         {
            if(frame.cmd.remove(" ") == "0102")//寻卡
            {
                uint16 frameLen;
                quint8 buffer[1];
                uint8 *p;
                memset(buffer, 0, 1);
                buffer[0] = 0x04;
                p = m1356dll->RC632_SendCmdReq(RC632_CMD_ANTICOLL, buffer, 1);
                frameLen = BUILD_UINT16(p[0], p[1]);
                serialPortThread->writeData((char *)(p + 2 ),frameLen);
            }
            else if(frame.cmd.remove(" ") == "0202")//寻卡结果
            {
                uint16 frameLen;
                quint8 buffer[4];
                uint8 *p;
                memset(buffer, 0, 4);
                QSTRING_TO_HEX(frame.vdata.remove(" "),buffer,4); // 卡号
                p = m1356dll->RC632_SendCmdReq(RC632_CMD_SELECT,buffer,4);
                frameLen = BUILD_UINT16(p[0], p[1]);
                serialPortThread->writeData((char *)(p + 2 ),frameLen);
                tagId = frame.vdata.remove(" ");
            }
            else if(frame.cmd.remove(" ") == "0302")
            {
                emit sendCardId(tagId);
            }
         }
        else
         {
             if(frame.cmd.remove(" ") == "0102")//寻卡
             {
                 QMessageBox::warning(this,tr("温馨提示"),tr("寻卡失败，请调整卡与读卡器的距离后再试！"),QMessageBox::Yes);
             }
             else if(frame.cmd.remove(" ") == "0202")//寻卡结果
             {
                 QMessageBox::warning(this,tr("温馨提示"),tr("A卡防冲撞失败，请调整卡与读卡器的距离后再试！"),QMessageBox::Yes);
             }
         }
}
