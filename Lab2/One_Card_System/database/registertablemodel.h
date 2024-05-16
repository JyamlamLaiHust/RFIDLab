#ifndef REGISTERTABLEMODEL_H
#define REGISTERTABLEMODEL_H
#include <QSqlTableModel>
#include <QStringList>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlField>
#include <QSqlRecord>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 注册表的model
***************************************/
class RegisterTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit RegisterTableModel(QObject *parent = 0);

    ~RegisterTableModel();

    void createTable();//创建表

    //添加记录,返回记录的总条数
    bool addRecord(QString &cardId, QString &personId, QString &time, QString &remark);

    //根据卡号删除记录,返回删除记录所在的行
    int deleteRecord(QString &tagId);

    //根据卡号查找记录,返回记录所在的行
    int findRecord(QString &tagId);

    //绑定表
    void bindTable(void);

    //获取表头
    QStringList modelHeaders();

private:

signals:

public slots:

private:
    QStringList header;//表头链表

    QString tableName;//表名
};
#endif // REGISTERTABLEMODEL_H
