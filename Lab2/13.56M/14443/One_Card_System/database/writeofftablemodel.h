#ifndef WRITEOFFTABLEMODEL_H
#define WRITEOFFTABLEMODEL_H
#include <QObject>
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
 *描述: 注销表的Model
***************************************/
class WriteOffTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QSqlDatabase db;//sqlite database

    QString tableName;//表名称

    QStringList header;//表头

public:

    explicit WriteOffTableModel(QObject *parent = 0);

    void createTable();//创建表

    void bindTable(void);//绑定表

    int findRecord(const QString &tagId);//根据卡号查找记录

    int addRecords(QString &tagId,QString &time,QString &remark);//添加记录

    bool updateRecords(QString &tagId,QString &time,QString &remark);//更新记录

signals:

public slots:
};

#endif // WRITEOFFTABLEMODEL_H
