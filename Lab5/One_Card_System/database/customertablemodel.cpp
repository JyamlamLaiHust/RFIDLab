#include "customertablemodel.h"
#include "database/database_api.h"
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
CustomerTableModel::CustomerTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_CUSTOMER;
    header<<QObject::trUtf8("卡号")<<QObject::trUtf8("姓名")<<QObject::trUtf8("身份证")<<QObject::trUtf8("是否激活");
}

/**
 * @brief CustomerTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void CustomerTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar PRIMARY KEY not null, ");
    str += header.at(1) + tr(" varchar, ");
    str += header.at(2) + tr(" varchar, ");
    str += header.at(3) + tr(" varchar); ");

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
 * @brief CustomerTableModel::restore
 * 绑定表名
 */
void CustomerTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief CustomerTableModel::findRecord
 * @param cardId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int CustomerTableModel::findRecordById(const QString cardId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == cardId)
            return row;
    }
    return -1;
}
/**
 * @brief CustomerTableModel::findRecord
 * @param customerName 姓名
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
QSqlRecord CustomerTableModel::findRecordByName(const QString customerName)
{
    setFilter(QObject::tr("姓名= '%1'").arg(customerName)); //根据姓名进行筛选
    select();
    return record();
}
/**
 * @brief CustomerTableModel::insertRecords
 * @param cardId 卡号
 * @param openTime 打开时间
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool CustomerTableModel::insertRecords(QString cardId, QString customerName, QString telephoneNumber, QString isUse)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\", \"%3\" , \"%4\") ")
           .arg(cardId).arg(customerName).arg(telephoneNumber).arg(isUse);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief CustomerTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool CustomerTableModel::deleteRecords(int row)
{
    return removeRow(row);
}

/**
 * @brief CustomerTableModel::findNameByTagId
 * @param tagId 卡号
 * @return 与卡号关联的姓名
 * 根据卡号查找关联的姓名
 */
QString CustomerTableModel::findNameByTagId(const QString tagId)
{
    int row = findRecordById(tagId);
    if (row != -1) {
        return data(index(row, 1)).toString(); // 返回姓名，假设姓名在第二列
    }
    return QString(); // 如果未找到对应的记录，返回空字符串
}

/**
 * @brief CustomerTableModel::findNameByTagId
 * @param tagId 卡号
 * @return 与卡号关联的姓名
 * 根据卡号查找关联的姓名
 */
QString CustomerTableModel::findInUseByTagId(const QString tagId)
{
    int row = findRecordById(tagId);
    if (row != -1) {
        return data(index(row, 2)).toString(); // 返回姓名，假设姓名在第二列
    }
    return QString(); // 如果未找到对应的记录，返回空字符串
}

QString CustomerTableModel::findTelephoneNumberByTagId(const QString tagId)
{
    int row = findRecordById(tagId);
    if (row != -1) {
        return data(index(row, 2)).toString(); // 返回姓名，假设姓名在第二列
    }
    return QString(); // 如果未找到对应的记录，返回空字符串
}
