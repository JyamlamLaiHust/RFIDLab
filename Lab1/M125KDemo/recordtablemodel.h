#ifndef RECORDTABLEMODEL_H
#define RECORDTABLEMODEL_H
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlField>
#include <QString>
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 消费记录的model
***************************************/
class RecordTableModel : public QSqlTableModel
{
public:
    explicit RecordTableModel(QObject *parent = 0);

    void createTable();//创建表

    //检测该表是否存在
    bool tableExist(const QString &tableName);

    //根据卡号查找记录,返回该记录
    int findRecord(const QString &tagId);

    //根据tagId删除记录
    bool deleteByTagId(const QString &tagId);

    //添加记录
    int addRecord(QString &tagId, QString &time, QString status,QString lasttime);

    void updateRecord(int row,QString &tagId, QString &time, QString status,QString lasttime);
private:
    QSqlDatabase db;

    QString tableName; //表名

    QStringList header;//表头
};

#endif // RECORDTABLEMODEL_H
