#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QStandardItemModel>
#include <QSqlDatabase>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述:  数据库创建并打开
***************************************/
class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);
    bool addSqliteConnection(const QString &dbName);//创建并打开数据库
};

#endif // DATABASE_H
