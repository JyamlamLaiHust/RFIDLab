#include "consumepage.h"
#include "ui_consumepage.h"
#include "database/dbmanager.h"
#include <QDebug>
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 消费模拟页面,模拟学校的食堂,超市等消费场景
***************************************/
ConsumePage::ConsumePage(QWidget *parent, SerialPortThread *serialPortThread) :
    QWidget(parent),
    ui(new Ui::ConsumePage)
{
    ui->setupUi(this);
    last_value = 0.0;
    messageBox = new QMessageBox(this);
    messageBox->setStandardButtons(QMessageBox::Yes);
    messageBox->setWindowTitle(tr("温馨提示"));
    messageBox->setIcon(QMessageBox::Warning);
    this->initViews();
    this->serialPortThread = serialPortThread;
    timer = new QTimer(this);
    m1356dll = new M1356Dll();
    this->handleConnect();
    this->update();
    this->currentOps = -1;
}

ConsumePage::~ConsumePage()
{
    delete messageBox;
    delete ui;
}
/**
 * @brief ConsumePage::initViews
 * 初始化界面
 */
void ConsumePage::initViews()
{
    supermarketName << tr("方便面")<<tr("口香糖")<<tr("冰可乐");
//    supermarketAddr << "五教旁" << "男生7舍前面"<<"行知食堂对面"<<"体育馆旁"
//                    << "女生6舍后面"<< "图书馆旁" << "高尔夫球场旁";

//    foodName <<"兰州拉面"<<"土耳其烤肉饭"<<"麻辣烫"<<"2楼套餐"<<"酸辣粉"<<
//               "小火锅"<< "山西刀削面"<<"照烧鸡腿饭";
//    cafeteriaAddr << "美娜食堂1楼" << "学生食堂2楼" << "教师食堂" << "学生食堂1楼"
//                  << "美娜食堂2楼" << "学生食堂3楼" << "鑫源餐厅" << "行知食堂";

    goodsName << "跑步机" << "哑铃" << "杠铃" << "卧推机" << "有氧步台" << "健身自行车" << "拉力器";
    vendorAddr<<"难度1"<<"难度2"<<"难度3"<<"难度4"<<"难度5"<<"难度6"<<"难度7";

    castName<<"洗衣机"<<"烘干机"<<"洗鞋机";
    castAddr <<"10分钟"<<"20分钟"<<"30分钟"<<"40分钟";

    ui->comboBox_castType->clear();
    ui->comboBox_castType->addItems(castName);

    ui->comboBox_goodsName->clear();
    ui->comboBox_goodsName->addItems(goodsName);

//    ui->comboBox_foodName->clear();
//    ui->comboBox_foodName->addItems(foodName);


    ui->comboBox_supermarket->clear();
    ui->comboBox_supermarket->addItems(supermarketName);

    ui->label_Tips->installEventFilter(this);
    ui->lineEdit_customerName->setReadOnly(true);
    ui->lineEdit_roomId->setReadOnly(true);

    ui->lineEdit_telephoneNumber->setReadOnly(true);

    ui->lineEdit_ReadId1->setReadOnly(true);
    ui->lineEdit_ReadId2->setReadOnly(true);
    ui->lineEdit_ReadId3->setReadOnly(true);

    QRegExp rx("^[1-9]{1,3}\\.[0-9]{1,2}");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
//    ui->lineEdit_value->setValidator(validator);
//    ui->lineEdit_value->installEventFilter(this);
    ui->lineEdit_value1->setValidator(validator);
    ui->lineEdit_value1->installEventFilter(this);
    ui->lineEdit_value2->setValidator(validator);
    ui->lineEdit_value2->installEventFilter(this);
    ui->lineEdit_value3->setValidator(validator);
    ui->lineEdit_value3->installEventFilter(this);
    rx.setPattern(tr("^[1-9A-Fa-f]{0,16}"));
    validator = new QRegExpValidator(rx, this);
    ui->lineEdit_tagId->setValidator(validator);
    ui->lineEdit_tagId1->setValidator(validator);
    ui->lineEdit_tagId2->setValidator(validator);
    ui->lineEdit_tagId3->setValidator(validator);
}
/**
 * @brief ConsumePage::handleConnect
 * 处理信号与插槽的连接关系
 */
