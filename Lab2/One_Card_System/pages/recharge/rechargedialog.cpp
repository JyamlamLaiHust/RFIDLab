#include "rechargedialog.h"
#include "ui_rechargedialog.h"
#include "database/dbmanager.h"
#include <QRegExp>
#include <QRegExpValidator>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 充值对话框,本对话框需要检测管理员是否登陆
***************************************/
RechargeDialog::RechargeDialog(QWidget *parent,SerialPortThread *serialPortThread) :
    QDialog(parent),
    ui(new Ui::RechargeDialog)
{
    ui->setupUi(this);
    currentOps = -1;
    last_value = 0.0;
    this->serialPortThread = serialPortThread;
    connect( this->serialPortThread,SIGNAL(receivedMsg(QByteArray)),this,SLOT(onDecodeFrame(QByteArray)));
    m1356dll = new M1356Dll();
    messageBox = new QMessageBox(this);
    messageBox->setStandardButtons(QMessageBox::Yes);
    messageBox->setWindowTitle(tr("温馨提示"));
    messageBox->setIcon(QMessageBox::Warning);
    connect(this,SIGNAL(calcOps(float)),this,SLOT(on_readValue(float)));
    QRegExp rx("^[1-9]{1,3}\\.[0-9]{1,2}");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_money->setValidator(validator);
    ui->lineEdit_money->installEventFilter(this);
}

RechargeDialog::~RechargeDialog()
{
    delete m1356dll;
    delete messageBox;
    delete ui;
}
/**
 * @brief RechargeDialog::on_btn_recharge_clicked
 * 充值按钮点击事件
 */
void RechargeDialog::on_btn_recharge_clicked()
{
    QString cardId = ui->lineEdit_cardId->text();
    if(cardId.count() <= 2)
    {
        ui->labelMessage->setText(tr("好像没看见卡号,请先读取卡号!"));
        return;
    }
    QString recharge = ui->lineEdit_money->text();
    float money = recharge.toFloat();
    QString currentValue = ui->label_currentValue->text().split(tr(" ")).at(0);
    if(money == 0.0)
    {
        ui->labelMessage->setText(tr("请填写充值金额!"));
        return;
    }
    ui->label_chargeValue->setText(recharge + tr(" 元"));
    last_value = money + currentValue.toFloat();
    if(last_value >= 999.99)
    {
        ui->labelMessage->setText(tr("如果充值,您卡内余额超限,为了您的财产安全,请先消费后再充"));
        return;
    }
    this->authentication();
    currentOps = 20;
}
/**
 * @brief RechargeDialog::eventFilter
 * @param obj 触发的对象
 * @param event 当前的事件
 * @return 此处只在RechargeDialog前面过滤,返回值含义未变
 * 事件过滤器
 */
bool RechargeDialog::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->lineEdit_money)
    {
        if(event->type() == QEvent::FocusOut)
        {
            QString value =  ((QLineEdit *)obj)->text();
            if(value.length() == 0)
                ((QLineEdit *)obj)->setText(tr("0.00"));
            else if(value.endsWith('.'))
                 ((QLineEdit *)obj)->setText(value + tr("00"));
            else if(!value.contains('.'))
                 ((QLineEdit *)obj)->setText(value + tr(".00"));
            else if(value.right(value.length() - value.indexOf('.')).length() == 2)
                 ((QLineEdit *)obj)->setText(value + tr("0"));
        }
    }
    return QDialog::eventFilter(obj,event);
}
/**
 * @brief RechargeDialog::on_btn_return_clicked
 * 返回按钮点击事件
 */
void RechargeDialog::on_btn_return_clicked()
{
    this->close();
}
/**
 * @brief RechargeDialog::authentication
 * 授权操作
 */
void RechargeDialog::authentication()
{
    uint16 frameLen;
    quint8 buffer[8];
    uint8 *p;
    buffer[0] = 0x60;   // A密钥
    buffer[1] = 0x09;   // 绝对块号
    for(int i = 2 ; i < 8 ; i ++)
        buffer[i] = 0xFF;
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_AUTHENTICATION,buffer,8);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialPortThread->writeData((char *)(p + 2 ),frameLen);
}
/**
 * @brief RechargeDialog::on_btn_clear_clicked
 * 清除按钮点击事件
 */
void RechargeDialog::on_btn_clear_clicked()
{
    ui->label_chargeValue->setText(tr("0.00 元"));
    ui->label_currentValue->setText(tr("0.00 元"));
    ui->label_lastValue->setText(tr("0.00 元"));
    ui->lineEdit_cardId->clear();
    ui->lineEdit_money->clear();
    ui->labelMessage->clear();
}
/**
 * @brief ConsumePage::on_readValue
 * @param value 卡内余额
 * 读取卡内余额后调用
 */
