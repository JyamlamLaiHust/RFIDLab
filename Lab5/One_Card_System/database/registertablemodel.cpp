#include "registertablemodel.h"
#include "database_api.h"
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 注册表的model
***************************************/
RegisterTableModel::RegisterTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_REGISTER;
    header<<QObject::trUtf8("卡号")<<QObject::trUtf8("用户编号")
             <<QObject::trUtf8("时间")<<QObject::trUtf8("信息备注");
}
RegisterTableModel::~RegisterTableModel()
{

}
/**
 * @brief RegisterTableModel::createTable
 * @param tableName 注册表名称
 * 用于创建注册表
 */
void RegisterTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar primary key not null, ");
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
 * @brief RegisterTableModel::restore
 * 绑定表名
 */
void RegisterTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}
/**
 * @brief RegisterTableModel::findRecord
 * @param tagId 标签ID
 * @return QSqlRecord型的记录集
 * 根据卡号查找注册记录
 */
int RegisterTableModel::findRecord(QString &tagId)
{
    int row;
    for(row=0; row<rowCount(); row++){
        if(data(index(row, 0)) == tagId)
            return row;
    }
    return -1;
}
/**
 * @brief RegisterTableModel::addRecord
 * @param cardId 卡号
 * @param personId 人员编号
 * @param time 时间
 * @param remark 备注信息
 * @return 每次插入到最后一行，返回当前记录的总行数
 * 向注册表中插入数据
 */
bool RegisterTableModel::addRecord(QString &cardId,QString &personId, QString &time, QString &remark)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" , \"%3\" , \"%4\" ) ")
            .arg(cardId).arg(personId).arg(time).arg(remark);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}
/**
 * @brief RegisterTableModel::modelHeaders
 * @return QStringList型的表头
 * 返回表头
 */
QStringList RegisterTableModel::modelHeaders()
{
    return header;
}
/**
 * @brief RegisterTableModel::deleteRecord
 * @param tagId 卡号
 * @return 记录所在行
 * 删除记录
 */
int RegisterTableModel::deleteRecord(QString &tagId)
{
    int row = findRecord(tagId);
    if(row>=0){
        removeRow(row);
    }
    return row;
}

