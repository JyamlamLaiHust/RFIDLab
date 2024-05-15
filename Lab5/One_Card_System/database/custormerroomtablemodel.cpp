#include "custormerroomtablemodel.h"
#include "database/database_api.h"
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
CustomerRoomTableModel::CustomerRoomTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_CUSTOMERROOM;
    header<<QObject::trUtf8("卡号")<<QObject::trUtf8("刷卡时间");
}

/**
 * @brief CustomerRoomTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void CustomerRoomTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar PRIMARY KEY not null, ");
    str += header.at(1) + tr(" varchar);");

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
 * @brief CustomerRoomTableModel::restore
 * 绑定表名
 */
void CustomerRoomTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief CustomerRoomTableModel::findRecord
 * @param cardId 卡号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int CustomerRoomTableModel::findRecordById(const QString cardId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == cardId)
            return row;
    }
    return -1;
}
///**
// * @brief CustomerRoomTableModel::findRecord
// * @param personId 人员编号
// * @return QSqlRecord型记录集
// * 根据人员编号查找记录
// */
//QSqlRecord CustomerRoomTableModel::findRecordByName(const QString userName)
//{
//    setFilter(QObject::tr("姓名= '%1'").arg(userName)); //根据姓名进行筛选
//    select();
//    return record();
//}
/**
 * @brief CustomerRoomTableModel::insertRecords
 * @param personId   人员编号
 * @param personName 人员名称
 * @param personType 身份类别
 * @param remark 备注信息
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool CustomerRoomTableModel::insertRecords(QString cardId, QString Time)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" ) ")
           .arg(cardId).arg(Time);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief CustomerRoomTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool CustomerRoomTableModel::deleteRecords(int row)
{
    return removeRow(row);
}
