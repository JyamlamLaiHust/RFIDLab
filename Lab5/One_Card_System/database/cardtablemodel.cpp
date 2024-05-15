#include "cardtablemodel.h"

#include "database/database_api.h"
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
            QObject::trUtf8("房间号")<< QObject::trUtf8("状态标志");
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
    str += header.at(3) + tr(" varchar) ");
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
int CardTableModel::findRecordById(const QString cardId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == cardId)
            return row;
    }
    return -1;
}
/**
 * @brief CardTableModel::findRecord
 * @param customerName 姓名
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
QSqlRecord CardTableModel::findRecordByName(const QString customerName)
{
    setFilter(QObject::tr("姓名= '%1'").arg(customerName)); //根据姓名进行筛选
    select();
    return record();
}
/**
 * @brief CardTableModel::insertRecords
 * @param cardId 卡号
 * @param customerName 姓名
 * @param telephoneNumber 手机号
 * @param isUse 是否激活
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool CardTableModel::insertRecords(QString cardId, QString customerName, QString telephoneNumber, QString isUse)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" , \"%3\" , \"%4\" ) ")
           .arg(cardId).arg(customerName).arg(telephoneNumber).arg(isUse);
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
