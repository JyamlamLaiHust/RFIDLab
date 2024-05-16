#include "cardtablemodel.h"
#include "database/database_api.h"
#include <QDateTime>
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
CardTableModel::CardTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_CARD;
    header<<QObject::trUtf8("序号")<<QObject::trUtf8("卡号")<<
            QObject::trUtf8("房间号")<< QObject::trUtf8("时间")<<
            QObject::trUtf8("退房时间")<< QObject::trUtf8("状态标志");
}

/**
 * @brief CardTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void CardTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar PRIMARY KEY not null, ");
    str += header.at(1) + tr(" varchar, ");
    str += header.at(2) + tr(" varchar, ");
    str += header.at(3) + tr(" datetime, ");
    str += header.at(4) + tr(" datetime, ");
    str += header.at(5) + tr(" varchar)");
    qDebug()<<"Sql: " << str.toUtf8().data();
    bool ret = query.exec(str);
    if(ret == true){
        qDebug()<<tableName<<QObject::tr(" table create success");
    }
    else{
        qDebug()<<tableName<<QObject::tr(" table create failed");
    }
}
/**
 * @brief CardTableModel::restore
 * 绑定表名
 */
void CardTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief CardTableModel::findRecord
 * @param cardId 卡号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int CardTableModel::findRecordByCardId(const QString cardId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 1)).toString() == cardId)
            return row;
    }
    return -1;
}

int CardTableModel::findRecordByRoomId(const QString roomId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 2)).toString() == roomId)
            return row;
    }
    return -1;
}

///**
// * @brief CardTableModel::findRecord
// * @param customerName 姓名
// * @return QSqlRecord型记录集
// * 根据人员编号查找记录
// */
//QSqlRecord CardTableModel::findRecordByName(const QString customerName)
//{
//    setFilter(QObject::tr("姓名= '%1'").arg(customerName)); //根据姓名进行筛选
//    select();
//    return record();
//}
/**
 * @brief CardTableModel::insertRecords
 * @param number 序号
 * @param cardId 卡号
 * @param roomId 房间号
 * @param isUse 状态标志
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool CardTableModel::insertRecords(QString number, QString cardId, QString roomId, QDateTime checkInTime, QDateTime checkOutTime, bool isUse)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" , \"%3\" , \"%4\", \"%5\" , \"%6\" ) ")
           .arg(number).arg(cardId).arg(roomId).arg(checkInTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(checkOutTime.toString("yyyy-MM-dd hh:mm:ss")).arg(isUse);

    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief CardTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool CardTableModel::deleteRecords(int row)
{
    return removeRow(row);
}

QString CardTableModel::findRoomIdByTagId(const QString tagId)
{
    int row = findRecordByCardId(tagId);
    if (row != -1) {
        return data(index(row, 2)).toString();
    }
    return QString(); // 如果未找到对应的记录，返回空字符串
}

QDateTime CardTableModel::findCheckOutTimeByTagId(const QString tagId)
{
    int row = findRecordByCardId(tagId);
    if (row != -1) {
        QVariant timeData = data(index(row, 4)); // 获取时间数据，假设在第五列
        if (timeData.isValid()) {
            return timeData.toDateTime(); // 转换为 QDateTime 类型并返回
        }
    }
    return QDateTime(); // 如果未找到对应的记录，返回空字符串
}
