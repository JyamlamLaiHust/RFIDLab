#include "recordtablemodel.h"
#include "database/database_api.h"
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 消费记录表的model
***************************************/
RecordTableModel::RecordTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_RECORD;
    header<<QObject::trUtf8("卡号")<<
            QObject::trUtf8("时间")<<
            QObject::trUtf8("地点")<<
            QObject::trUtf8("读卡器编号")<<
            QObject::trUtf8("金额")<<
            QObject::trUtf8("信息备注");
}
/**
 * @brief RecordTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建消费记录表
 */
void RecordTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar not null, ");
    str += header.at(1) + tr(" varchar, ");
    str += header.at(2) + tr(" varchar, ");
    str += header.at(3) + tr(" varchar, ");
    str += header.at(4) + tr(" varchar, ");
    str += header.at(5) + tr(" varchar) ");
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
 * @brief RecordTableModel::restore
 * 绑定表名
 */
void RecordTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief RecordTableModel::findRecord
 * @param tagId
 * @return QSqlRecord型记录集
 * 根据卡号查找记录
 */
QSqlRecord RecordTableModel::findRecord(const QString &tagId)
{
    for(int row=0; row<rowCount(); row++){
        if(data(index(row, 0)).toString() == tagId)
            return record(row);
    }
    return QSqlRecord();
}
/**
 * @brief RecordTableModel::deleteByTagId
 * @param tagId 卡号
 * @return 如果成功返回true，否则false
 * 根据卡号删除记录
 */
bool RecordTableModel::deleteByTagId(const QString &tagId)
{
    for(int row=0; row<rowCount(); row++){
        if(data(index(row, 0)).toString() == tagId)
            removeRow(row);
    }
    return submitAll();
}
/**
 * @brief RecordTableModel::addRecord
 * @param tagId 卡号
 * @param time 消费时间
 * @param addr 消费地址
 * @param readerId 读卡器ID
 * @param value 消费金额
 * @param remark 备注
 * @return 记录条数
 * 添加记录
 */
int RecordTableModel::addRecord(QString &tagId, QString &time, QString &addr,
                                 QString &readerId, QString &value, QString remark)
{
    QSqlRecord record;//也可以直接使用sql语句进行,但是sql语句更容易写错
    record.append(QSqlField(header.at(0), QVariant::String));
    record.append(QSqlField(header.at(1), QVariant::String));
    record.append(QSqlField(header.at(2), QVariant::String));
    record.append(QSqlField(header.at(3), QVariant::String));
    record.append(QSqlField(header.at(4), QVariant::String));
    record.append(QSqlField(header.at(5), QVariant::String));
    record.setValue(0, QVariant(tagId));
    record.setValue(1, QVariant(time));
    record.setValue(2, QVariant(addr));
    record.setValue(3, QVariant(readerId));
    record.setValue(4, QVariant(value));
    record.setValue(5, QVariant(remark));
    insertRecord(-1, record);
    return rowCount();
}
