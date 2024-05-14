#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QGroupBox>
#include "sqlite.h"

#define Table_Column_Record 2//表格列数
#define Edit_Count_Record 2//文本框个数
#define Button_Count_Record 2//按钮个数
#define Label_Count_Record 2//标签个数

enum Label_Index_Record{UserID_Record = 0, BookID_Record};
enum Button_Index_Record{Select_Record = 0, Delete_Record};

class Record : public QWidget
{
    Q_OBJECT
public:
    explicit Record(QWidget *parent = 0);
    void ShowTable(QSqlQuery query);//显示表格
    void Clear();//清空文本框和表格信息
    void SetSlot();//设置槽函数
    void ClearEdit();//清空文本框
    void SetCard(QString cardID);

public slots:
    void delete_record();//删除按钮槽
    void select_record();//搜索按钮槽
    void get_table_line(int row, int col);//单击表格一行触发的槽
private:
    QPushButton *Button[Button_Count_Record];
    QLineEdit *Edit[Edit_Count_Record];
    QLabel *Label[Label_Count_Record];
    QTableWidget *Table;//表格
    Sqlite *sql;//数据库相关操作的类
};

#endif // Record_H
