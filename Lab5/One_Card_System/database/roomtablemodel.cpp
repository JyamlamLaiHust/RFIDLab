#include "roomtablemodel.h"
#include "database/database_api.h"
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
RoomTableModel::RoomTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_ROOM;
    header<<QObject::trUtf8("房号")<<QObject::trUtf8("房间面积");
}

/**
 * @brief RoomTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void RoomTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar PRIMARY KEY not null, ");
    str += header.at(1) + tr(" varchar); ");
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
 * @brief RoomTableModel::restore
 * 绑定表名
 */
void RoomTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief RoomTableModel::findRecord
 * @param roomId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int RoomTableModel::findRecordById(const QString roomId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == roomId)
            return row;
    }
    return -1;
}
///**
// * @brief RoomTableModel::findRecord
// * @param personId 人员编号
// * @return QSqlRecord型记录集
// * 根据人员编号查找记录
// */
//QSqlRecord RoomTableModel::findRecordByName(const QString userName)
//{
//    setFilter(QObject::tr("姓名= '%1'").arg(userName)); //根据姓名进行筛选
//    select();
//    return record();
//}
/**
 * @brief RoomTableModel::insertRecords
 * @param personId   人员编号
 * @param personName 人员名称
 * @param personType 身份类别
 * @param remark 备注信息
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool RoomTableModel::insertRecords(QString roomId,QString square)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" ) ")
           .arg(roomId).arg(square);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief RoomTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool RoomTableModel::deleteRecords(int row)
{
    return removeRow(row);
}
