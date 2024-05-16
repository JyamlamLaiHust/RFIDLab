#ifndef CUSTOMERTABLEMODEL_H
#define CUSTOMERTABLEMODEL_H

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
class CustomerTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QString tableName;//表名

    QStringList header;//表头
public:
    explicit CustomerTableModel(QObject *parent = 0);
    void createTable();//创建表
    void bindTable(void);//绑定表
    int findRecordById(const QString cardId);//根据用户Id查询记录
    QSqlRecord findRecordByName(const QString customerName);//根据用户名查询记录
    QString findNameByTagId(const QString tagId);
    QString findInUseByTagId(const QString tagId);
    QString findTelephoneNumberByTagId(const QString tagId);
    //插入记录
    bool insertRecords(QString cardId, QString customerName, QString telephoneNumber, QString isUse);
    //删除记录
    bool deleteRecords(int row);

signals:

public slots:
};

#endif // CUSTOMERTABLEMODEL_H
