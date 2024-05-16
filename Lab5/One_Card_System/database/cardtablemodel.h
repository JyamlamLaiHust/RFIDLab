#ifndef CARDTABLEMODEL_H
#define CARDTABLEMODEL_H

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
class CardTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QString tableName;//表名

    QStringList header;//表头
public:
    explicit CardTableModel(QObject *parent = 0);
    void createTable();//创建表
    void bindTable(void);//绑定表
    int findRecordByCardId(const QString cardId);//根据用户Id查询记录
    int findRecordByRoomId(const QString roomId);//根据用户Id查询记录

    QSqlRecord findRecordByName(const QString customerName);//根据用户名查询记录
    //插入记录
    bool insertRecords(QString number, QString cardId, QString roomId, QDateTime checkInTime, QDateTime checkOutTime, bool isUse);
    //删除记录
    bool deleteRecords(int row);
    QString findRoomIdByTagId(const QString tagId);
    QDateTime findCheckOutTimeByTagId(const QString tagId);
signals:

public slots:
};

#endif // CARDTABLEMODEL_H
