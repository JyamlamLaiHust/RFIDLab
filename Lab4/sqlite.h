#ifndef SQLITE_H
#define SQLITE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#define DATABASE "database.db"

class Sqlite
{
public:
    Sqlite();
    bool connect();//连接数据库
    bool add_user(char *cardID, char *plate_number, char *type, float balance);//添加到user表中
    bool add_record(char *cardID, char *plate_number, char *inTime, char *outTime, float consumption,float balance);//添加到record表中
    QSqlQuery select(const char *table, char *where = NULL);//查找
    bool del(const char *table, char *where = NULL);//删除
    bool update_record(char *cardID, char *plate_number, char *inTime, char *outTime, float consumption,float balance);//修改record表中数据
    bool update_user(char *cardID, char *plate_number, float balance);//修改user表中数据
    ~Sqlite();

private:
    QSqlDatabase db;
};

#endif // SQLITE_H
