#ifndef BORROW_RETURN_H
#define BORROW_RETURN_H

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
#include <QCheckBox>
#include <QDateTime>
#include <QRadioButton>
#include <QButtonGroup>
#include "sqlite.h"
#include "uhf_thread.h"

#define Edit_Count_BORROW_RETURN 4//用户信息文本框个数
#define Label_Count_BORROW_RETURN 4//用户信息标签个数
#define Table_Column_BORROW_RETURN 6//表格列数

enum Edit_Index_User_Borrow{CardId_User_Borrow = 0, Name_User_Borrow, Gender_User_Borrow, Age_User_Borrow};//卡号、姓名、性别、年龄

class Borrow_Return : public QWidget//借书界面
{
    Q_OBJECT
public:
    explicit Borrow_Return(QWidget *parent = 0);
    void ShowTable(QSqlQuery query);//显示表格
    void SetInfo(QString cardID);//获取卡号
    void Clear();//清空文本框和表格信息

private:
    QLineEdit *Edit_User[Edit_Count_BORROW_RETURN];//用户文本框
    QLabel *Label_User[Label_Count_BORROW_RETURN];//用户标签
    QRadioButton *Borrow,*Return; //借书 还书 单选按钮
    QButtonGroup *Function;//选择功能（借书、还书）
    QTableWidget *Table;//表格
    Sqlite *sql;//数据库操作相关类
};

#endif // Borrow_Return_H