void ConsumePage::handleConnect()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(5000);
    connect(ui->btn_Enventory,SIGNAL(clicked(bool)),this,SLOT(readCardId(bool)));
    connect(ui->btn_Enventory1,SIGNAL(clicked(bool)),this,SLOT(readCardId(bool)));
    connect(ui->btn_Enventory2,SIGNAL(clicked(bool)),this,SLOT(readCardId(bool)));
    connect(ui->btn_Enventory3,SIGNAL(clicked(bool)),this,SLOT(readCardId(bool)));
    connect(serialPortThread,SIGNAL(receivedMsg(QByteArray)),this,SLOT(onDecodeFrame(QByteArray)));
    connect(this,SIGNAL(calcOps(float)),this,SLOT(on_readValue(float)));
}
/**
 * @brief ConsumePage::eventFilter
 * @param obj 触发的对象
 * @param event 当前的事件
 * @return 此处只在QWidget前面过滤,返回值含义未变
 * 事件过滤器
 */
bool ConsumePage::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->label_Tips)
    {
        if(event->type() == QEvent::MouseButtonDblClick)
        {
            ui->label_Tips->clear();
        }
    }
    else if(
            obj == ui->lineEdit_value1||
            obj == ui->lineEdit_value2||
            obj == ui->lineEdit_value3)
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
    return QWidget::eventFilter(obj,event);
}
/**
 * @brief ConsumePage::updateTime
 * 更新时间槽函数
 */
void ConsumePage::updateTime()
{
    QString currentTime = CurrentDateTime();
    ui->lineEdit_time1->setText(currentTime);
    ui->lineEdit_time2->setText(currentTime);
    ui->lineEdit_time3->setText(currentTime);
    ui->lineEdit_time4->setText(currentTime);
}
/**
 * @brief ConsumePage::readCardId
 * @param clicked 无意义
 * 识别按钮处理函数
 */
void ConsumePage::readCardId(bool clicked)
{
    Q_UNUSED(clicked);
    QPushButton *btn = dynamic_cast<QPushButton*>(QObject::sender());
    if(!btn) return;
    currentEnventoryButton = btn;
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
}
/**
 * @brief ConsumePage::on_cardIdReceived
 * @param tagId 卡号
 * 接收到卡号时调用
 */
