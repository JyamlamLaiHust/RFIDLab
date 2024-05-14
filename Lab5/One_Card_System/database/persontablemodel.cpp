#include "persontablemodel.h"
#include "database/database_api.h"
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
PersonTableModel::PersonTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_PERSON;
    header<<QObject::trUtf8("编号")<<QObject::trUtf8("姓名")<<
            QObject::trUtf8("身份类型")<< QObject::trUtf8("信息备注");
}

/**
 * @brief PersonTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void PersonTableModel::createTable()
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
 * @brief PersonTableModel::restore
 * 绑定表名
 */
void PersonTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief PersonTableModel::findRecord
 * @param personId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int PersonTableModel::findRecordById(const QString personId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == personId)
            return row;
    }
    return -1;
}
/**
 * @brief PersonTableModel::findRecord
 * @param personId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
QSqlRecord PersonTableModel::findRecordByName(const QString userName)
{
    setFilter(QObject::tr("姓名= '%1'").arg(userName)); //根据姓名进行筛选
    select();
    return record();
}
/**
 * @brief PersonTableModel::insertRecords
 * @param personId   人员编号
 * @param personName 人员名称
 * @param personType 身份类别
 * @param remark 备注信息
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool PersonTableModel::insertRecords(QString personId,QString personName, QString personType, QString remark)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" , \"%3\" , \"%4\" ) ")
           .arg(personId).arg(personName).arg(personType) .arg(remark);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief PersonTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool PersonTableModel::deleteRecords(int row)
{
    return removeRow(row);
}
