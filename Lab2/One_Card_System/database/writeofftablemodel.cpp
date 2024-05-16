#include "writeofftablemodel.h"
#include "database_api.h"
#include <qdebug.h>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 用户注销表的model
***************************************/
WriteOffTableModel::WriteOffTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_WRITEOFF;
    header<<QObject::trUtf8("卡号")<<QObject::trUtf8("时间")<<QObject::trUtf8("信息备注");
}
/**
 * @brief WriteOffTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建注销表
 */
void WriteOffTableModel::createTable()
{

    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar primary key not null, ");
    str += header.at(1) + tr(" varchar, ");
    str += header.at(2) + tr(" varchar) ");
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
 * @brief WriteOffTableModel::restore
 * 绑定表名
 */
void WriteOffTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief WriteOffTableModel::findRecord
 * @param tagId 卡号
 * @return 记录所在的行
 * 根据卡号查找记录
 */
int WriteOffTableModel::findRecord(const QString &tagId)
{
    for(int row=0; row<rowCount(); row++){
        if(data(index(row, 0)).toString() == tagId)
            return row;
    }
    return -1;
}
/**
 * @brief WriteOffTableModel::addRecords
 * @param tagId 卡号
 * @param time 时间
 * @param remark 备注信息
 * @return 当前记录的总行数
 * 添加记录
 */
int WriteOffTableModel::addRecords(QString &tagId,QString &time,QString &remark)
{
    QSqlRecord record;
    record.append(QSqlField(header.at(0), QVariant::String));
    record.append(QSqlField(header.at(1), QVariant::String));
    record.append(QSqlField(header.at(2), QVariant::String));
    record.setValue(0, QVariant(tagId));
    record.setValue(1, QVariant(time));
    record.setValue(2, QVariant(remark));
    insertRecord(-1, record);
    return rowCount();
}
/**
 * @brief WriteOffTableModel::updateRecords
 * @param tagId 卡号
 * @param time 当前时间
 * @param remark 备注
 * @return 如果更新成功返回true，否则返回false
 * 更新记录
 */
bool WriteOffTableModel::updateRecords(QString &tagId,QString &time,QString &remark)
{
    setFilter(tr("卡号 = '%1'").arg(tagId));
    select();
    if (rowCount() == 1)
    {
        setData(index(0, 0), QVariant(tagId));
        setData(index(0, 1), QVariant(time));
        setData(index(0, 2), QVariant(remark));
        return submitAll();
    }
    return false;
}
