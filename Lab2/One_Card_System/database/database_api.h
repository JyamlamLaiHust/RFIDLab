#ifndef DATABASE_API_H
#define DATABASE_API_H
#include <QtSql/QSqlTableModel>
//***************表名,数据库名****************//
#define DATABASE_NAME   "db_OneCardSystem.db"
#define TABLE_NAME_ADMIN    "table_admin"
#define TABLE_NAME_PERSON   "table_Person"
#define TABLE_NAME_REGISTER "table_Register"
#define TABLE_NAME_WRITEOFF "table_WriteOff"
#define TABLE_NAME_RECORD   "table_Records"
#define TABLE_NAME_RECHARGE "table_Recharge"

//***************外部API接口*****************//
extern void DB_Init();//DB初始化
extern void DB_Close();//DB关闭
extern QStringList getTableNames();//获取当前DB所有表的表名

#endif // DATABASE_API_H
