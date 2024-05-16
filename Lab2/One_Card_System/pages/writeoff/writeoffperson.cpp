#include "writeoffperson.h"
#include "ui_writeoffperson.h"
#include <QMessageBox>
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 用户注销页面
***************************************/
WriteOffPerson::WriteOffPerson(QWidget *parent,SerialPortThread *serialPortThread) :
    QDialog(parent), ui(new Ui::WriteOffPerson)
{
    ui->setupUi(this);
    this->serialPortThread = serialPortThread;
    ui->lineEdit_CardId->setReadOnly(true);
}

WriteOffPerson::~WriteOffPerson()
{
    delete ui;
}
/**
 * @brief WriteOffPerson::on_btn_LogOff_clicked
 * 注销按钮点击事件
 */
void WriteOffPerson::on_btn_LogOff_clicked()
{
    QString cardId = ui->lineEdit_CardId->text();
    QString logOffMark = ui->textEdit_Mark->toPlainText();
    QString currentTime = CurrentDateTime();
    //注册表的model
    RegisterTableModel *registerTable = new RegisterTableModel(this);
    registerTable->bindTable();
    //注销表的model
    WriteOffTableModel *writeOffTable = new WriteOffTableModel(this);
    writeOffTable->bindTable();
    //人员信息表的model
    PersonTableModel *personTable = new PersonTableModel(this);
    personTable->bindTable();
    //记录表的model
    RecordTableModel *recordTable = new RecordTableModel(this);
    recordTable->bindTable();

    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);

    int row = registerTable->findRecord(cardId);
    if(row >= 0)
    {
        QSqlRecord record = registerTable->record(row);
        QString PersonId = record.value(1).toString();
        int recordId = personTable->findRecordById(PersonId);
        personTable->deleteRecords(recordId);
        registerTable->deleteRecord(cardId);
        recordTable->deleteByTagId(cardId);
        if(writeOffTable->findRecord(cardId) >= 0)
        {
            writeOffTable->updateRecords(cardId,currentTime,logOffMark);
        }else {
            writeOffTable->addRecords(cardId,currentTime,logOffMark);
        }
        message.setText(tr("注销成功！"));
        message.exec();
    }
    else
    {
        message.setText(tr("此卡尚未注册，您是否拿错卡了？"));
        message.exec();
        return ;
    }

}
/**
 * @brief WriteOffPerson::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void WriteOffPerson::on_btn_Return_clicked()
{
    this->close();
}
/**
 * @brief WriteOffPerson::on_btn_Inventory_clicked
 * 识别按钮点击事件
 */
void WriteOffPerson::on_btn_Inventory_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    m1356dll = new M1356Dll();
    uint16 frameLen;
    quint8 buffer[1];
    uint8 *p;
    memset(buffer, 0, 1);
    buffer[0] = RC632_14443_ALL;
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_REQUEST_A,buffer,1);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialPortThread->writeData((char *)(p + 2 ),frameLen);
    delete m1356dll;
}
/**
 * @brief RegistorWidget::on_tagIdReceived
 * @param tagId 标签ID
 * 接收到卡号时调用
 */
void WriteOffPerson::on_tagIdReceived(QString tagId){
      ui->lineEdit_CardId->setText(tagId);
 }
