#ifndef BOOKSMANAGE_H
#define BOOKSMANAGE_H

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

#define Button_Count_BOOKS 4    //按钮个数
#define Edit_Count_BOOKS 6      //文本框个数
#define Label_Count_BOOKS 6     //标签个数
#define Table_Column_BOOKS 6    //表格列数

enum Button_Index_Books{Add_Books = 0, Delete_Books, Updata_Books, Select_Books};                                //读卡、添加按钮、删除按钮、更新按钮、搜索按钮
enum Edit_Index_Books{ID_Books = 0, Name_Books, Author_Books, PublishingHouse_Books, Count_Books, Residue_Books};//编号、书名、作者、出版社、总数、剩余

class BooksManage : public QWidget//图书管理界面
{
    Q_OBJECT
public:
    explicit BooksManage(QWidget *parent = 0);
    void SetSlot();                     //设置槽函数
    void ShowTable(QSqlQuery query);    //显示表函数
    void ClearEdit();                   //清空文本框
    void Clear();                       //清空文本框和表格信息
    void SetCard(QString cardID);

public slots:
    void add_books();   //添加按钮槽
    void delete_books();//删除按钮槽
    void updata_books();//更新按钮槽
    void select_books();//搜索按钮槽
    void get_table_line(int row, int col);//单击表格一行触发的槽

private:
    QPushButton *Button[Button_Count_BOOKS];//按钮
    QLineEdit *Edit[Edit_Count_BOOKS];//文本框
    QLabel *Label[Label_Count_BOOKS];//标签
    QTableWidget *Table;//表格
    Sqlite *sql;//数据库相关操作类
};

#endif // BOOKSMANAGE_H
