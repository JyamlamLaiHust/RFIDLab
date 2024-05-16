#ifndef REGIST_WIDGET_H
#define REGIST_WIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include "sqlite.h"

#define LABEL_COUNT_REGIST 4
#define EDIT_COUNT_REGIST 3
#define BUTTON_COUNT_REGIST 3
enum BUTTON_INDEX_REGIST{Regist_Regist = 0, Rese_Registt, Cancel_Regist};
enum EDIT_INDEX_REGIST{ ID_Regist = 0, Plate_number_Regist, Balance_Regist};//文本框数组下标

class Regist_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Regist_Widget(QWidget *parent = 0);

signals:

public slots:
    void Uhf_Regist_Button_Click();
    void Uhf_Rese_Button_Click();
    void Uhf_Cancel_Button_Click();
    void Set_CardID(QString Card_id);

private:
    QLabel *Label[LABEL_COUNT_REGIST], *instruction; //标签
    QLineEdit *Edit[EDIT_COUNT_REGIST]; //文本框
    QPushButton *PushButton[BUTTON_COUNT_REGIST]; //UHF区域按钮
    QComboBox *Types;
};

#endif // REGIST_WIDGET_H
