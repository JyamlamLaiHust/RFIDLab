#ifndef ADMINTABLEMODEL_H
#define ADMINTABLEMODEL_H

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
 *描述: 管理员表 model对象
***************************************/
class AdminTableModel : public QObject
{
    Q_OBJECT
private:
    QSqlTableModel *model;//sqltablemodel,作为管理员的model

    QString tableName;//表名

    QStringList header;//表头
public:
    explicit AdminTableModel(QObject *parent = 0);
    void createTable();//创建表
    void bindTable(void);//绑定表
    QSqlTableModel* getModel(void);//获取管理员表的model
    QSqlRecord findRecord(const QString &userName);//查找记录
    int insertRecords(QString userName, QString pawd, QString remark);//插入记录
    bool updateRecords(QString personName, QString pwd, QString time);//更新记录
//    bool deleteRecords(QString userName);

signals:

public slots:
};

#endif // ADMINTABLEMODEL_H
