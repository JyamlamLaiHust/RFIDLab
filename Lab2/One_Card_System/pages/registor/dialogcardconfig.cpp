#include "dialogcardconfig.h"
#include "ui_dialogcardconfig.h"
#include <QRegExp>
#include <QValidator>
#include <QDebug>
#include <QMessageBox>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 注册之后卡的配置对话框,主要用于初始化卡的存储格式,初始化金额
***************************************/
DialogCardConfig::DialogCardConfig(QWidget *parent, SerialPortThread *serialPortThread) :
    QDialog(parent),
    ui(new Ui::DialogCardConfig)
{
    currentOps = -1 ;
    ui->setupUi(this);
    m1356dll = new M1356Dll();
    this->serialPortThread = serialPortThread;
    connect(serialPortThread,SIGNAL(receivedMsg(QByteArray)),this,SLOT(onDecodeFrame(QByteArray)));
    QRegExp rx("^[0-9a-fA-F]{17}");
    QValidator* validator = new QRegExpValidator(rx, this);
    ui->lineEdit_Pwd->setValidator(validator);
    ui->lineEdit_Pwd->setInputMask(tr("HH HH HH HH HH HH"));
    rx.setPattern("^[1-9]{1,3}\\.[0-9]{1,2}");
    validator = new QRegExpValidator(rx, this);
    ui->initValue->setValidator(validator);
    ui->initValue->installEventFilter(this);
    ui->radioButtonA->setChecked(true);
    ui->lineEdit_Pwd->setText(tr("FFFFFFFFFFFF"));
}

DialogCardConfig::~DialogCardConfig()
{
    this->disconnect(serialPortThread);
    delete ui;
}

/**
 * @brief DialogCardConfig::on_lineEdit_Pwd_cursorPositionChanged
 * @param arg1 原位置
 * @param arg2 新位置
 * 密码输入框光标位置发生改变时调用
 */
void DialogCardConfig::on_lineEdit_Pwd_cursorPositionChanged(int arg1, int arg2)
{
    if(arg1 > arg2)
        return;
    int len = ui->lineEdit_Pwd->text().length();
    int tem = 5 - (len - 5)/2;
    int cursorPositon = len - tem;
    if(arg2 > cursorPositon)
        ui->lineEdit_Pwd->setCursorPosition(cursorPositon);
}
/**
 * @brief DialogCardConfig::on_checkBox_clicked
 * @param checked 如果选中为true,否则为false
 * 显示密钥复选框点击事件
 */
void DialogCardConfig::on_checkBox_clicked(bool checked)
{
    if(checked)
        ui->lineEdit_Pwd->setEchoMode(QLineEdit::Password);
    else
        ui->lineEdit_Pwd->setEchoMode(QLineEdit::Normal);
}
/**
 * @brief DialogCardConfig::eventFilter
 * @param obj 产生事件的对象
 * @param event Qt事件
 * @return bool型值,表明此事件是否处理了
 * 事件过滤器
 */
bool DialogCardConfig::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->initValue)
    {
        if(event->type() == QEvent::FocusOut)
        {
            QString value = ui->initValue->text();
            if(value.length() == 0)
                ui->initValue->setText(tr("1.00"));
            else if(value.endsWith('.'))
                ui->initValue->setText(value + tr("00"));
            else if(!value.contains('.'))
                ui->initValue->setText(value + tr(".00"));
            else if(value.right(value.length() - value.indexOf('.')).length() == 2)
                ui->initValue->setText(value + tr("0"));
        }
    }
    return QDialog::eventFilter(obj,event);
}

/**
 * @brief DialogCardConfig::onDecodeFrame
 * @param frame 14443的响应帧
 * 串口接收槽函数
 */
void DialogCardConfig::onDecodeFrame(QByteArray bytes)
{
    M1356_RspFrame_t frame = m1356dll->M1356_RspFrameConstructor(bytes);
    qDebug() <<"data: " << frame.vdata << frame.cmd << frame.sof;
    if(frame.cmd.remove(" ") == "0702" && frame.status == "00")//授权成功
    {
        switch (currentOps) {
        case 0: //init
        {
            uint16 frameLen;
            quint8 buffer[5];
            uint8 *p;
            QString str = ui->initValue->text();
            buffer[0] = 0x9;//绝对块号,这样的最好定义成宏,方便修改
            memset(buffer+1, 0, 5);
            float test = str.toFloat();
            memcpy(buffer + 1,&test,4);
            p = m1356dll->RC632_SendCmdReq(RC632_CMD_M1INITVAL,buffer,5);
            frameLen = BUILD_UINT16(p[0], p[1]);
            serialPortThread->writeData((char *)(p + 2 ),frameLen);
            currentOps = -1;
        }
            break;
        case 1: //mem
        {
            uint16 frameLen;
            quint8 buffer[1];
            uint8 *p;
            buffer[0] = 0x9;
            p = m1356dll->RC632_SendCmdReq(RC632_CMD_M1READ,buffer,1);
            frameLen = BUILD_UINT16(p[0], p[1]);
            serialPortThread->writeData((char *)(p + 2 ),frameLen);
             currentOps = -1;
        }
            break;
        default:
            break;
        }
    }
    else if(frame.cmd.remove(" ") == "0802")
    {
        ui->lineEditMemData->setText(frame.vdata);
    }
}

/**
 * @brief DialogCardConfig::on_btn_Init_clicked
 * 初始化按钮点击事件
 */
void DialogCardConfig::on_btn_Init_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    if(ui->lineEdit_Pwd->text().length() != 17)
    {
        QMessageBox::warning(this, "Error", tr("请在密钥区输入6个字节密钥！"));
        return;
    }
    this->authentication();
    currentOps = 0 ;
}
/**
 * @brief DialogCardConfig::on_btn_MemData_clicked
 * 查看内存数据
 */
void DialogCardConfig::on_btn_MemData_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    if(ui->lineEdit_Pwd->text().length() != 17)
    {
        QMessageBox::warning(this, "Error", tr("请在密钥区输入6个字节密钥！"));
        return;
    }
    this->authentication();
    currentOps = 1;
}
/**
 * @brief DialogCardConfig::authentication
 * 授权
 */
void DialogCardConfig::authentication()
{
    uint16 frameLen;
    quint8 buffer[8];
    uint8 *p;
    if(ui->radioButtonA->isChecked())
        buffer[0] = 0x60;   // A密钥
    else
        buffer[0] = 0x61;  // B 密钥
    buffer[1] = 0x09;   // 绝对块号
    QString str = ui->lineEdit_Pwd->text().remove(" "); //六字节
    QSTRING_TO_HEX(str, (uint8*)(buffer+2),6);
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_AUTHENTICATION,buffer,8);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialPortThread->writeData((char *)(p + 2 ),frameLen);
}
/**
 * @brief DialogCardConfig::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void DialogCardConfig::on_btn_Return_clicked()
{
    this->close();
}
