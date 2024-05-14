#ifndef PERSONTABLEMODEL_H
#define PERSONTABLEMODEL_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
class PersonTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QString tableName;//表名

    QStringList header;//表头
public:
    explicit PersonTableModel(QObject *parent = 0);
    void createTable();//创建表
    void bindTable(void);//绑定表
    int findRecordById(const QString personId);//根据用户Id查询记录
    QSqlRecord findRecordByName(const QString userName);//根据用户名查询记录
    //插入记录
    bool insertRecords(QString personId,QString personName,QString personType,QString remark);
    //删除记录
    bool deleteRecords(int row);

signals:

public slots:
};

#endif // PERSONTABLEMODEL_H