void RechargeDialog::on_readValue(float value)
{
    switch (currentOps) {
    case 21:
        currentOps = -1;
        ui->label_currentValue->setText(QString::number(value,'f',2) + tr(" 元"));
        break;
    case 20:
        {
            currentOps = -1;
            ui->label_lastValue->setText(QString::number(value,'f',2) + tr(" 元"));
            RechargeTableModel *rechargemodel = new RechargeTableModel(this);
            rechargemodel->bindTable();
            rechargemodel->addRecord(ui->lineEdit_cardId->text(),CurrentDateTime(),
                                     ui->label_currentValue->text().split(tr(" ")).at(0),
                                     ui->label_chargeValue->text().split(tr(" ")).at(0),
                                     ui->label_lastValue->text().split(tr(" ")).at(0),tr("校园充值中心"));
            ui->labelMessage->setText(tr("充值成功!"));
            ui->lineEdit_cardId->clear();
            ui->lineEdit_money->setText(tr("0.00"));
        }
        break;
    default:
        break;
    }
}
/**
 * @brief RechargeDialog::on_btn_inventory_clicked
 * 识别按钮点击事件
 */
void RechargeDialog::on_btn_inventory_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        messageBox->setText(tr("请先连接读卡器后再试！"));
        messageBox->exec();
        return;
    }
    uint16 frameLen;
    quint8 buffer[1];
    uint8 *p;
    memset(buffer, 0, 1);
    buffer[0] = RC632_14443_ALL;
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_REQUEST_A,buffer,1);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialPortThread->writeData((char *)(p + 2 ),frameLen);
    this->on_btn_clear_clicked();
}
/**
 * @brief RechargeDialog::on_cardIdReceived
 * @param tagId 卡号
 * 接收到卡号时调用
 */
void RechargeDialog::on_cardIdReceived(QString tagId)
{
    bool flag = false;
    RegisterTableModel *model = new RegisterTableModel(this);
    model->bindTable();
    model->findRecord(tagId);
    if(model->findRecord(tagId) == -1)
        flag = true;
    ui->lineEdit_cardId->setText(tagId);
    if(flag)
    {
        messageBox->setText("该卡未注册,不能使用,谢谢!");
        messageBox->exec();
        ui->btn_recharge->setEnabled(false);
    }
    else
    {
        ui->btn_recharge->setEnabled(true);
        currentOps = 21;
        this->authentication();
    }
}
/**
 * @brief RechargeDialog::onDecodeFrame
 * @param bytes 接收到的数据
 * 串口接收槽函数
 */
void RechargeDialog::onDecodeFrame(QByteArray bytes)
{
    M1356_RspFrame_t frame = m1356dll->M1356_RspFrameConstructor(bytes);
    if(frame.status == "00")
    {
        if(frame.cmd.remove(" ") == "0702")//授权成功
        {
            switch (currentOps) {
            case 20: //init
            {
                uint16 frameLen;
                quint8 buffer[5];
                uint8 *p;
                buffer[0] = 0x9;
                memset(buffer+1, 0, 5);
                float value = last_value;
                memcpy(buffer + 1,&value,4);
                p = m1356dll->RC632_SendCmdReq(RC632_CMD_M1INITVAL,buffer,5);
                frameLen = BUILD_UINT16(p[0], p[1]);
                serialPortThread->writeData((char *)(p + 2 ),frameLen);
            }
                break;
            case 21: //value
            {
                uint16 frameLen;
                quint8 buffer[1];
                uint8 *p;
                buffer[0] = 0x9;
                p = m1356dll->RC632_SendCmdReq(RC632_CMD_M1READVAL, (const uint8*)buffer, 1);
                frameLen = BUILD_UINT16(p[0], p[1]);
                serialPortThread->writeData((char *)(p + 2 ),frameLen);
            }
                break;
            default:
                break;
            }
        }
        else if(frame.cmd.remove(" ") == "0B02" && currentOps == 21)
        {
            Float2Bytes temp;
            QSTRING_TO_HEX(frame.vdata.remove(" "),(quint8 *)temp.value_b,4);
            QString modify_value = QString::number(temp.value_f,'f',2);
            emit calcOps(modify_value.toFloat());
        }
        else if(frame.cmd.remove(" ") == "0A02" && currentOps == 20)
        {
           emit calcOps(last_value);
        }
    }
    else {
        if(frame.cmd.remove(" ") == "0702")//授权成功
        {
            messageBox->setText(tr("授权失败,请将卡放到可识别区域!"));
            messageBox->exec();
            currentOps = -1;
        }
        else if(frame.cmd.remove(" ") == "0B02")
        {
            messageBox->setText(tr("读卡失败,请注意卡和读卡器之间的距离"));
            messageBox->exec();
            currentOps = -1;
        }
        else if(frame.cmd.remove(" ") == "0A02")
        {
            messageBox->setText(tr("写卡失败,请将卡放到可识别区域!"));
            messageBox->exec();
            currentOps = -1;
        }
    }
}
