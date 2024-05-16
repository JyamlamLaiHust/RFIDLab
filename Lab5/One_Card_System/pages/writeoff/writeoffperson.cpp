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
//    ui->lineEdit_CardId->setReadOnly(true);
//    ui->lineEdit_RoomId->text();
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
    QString roomId = ui->lineEdit_RoomId->text();
    QString logOffMark = ui->textEdit_Mark->toPlainText();
    QString currentTime = CurrentDateTime();

    //卡表的model
    CardTableModel *cardTable = new CardTableModel(this);
    cardTable->bindTable();

//    RegisterTableModel *registerTable = new RegisterTableModel(this);
//    registerTable->bindTable();

    //注销表的model
    WriteOffTableModel *writeOffTable = new WriteOffTableModel(this);
    writeOffTable->bindTable();

    //人员信息表的model
    PersonTableModel *personTable = new PersonTableModel(this);
    personTable->bindTable();

    CustomerTableModel *customerTable = new CustomerTableModel(this);
    customerTable->bindTable();

    CustomerRoomTableModel *customerRoomTable = new CustomerRoomTableModel(this);
    customerRoomTable->bindTable();

//    //记录表的model
//    RecordTableModel *recordTable = new RecordTableModel(this);
//    recordTable->bindTable();

    RoomTableModel *roomTable = new RoomTableModel(this);
    roomTable->bindTable();

    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);

    int row = cardTable->findRecordByRoomId(roomId);

    if(row >= 0)
    {
        QSqlRecord record = cardTable->record(row);
        QString cardId = record.value(1).toString();
        QString roomId = record.value(2).toString();

        cardTable->deleteRecords(row);

//        QString PersonId = record.value(1).toString();
//        int recordId = personTable->findRecordById(PersonId);
//        personTable->deleteRecords(recordId);

        int customerId = customerTable->findRecordById(cardId);
        customerTable->deleteRecords(customerId);

        int customerRoomId = customerRoomTable->findRecordById(cardId);
        customerRoomTable->deleteRecords(customerRoomId);

        int roomRecordId = roomTable->findRecordById(roomId);
        roomTable->deleteRecords(roomRecordId);

//        recordTable->deleteByTagId(cardId);

        if(writeOffTable->findRecord(cardId) >= 0)
        {
            writeOffTable->updateRecords(cardId,currentTime,logOffMark);
        }else {
            writeOffTable->addRecords(cardId,currentTime,logOffMark);
        }
        message.setText(tr("已退房！"));
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
///**
// * @brief RegistorWidget::on_tagIdReceived
// * @param tagId 标签ID
// * 接收到卡号时调用
// */
//void WriteOffPerson::on_tagIdReceived(QString tagId){
//      ui->lineEdit_CardId->setText(tagId);
// }
