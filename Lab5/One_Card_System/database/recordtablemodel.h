#ifndef RECORDTABLEMODEL_H
#define RECORDTABLEMODEL_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
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
    Q_OBJECT
private:
    QString tableName; //表名

    QStringList header;//表头

public:

    explicit RecordTableModel(QObject *parent = 0);

    void createTable();//创建表

    void bindTable(void);//绑定表

    //根据卡号查找记录,返回该记录
    QSqlRecord findRecord(const QString &tagId);

    //根据tagId删除记录
    bool deleteByTagId(const QString &tagId);

    //添加记录
    int addRecord(QString &tagId,QString &time,QString &addr,QString &readerId,QString &value,QString remark);

signals:

public slots:
};

#endif // RECORDTABLEMODEL_H
