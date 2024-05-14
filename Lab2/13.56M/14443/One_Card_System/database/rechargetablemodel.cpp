#include "rechargetablemodel.h"
#include "database/database_api.h"
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 充值记录表的model
***************************************/
RechargeTableModel::RechargeTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_RECHARGE;
    header<<QObject::trUtf8("卡号")<<
            QObject::trUtf8("时间")<<
            QObject::trUtf8("原有金额")<<
            QObject::trUtf8("充值金额")<<
            QObject::trUtf8("当前金额")<<
            QObject::trUtf8("信息备注");
}
/**
 * @brief RechargeTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建充值记录表
 */
void RechargeTableModel::createTable()
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
 * @brief RechargeTableModel::restore
 * 绑定表名
 */
void RechargeTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief RechargeTableModel::findRecord
 * @param tagId 卡号
 * @return QSqlRecord型记录集
 * 根据卡号查找记录
 */
QSqlRecord RechargeTableModel::findRecord(const QString &tagId)
{
    for(int row=0; row<rowCount(); row++){
        if(data(index(row, 0)).toString() == tagId)
            return record(row);
    }
    return QSqlRecord();
}
/**
 * @brief RechargeTableModel::deleteByTagId
 * @param tagId 卡号
 * @return 如果成功返回true，否则false
 * 根据卡号删除记录
 */
bool RechargeTableModel::deleteByTagId(const QString &tagId)
{
    for(int row=0; row<rowCount(); row++){
        if(data(index(row, 0)).toString() == tagId)
            removeRow(row);
    }
    return submitAll();
}
/**
 * @brief RechargeTableModel::addRecord
 * @param tagId 卡号
 * @param time 消费时间
 * @param old_value 原有金额
 * @param value 充值金额
 * @param current_value 充值后的金额
 * @param remark 备注
 * @return 记录条数
 * 添加记录
 */
int RechargeTableModel::addRecord(QString tagId, QString time, QString old_value,
                                 QString value, QString current_value, QString remark)
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
    record.setValue(2, QVariant(old_value));
    record.setValue(3, QVariant(value));
    record.setValue(4, QVariant(current_value));
    record.setValue(5, QVariant(remark));
    insertRecord(-1, record);
    return rowCount();
}

