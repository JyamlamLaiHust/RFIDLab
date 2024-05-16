#include "tableinfopages.h"
#include "ui_tableinfopages.h"
#include "QMessageBox"
#include <QRegExp>
#include <QRegExpValidator>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 表的查询页面,包含注册表,消费记录表等
***************************************/
TableInfoPages::TableInfoPages(QWidget *parent,SerialPortThread *serial) :
    QWidget(parent),
    ui(new Ui::TableInfoPages)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->stretchLastSection();
    ui->dtEditStart->setDateTime(QDateTime::currentDateTime());
    ui->dtEditEnd->setDateTime(QDateTime::currentDateTime());
    this->serial = serial;
    m1356dll = new M1356Dll();
    QRegExp rx("^[1-9A-Fa-f]{0,16}");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit->setValidator(validator);
}

TableInfoPages::~TableInfoPages()
{
    delete m1356dll;
    delete ui;
}
/**
 * @brief TableInfoPages::on_btn_Query_clicked
 * 查询按钮点击事件
 */
void TableInfoPages::on_btn_Query_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    switch (index) {

    case 0: //根据时间进行筛选查询
    {
        QString startTimeStr = ui->dtEditStart->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        QString endTimeStr = ui->dtEditEnd->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        QString str = "时间 Between '" + startTimeStr + "' and '" + endTimeStr + "'";
        currentModel->setFilter(str);
        // 输出筛选信息
        qDebug() << "Applying time filter:" << str;
        qDebug() << "Filtered model row count:" << currentModel->rowCount();
        updateTableView(currentModel);
    }
        break;
    case 1: //根据卡号进行筛选查询
    {
        QString cardId = ui->lineEdit->text();
        QString str = tr("卡号 = '%1'").arg(cardId);
        currentModel->setFilter(str);
        updateTableView(currentModel);
        qDebug() << cardId;
    }
        break;
    case 2://根据姓名进行筛选查询
    {
        QString customerName = ui->lineEdit_2->text();
        QString str =  tr("姓名 = '%1'").arg(customerName);
        currentModel->setFilter(str);
        updateTableView(currentModel);
        qDebug() << customerName;
    }
        break;
    default:
        break;
    }
}
/**
 * @brief TableInfoPages::currentAction
 * @param action 当前的Action
 * 菜单点击事件槽函数
 */
void TableInfoPages::currentAction(QAction *action)
{
    if(action->text() == tr("退房记录"))
    {
        WriteOffTableModel *writeOffTableModel = new WriteOffTableModel(this);
        writeOffTableModel->bindTable();
        updateTableView(writeOffTableModel);
        ui->comboBox->clear();
        ui->comboBox->addItem("时间");
        ui->comboBox->addItem("卡号");
//        updateTableView(writeOffTableModel);
    }
    else if(action->text() == tr("入住记录"))
    {
//        RegisterTableModel *registerTableModel = new RegisterTableModel(this);
//        registerTableModel->bindTable();
        CardTableModel *cardTableModel = new CardTableModel(this);
        cardTableModel->bindTable();
        updateTableView(cardTableModel);
        ui->comboBox->clear();
        ui->comboBox->addItem("时间");
        ui->comboBox->addItem("卡号");
//        updateTableView(cardTableModel);
    }

    else if(action->text() == tr("刷卡记录"))
    {
//        RecordTableModel *recordTableModel = new RecordTableModel(this);
//        recordTableModel->bindTable();
        CustomerRoomTableModel *customerRoomTableModel = new CustomerRoomTableModel(this);
        customerRoomTableModel->bindTable();
        updateTableView(customerRoomTableModel);
        ui->comboBox->clear();
        ui->comboBox->addItem("卡号");  
    }
    else if(action->text() == tr("客人信息"))
    {
//        PersonTableModel *personTableModel = new PersonTableModel(this);
//        personTableModel->bindTable();
//        updateTableView(personTableModel);
        CustomerTableModel *customerTableModel = new CustomerTableModel(this);
        customerTableModel->bindTable();
        updateTableView(customerTableModel);
        ui->comboBox->clear();
        ui->comboBox->addItem("卡号");
        ui->comboBox->addItem("姓名");        
    }
}
/**
 * @brief TableInfoPages::updateTableView
 * @param model 数据表的model
 * 更新TableView界面
 */
void TableInfoPages::updateTableView(QSqlTableModel *model)
{
    currentModel = model;
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
/**
 * @brief TableInfoPages::on_comboBox_currentIndexChanged
 * @param text 当前的显示文本
 * 下拉框文本发生改变时调用
 */
void TableInfoPages::on_comboBox_currentIndexChanged(const QString &text)
{
    if(text == tr("时间"))
        ui->stackedWidget->setCurrentIndex(0);
    else if(text == tr("卡号"))
        ui->stackedWidget->setCurrentIndex(1);
    else
        ui->stackedWidget->setCurrentIndex(2);
}
/**
 * @brief TableInfoPages::on_tagIdReceived
 * @param tagId 卡号
 * 读取到卡号槽函数，显示卡号
 */
void TableInfoPages::on_tagIdReceived(QString tagId){
      ui->lineEdit->setText(tagId);
 }
/**
 * @brief TableInfoPages::on_btn_Enventory_clicked
 * 识别按钮点击事件
 */
void TableInfoPages::on_btn_Enventory_clicked()
{
    if(!serial->serialPortIsOpen())
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
    serial->writeData((char *)(p + 2 ),frameLen);
}
