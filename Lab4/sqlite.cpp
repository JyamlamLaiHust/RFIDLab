#include "sqlite.h"

Sqlite::Sqlite()
{
}
/*连接数据库*/
bool Sqlite::connect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE);
    if(!db.open()) return false;
    QSqlQuery query;
    /*创建user表 cardID和plate_number作为联合主键*/
    //卡号、车牌号、车类型、余额
    query.exec("create table user_900M (cardID vchar, plate_number vchar, type vchar, balance float, primary key (cardID,plate_number))");
    /*创建record表 cardID和plate_number作为外键*/
    //卡号、车牌号、进入时间、出去时间、计费、余额
    query.exec("create table record_900M (cardID vchar, plate_number vchar, inTime vchar, outTime vchar, consumption float, balance float,FOREIGN KEY (cardID ) REFERENCES user(cardID), FOREIGN KEY (plate_number ) REFERENCES user(plate_number))");
    return true;
}

/*添加user数据*/
bool Sqlite::add_user(char *cardID, char *plate_number, char *type, float balance)
{
    char command[256];
    sprintf(command, "insert into user_900M values('%s', '%s', '%s', %2f);", cardID, plate_number, type, balance);
    qDebug("ADD USER:%s\n",command);
    QSqlQuery query;
    return query.exec(command);
}

/*添加record数据*/
bool Sqlite::add_record(char *cardID, char *plate_number, char *inTime, char *outTime, float consumption,float balance)
{
    char command[256];
    sprintf(command, "insert into record_900M values('%s', '%s', '%s', '%s', %2f, %2f);", cardID, plate_number, inTime, outTime, consumption, balance);
    qDebug("ADD RECORD:%s\n",command);
    QSqlQuery query;
    return query.exec(command);
}
/*更改user中的数据*/
bool Sqlite::update_user(char *cardID, char *plate_number, float balance)
{
    char command[256];
    sprintf(command, "update user_900M set balance = %2f where cardID = '%s' and plate_number = '%s'", balance, cardID, plate_number);
    QSqlQuery query;
    qDebug("UPDATE USER:%s\n",command);
    return query.exec(command);
}
//更改record中的数据
bool Sqlite::update_record(char *cardID, char *plate_number, char *inTime, char *outTime, float consumption,float balance)
{
    char command[256];
    sprintf(command, "update record_900M set outTime = '%s', consumption = %2f, balance = %2f where cardID = '%s' and plate_number = '%s' and inTime = '%s'", outTime, consumption, balance, cardID, plate_number, inTime);
    QSqlQuery query;
    qDebug("UPDATE RECORD:%s\n",command);
    return query.exec(command);
}

//查找（表名称，条件）
QSqlQuery Sqlite::select(const char *table, char *where)
{
    char command[256];
    sprintf(command, "select * from %s", table);
    if(where!=NULL)
    {
        char tmp[256];
        strcpy(tmp,command);
        sprintf(command,"%s where %s",tmp,where);
    }
    QSqlQuery query;
    qDebug("SELECT:%s\n",command);
    query.exec(command);
    return query;
}

//删除（表名称，条件）
bool Sqlite::del(const char *table, char *where)
{
    char command[256];
    sprintf(command, "delete from %s", table);
    if(where!=NULL)
    {
        char tmp[256];
        strcpy(tmp,command);
        sprintf(command,"%s where %s",tmp,where);
    }
    QSqlQuery query;
    qDebug("DEL:%s\n",command);
    return query.exec(command);
}

Sqlite::~Sqlite()
{
    db.close();
}
