#include "registorwidget.h"
#include "ui_registorwidget.h"
#include "tools/tools.h"
#include "dialogcardconfig.h"
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 注册页面,用于新用户注册,该页面需要验证管理员是否登陆
***************************************/
RegistorWidget::RegistorWidget(QWidget *parent,SerialPortThread *serial) :
    QWidget(parent), ui(new Ui::RegistorWidget)
{
    ui->setupUi(this);
    this->serialThread = serial;
    m1356dll = new M1356Dll();
    uuid = new QUuid();
}

RegistorWidget::~RegistorWidget()
{
    delete m1356dll;
    delete uuid;
    delete ui;
}
/**
 * @brief RegistorWidget::on_tagIdReceived
 * @param tagId 标签ID(卡号)
 * 当读取到卡号时调用该方法
 */
void RegistorWidget::on_tagIdReceived(QString tagId){
      ui->lineEdit_CardId->setText(tagId);
 }
/**
 * @brief RegistorWidget::on_btn_Register_clicked
 * 注册按钮点击事件
 */
void RegistorWidget::on_btn_Register_clicked()
{
    QMessageBox message;
    QString userName = ui->lineEdit_Name->text();
    QString userType = ui->comboBox_UserType->currentText();
    QString personRemark = ui->textEdit_PersonMark->toPlainText();
    QString cardRemark = ui->textEdit_CardMark->toPlainText();
    QString cardId = ui->lineEdit_CardId->text();
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);
    //校验用户名的长度，采用utf8编码，汉语占用2个字符的宽度
    if(userName.toUtf8().length() < 4)
    {
        message.setText(tr("用户名长度有问题，长度应该大于等于两个汉字的长度。"));
        message.exec();
        return;
    }
    if(userType.toUtf8().length() < 4)
    {
        message.setText(tr("用户类型长度有问题，长度应该大于等于两个汉字的长度。"));
        message.exec();
        return;
    }
    if(cardId.count() < 4)
    {
        message.setText(tr("没发现卡号，请先识别到卡号了再点注册按钮。"));
        message.exec();
        return;
    }
    QString personId = uuid->createUuid().toString();
    QString time = CurrentDateTime();
    RegisterTableModel *registerTableModel =  new RegisterTableModel(this);
    registerTableModel->bindTable();
    PersonTableModel *personTableModel =  new PersonTableModel(this);
    personTableModel->bindTable();
    if(registerTableModel->findRecord(cardId) != -1)
    {
        message.setText(tr("此卡已经注册，请换张卡再试!"));
        message.exec();
        delete registerTableModel;
        return ;
    }

    if(!registerTableModel->addRecord(cardId,personId,time,cardRemark))
    {
        message.setText(tr("卡号信息保存失败，请重试!"));
        message.exec();
        delete registerTableModel;
        return ;
    }
    if(!personTableModel->insertRecords(personId,userName,userType,personRemark))
    {
        message.setText(tr("人员信息保存失败，请重试!"));
        message.exec();
        delete personTableModel;
        return ;
    }
    DialogCardConfig *dcc = new DialogCardConfig(this,serialThread);
    dcc->setWindowTitle(tr("初始化卡"));
    dcc->exec();
    delete dcc;
    delete registerTableModel;
    delete personTableModel;
}
/**
 * @brief RegistorWidget::on_btn_Reset_clicked
 * 重置按钮点击事件
 */
void RegistorWidget::on_btn_Reset_clicked()
{
    ui->lineEdit_Name->clear();
    ui->textEdit_PersonMark->clear();
    ui->textEdit_CardMark->clear();
    ui->lineEdit_CardId->clear();
}
/**
 * @brief RegistorWidget::on_btn_Inventory_clicked
 * 识别按钮点击事件
 */
void RegistorWidget::on_btn_Inventory_clicked()
{
    if(!serialThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    uint16 frameLen;
    quint8 buffer[1];
    uint8 *p;
    memset(buffer, 0, 1);
    buffer[0] = RC632_14443_ALL;
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_REQUEST_A,buffer,1);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialThread->writeData((char *)(p + 2 ),frameLen);
}
/**
 * @brief RegistorWidget::on_btn_Refresh_clicked
 * 刷新按钮点击事件
 */
void RegistorWidget::on_btn_Refresh_clicked()
{
    registerTableModel = new RegisterTableModel(this);
    registerTableModel->bindTable();
    ui->tableView->setModel(registerTableModel);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
/**
 * @brief RegistorWidget::on_comboBox_UserType_currentIndexChanged
 * @param arg1 当前文本值
 * 身份类型选择框文本值改变时调用
 */
void RegistorWidget::on_comboBox_UserType_currentIndexChanged(const QString &arg1)
{
    if(arg1 == tr("custom"))
    {
        ui->comboBox_UserType->setEditable(true);
        ui->comboBox_UserType->clearEditText();
    }
}