void ConsumePage::on_cardIdReceived(QString tagId)
{
    bool flag = false; // 判断是否已经注册
    bool timeOut = false; // 判断是否已经超时

//    RegisterTableModel *model = new RegisterTableModel(this);
//    model->bindTable();

    CardTableModel *cardTableModel = new CardTableModel(this);
    cardTableModel->bindTable();

    cardTableModel->findRecordByCardId(tagId);

    CustomerTableModel *customerTableModel = new CustomerTableModel(this);
    customerTableModel->bindTable();

    QDateTime checkOutTime = cardTableModel->findCheckOutTimeByTagId(tagId);

    if(customerTableModel->findRecordById(tagId) == -1)
        flag = true;

    QDateTime currentDateTime = QDateTime::currentDateTime();
    if(currentDateTime > checkOutTime)
    {
        timeOut = true;
    }

    QString customerName = customerTableModel->findNameByTagId(tagId); // 使用之前编写的函数获取姓名
    QString inUse = customerTableModel->findInUseByTagId(tagId);
    QString telephoneNumber = customerTableModel->findTelephoneNumberByTagId(tagId);
    QString roomId = cardTableModel->findRoomIdByTagId(tagId);

    if(currentEnventoryButton == ui->btn_Enventory)
    {
        ui->lineEdit_tagId->setText(tagId);
        ui->lineEdit_customerName->setText(customerName);
        ui->lineEdit_telephoneNumber->setText(telephoneNumber);
        ui->lineEdit_roomId->setText(roomId);
//        ui->lineEdit_InUse->setText(inUse);

        if(flag)
        {
            messageBox->setText("该卡未注册,不能使用,谢谢!");
            messageBox->exec();
            ui->btn_OK->setEnabled(false);
        } else if(timeOut) {
            messageBox->setText("您好！您没有权限进入此房间，请到前台办理续费！");
            messageBox->exec();
            ui->btn_OK->setEnabled(false);
        }else{
            ui->btn_OK->setEnabled(true);
            CustomerRoomTableModel *customerRoomTable = new CustomerRoomTableModel(this);
            customerRoomTable->bindTable();

            customerRoomTable->insertRecords(tagId,  QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
    }
    else if(currentEnventoryButton == ui->btn_Enventory1)
    {
        ui->lineEdit_tagId1->setText(tagId);
        if(flag)
        {
            messageBox->setText("该卡未注册,不能使用,谢谢!");
            messageBox->exec();
            ui->btn_OK1->setEnabled(false);
        } else if(timeOut) {
            messageBox->setText("您好！您没有权限进入健身房，请到前台办理续费！");
            messageBox->exec();
            ui->btn_OK->setEnabled(false);
        }
        else
            ui->btn_OK1->setEnabled(true);
    }
    else if(currentEnventoryButton == ui->btn_Enventory2)
    {
        ui->lineEdit_tagId2->setText(tagId);
        if(flag)
        {
            messageBox->setText("该卡未注册,不能使用,谢谢!");
            messageBox->exec();
            ui->btn_OK2->setEnabled(false);
        }
        else
            ui->btn_OK2->setEnabled(true);
    }
    else if(currentEnventoryButton == ui->btn_Enventory3)
    {
        ui->lineEdit_tagId3->setText(tagId);
        if(flag)
        {
            messageBox->setText("该卡未注册,不能使用,谢谢!");
            messageBox->exec();
            ui->btn_OK3->setEnabled(false);
        } else if(timeOut) {
            messageBox->setText("您好！您没有权限进入洗衣服，请到前台办理续费！");
            messageBox->exec();
            ui->btn_OK->setEnabled(false);
        }
        else
            ui->btn_OK3->setEnabled(true);
    }
}
/**
 * @brief ConsumePage::onDecodeFrame
 * @param bytes 接收到的数据
 * 串口接收槽函数
 */
void ConsumePage::onDecodeFrame(QByteArray bytes)
{
    M1356_RspFrame_t frame = m1356dll->M1356_RspFrameConstructor(bytes);
    if(frame.status == "00")
    {
        if(frame.cmd.remove(" ") == "0702")//授权成功
        {
            switch (currentOps) {
            case 10: //init
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
            case 11: //value
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
        else if(frame.cmd.remove(" ") == "0B02" && currentOps == 11)
        {
            ReadValue temp;
            QSTRING_TO_HEX(frame.vdata.remove(" "),(quint8 *)temp.value_b,4);
            QString modify_value = QString::number(temp.value_f,'f',2);
            emit calcOps(modify_value.toFloat());
        }
        else if(frame.cmd.remove(" ") == "0A02" && currentOps == 10)
        {
//            ui->label_Tips->setText(ui->label_Tips->text() + tr("   状态: 完成,当前余额 %1 元").arg(last_value));
            ui->label_Tips->setText("开门成功！");
            currentOps = -1;
            RecordTableModel *model = new RecordTableModel(this);
            model->bindTable();
            QString write_value = QString::number(sendData.value,'f',2);
            model->addRecord(sendData.cardId,sendData.time,sendData.addr,
                             sendData.readerId,write_value,sendData.remark);
        }
    }
    else {
        if(frame.cmd.remove(" ") == "0702")//授权
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
/**
 * @brief ConsumePage::on_readValue
 * @param value 卡内余额
 * 读取卡内余额后调用
 */
void ConsumePage::on_readValue(float value, QString cardId)
{
//    ui->label_Tips->setText(tr("卡内余额: %1 元\t\t应付金额: %2 元").arg(value).arg(sendData.value));
    ui->label_Tips->setText("开门成功！");
//    if(sendData.value > value)
//    {
//        messageBox->setText(tr("对不起,卡内余额不足,请充值!"));
//        messageBox->exec();
//        return;
//    }
//    last_value = value - sendData.value;
//    this->authentication();
//    currentOps = 10 ;
}
/**
 * @brief ConsumePage::on_btn_OK_clicked
 * 食堂结账按钮点击事件
 */
void ConsumePage::on_btn_OK_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    fillSendData(ui->lineEdit_time1->text(),
                 ui->lineEdit_customerName->text(),ui->lineEdit_telephoneNumber->text(),
                 ui->lineEdit_tagId->text(),ui->remark->toPlainText());
    if(this->checkDataValid())
    {
        this->authentication();
        currentOps = 11;
    }
}
/**
 * @brief ConsumePage::on_btn_OK2_clicked
 * 超市消费结账按钮点击事件
 */
void ConsumePage::on_btn_OK2_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    fillSendData(ui->lineEdit_time3->text(),
                 ui->lineEdit_ReadId2->text(),ui->lineEdit_value2->text(),
                 ui->lineEdit_tagId2->text(),ui->remark2->toPlainText());
    if(this->checkDataValid())
    {
        this->authentication();
        currentOps = 11;
    }
}
/**
 * @brief ConsumePage::on_btn_OK1_clicked
 * 教学楼结账按钮点击事件
 */
void ConsumePage::on_btn_OK1_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    fillSendData(ui->lineEdit_time2->text(),/*ui->lineEdit_addr1->text(),*/
                 ui->lineEdit_ReadId1->text(),ui->lineEdit_value1->text(),
                 ui->lineEdit_tagId1->text(),ui->remark1->toPlainText());
    if(this->checkDataValid())
    {
        this->authentication();
        currentOps = 11;
    }
}
/**
 * @brief ConsumePage::on_btn_OK3_clicked
 * 其他结账按钮点击事件
 */
void ConsumePage::on_btn_OK3_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    fillSendData(ui->lineEdit_time4->text(),/*ui->lineEdit_addr3->text(),*/
                 ui->lineEdit_ReadId3->text(),ui->lineEdit_value3->text(),
                 ui->lineEdit_tagId3->text(),ui->remark3->toPlainText());
    if(this->checkDataValid())
    {
        this->authentication();
        currentOps = 11;
    }
}
/**
 * @brief ConsumePage::fillSendData
 * @param time 时间
 * @param addr 地址
 * @param readerId 读卡器ID
 * @param value 金额
 * @param cardId 卡号
 * @param remark 备注信息
 * 填充数据
 */
void ConsumePage::fillSendData(QString time,QString readerId,
                               QString value,QString cardId,QString remark)
{
    sendData.time = time;
//    sendData.addr = addr;
    sendData.readerId = readerId;
    sendData.value = value.toFloat();
    sendData.cardId = cardId;
    if(remark.length() == 0)
        remark = tr("商家没给您备注");
    sendData.remark = remark;
}

bool ConsumePage::checkDataValid()
{
    if(sendData.cardId.length() < 2 )
    {
        messageBox->setText(tr("对不起,卡号不对,请先读卡"));
        messageBox->exec();
        return false;
    }
    else if(sendData.value == 0.00)
    {
        messageBox->setText(tr("应付金额为0元,不需要付款"));
        messageBox->exec();
        return false;
    }
    else return true;
}
/**
 * @brief ConsumePage::authentication
 * 授权操作
 */
void ConsumePage::authentication()
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
 * @brief ConsumePage::on_comboBox_foodName_currentIndexChanged
 * @param index 当前文本的索引值
 * 食物名称复选框文本值改变时调用
 */
void ConsumePage::on_comboBox_foodName_currentIndexChanged(int index)
{
//    QString addr = cafeteriaAddr.at(index);
//    ui->lineEdit_InUse->setText(addr + foodName.at(index));
    ui->lineEdit_customerName->setText(tr("E9A39FE5") + QString::number(index,16));
}
/**
// * @brief ConsumePage::on_comboBox_supermarket_currentIndexChanged
// * @param index 当前文本的索引值
// * 超市名称发生改变时调用
// */
void ConsumePage::on_comboBox_supermarket_currentIndexChanged(int index)
{
//    QString addr = supermarketAddr.at(index);
//    ui->lineEdit_addr2->setText(addr + supermarketName.at(index));
    ui->lineEdit_ReadId2->setText(tr("E3") + QString::number(index,16));
}
/**
 * @brief ConsumePage::on_comboBox_goodsName_currentIndexChanged
 * @param index 当前商品名的索引值
 * 商品名称发生改变时调用
 */
void ConsumePage::on_comboBox_goodsName_currentIndexChanged(int index)
{
//    QString addr = vendorAddr.at(index);
//    ui->lineEdit_addr1->setText(addr + goodsName.at(index));
    ui->lineEdit_ReadId1->setText(tr("E69599E5") + QString::number(index,16));
}
/**
 * @brief ConsumePage::on_comboBox_castType_currentIndexChanged
 * @param index 当前消费名的索引值
 * 消费类别名发生改变时调用
 */
void ConsumePage::on_comboBox_castType_currentIndexChanged(int index)
{
//    QString addr = castAddr.at(index);
//    ui->lineEdit_addr3->setText(addr + castName.at(index));
    ui->lineEdit_ReadId3->setText(tr("E4BAA4E8") + QString::number(index,16));
}
