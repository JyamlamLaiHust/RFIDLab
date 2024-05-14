#include "database.h"
#include <qdebug.h>
Database::Database(QObject *parent) :QObject(parent)
{
    addSqliteConnection("m125kModule.db");
}
/**
 * @brief Database::addSqliteConnection
 * @param dbName 数据库名称
 * 用于创建数据库
 */
bool Database::addSqliteConnection(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open()){
        qDebug()<<dbName<<" create failed!";
        return false;
    }
    else{
        qDebug()<<dbName<<" create success!";
        return true;
    }
}
