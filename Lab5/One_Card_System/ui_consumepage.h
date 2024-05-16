/********************************************************************************
** Form generated from reading UI file 'consumepage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSUMEPAGE_H
#define UI_CONSUMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsumePage
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_Tips;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_telephoneNumber;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEdit_tagId;
    QLineEdit *lineEdit_roomId;
    QLabel *label;
    QPushButton *btn_Enventory;
    QLineEdit *lineEdit_customerName;
    QLabel *label_5;
    QLineEdit *lineEdit_time1;
    QLabel *label_7;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QTextEdit *remark;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_Cancel;
    QPushButton *btn_OK;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QComboBox *comboBox_goodsName;
    QLabel *label_9;
    QLineEdit *lineEdit_value1;
    QLabel *label_12;
    QLineEdit *lineEdit_time2;
    QLineEdit *lineEdit_tagId1;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_13;
    QLabel *label_10;
    QPushButton *btn_Enventory1;
    QLineEdit *lineEdit_ReadId1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_14;
    QTextEdit *remark1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_Return1;
    QPushButton *btn_OK1;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_tagId2;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_time3;
    QLabel *label_15;
    QPushButton *btn_Enventory2;
    QComboBox *comboBox_supermarket;
    QLineEdit *lineEdit_value2;
    QLabel *label_16;
    QLineEdit *lineEdit_ReadId2;
    QLabel *label_19;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_21;
    QTextEdit *remark2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_Return2;
    QPushButton *btn_OK2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QLabel *label_26;
    QLabel *label_23;
    QLineEdit *lineEdit_value3;
    QLineEdit *lineEdit_time4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_27;
    QPushButton *btn_Enventory3;
    QLineEdit *lineEdit_tagId3;
    QLabel *label_24;
    QLineEdit *lineEdit_ReadId3;
    QLabel *label_22;
    QComboBox *comboBox_castType;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_28;
    QTextEdit *remark3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_Return3;
    QPushButton *btn_OK3;

    void setupUi(QWidget *ConsumePage)
    {
        if (ConsumePage->objectName().isEmpty())
            ConsumePage->setObjectName(QStringLiteral("ConsumePage"));
        ConsumePage->resize(774, 590);
        horizontalLayout = new QHBoxLayout(ConsumePage);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(ConsumePage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_Tips = new QLabel(groupBox);
        label_Tips->setObjectName(QStringLiteral("label_Tips"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(14);
        label_Tips->setFont(font1);
        label_Tips->setAlignment(Qt::AlignCenter);
        label_Tips->setMargin(6);

        verticalLayout_9->addWidget(label_Tips);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_telephoneNumber = new QLineEdit(groupBox_2);
        lineEdit_telephoneNumber->setObjectName(QStringLiteral("lineEdit_telephoneNumber"));
        lineEdit_telephoneNumber->setFont(font);

        gridLayout->addWidget(lineEdit_telephoneNumber, 1, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_tagId = new QLineEdit(groupBox_2);
        lineEdit_tagId->setObjectName(QStringLiteral("lineEdit_tagId"));
        lineEdit_tagId->setFont(font);

        gridLayout->addWidget(lineEdit_tagId, 4, 1, 1, 3);

        lineEdit_roomId = new QLineEdit(groupBox_2);
        lineEdit_roomId->setObjectName(QStringLiteral("lineEdit_roomId"));
        lineEdit_roomId->setFont(font);

        gridLayout->addWidget(lineEdit_roomId, 2, 1, 1, 3);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        btn_Enventory = new QPushButton(groupBox_2);
        btn_Enventory->setObjectName(QStringLiteral("btn_Enventory"));
        btn_Enventory->setFont(font);

        gridLayout->addWidget(btn_Enventory, 5, 3, 1, 1);

        lineEdit_customerName = new QLineEdit(groupBox_2);
        lineEdit_customerName->setObjectName(QStringLiteral("lineEdit_customerName"));

        gridLayout->addWidget(lineEdit_customerName, 0, 2, 1, 2);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_time1 = new QLineEdit(groupBox_2);
        lineEdit_time1->setObjectName(QStringLiteral("lineEdit_time1"));
        lineEdit_time1->setFont(font);

        gridLayout->addWidget(lineEdit_time1, 3, 1, 1, 3);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        remark = new QTextEdit(groupBox_2);
        remark->setObjectName(QStringLiteral("remark"));
        remark->setFont(font);

        verticalLayout->addWidget(remark);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_Cancel = new QPushButton(groupBox_2);
        btn_Cancel->setObjectName(QStringLiteral("btn_Cancel"));
        btn_Cancel->setFont(font);

        horizontalLayout_2->addWidget(btn_Cancel);

        btn_OK = new QPushButton(groupBox_2);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));
        btn_OK->setFont(font);

        horizontalLayout_2->addWidget(btn_OK);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_9->addLayout(verticalLayout_3, 0, 1, 1, 1);

        gridLayout_9->setColumnStretch(0, 3);
        gridLayout_9->setColumnStretch(1, 2);

        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 2);

        comboBox_goodsName = new QComboBox(groupBox_3);
        comboBox_goodsName->setObjectName(QStringLiteral("comboBox_goodsName"));
        comboBox_goodsName->setFont(font);

        gridLayout_2->addWidget(comboBox_goodsName, 0, 2, 1, 2);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_value1 = new QLineEdit(groupBox_3);
        lineEdit_value1->setObjectName(QStringLiteral("lineEdit_value1"));
        lineEdit_value1->setFont(font);

        gridLayout_2->addWidget(lineEdit_value1, 1, 1, 1, 3);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        lineEdit_time2 = new QLineEdit(groupBox_3);
        lineEdit_time2->setObjectName(QStringLiteral("lineEdit_time2"));
        lineEdit_time2->setFont(font);

        gridLayout_2->addWidget(lineEdit_time2, 3, 1, 1, 3);

        lineEdit_tagId1 = new QLineEdit(groupBox_3);
        lineEdit_tagId1->setObjectName(QStringLiteral("lineEdit_tagId1"));
        lineEdit_tagId1->setFont(font);

        gridLayout_2->addWidget(lineEdit_tagId1, 4, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 5, 2, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        btn_Enventory1 = new QPushButton(groupBox_3);
        btn_Enventory1->setObjectName(QStringLiteral("btn_Enventory1"));
        btn_Enventory1->setFont(font);

        gridLayout_2->addWidget(btn_Enventory1, 5, 3, 1, 1);

        lineEdit_ReadId1 = new QLineEdit(groupBox_3);
        lineEdit_ReadId1->setObjectName(QStringLiteral("lineEdit_ReadId1"));
        lineEdit_ReadId1->setFont(font);

        gridLayout_2->addWidget(lineEdit_ReadId1, 2, 1, 1, 3);


        gridLayout_10->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_14);

        remark1 = new QTextEdit(groupBox_3);
        remark1->setObjectName(QStringLiteral("remark1"));
        remark1->setFont(font);

        verticalLayout_2->addWidget(remark1);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btn_Return1 = new QPushButton(groupBox_3);
        btn_Return1->setObjectName(QStringLiteral("btn_Return1"));
        btn_Return1->setFont(font);

        horizontalLayout_4->addWidget(btn_Return1);

        btn_OK1 = new QPushButton(groupBox_3);
        btn_OK1->setObjectName(QStringLiteral("btn_OK1"));
        btn_OK1->setFont(font);

        horizontalLayout_4->addWidget(btn_OK1);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout_10->addLayout(verticalLayout_4, 0, 1, 1, 1);

        gridLayout_10->setColumnStretch(0, 3);
        gridLayout_10->setColumnStretch(1, 2);

        gridLayout_3->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_tagId2 = new QLineEdit(groupBox_4);
        lineEdit_tagId2->setObjectName(QStringLiteral("lineEdit_tagId2"));
        lineEdit_tagId2->setFont(font);

        gridLayout_4->addWidget(lineEdit_tagId2, 4, 1, 1, 3);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 4, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 5, 2, 1, 1);

        lineEdit_time3 = new QLineEdit(groupBox_4);
        lineEdit_time3->setObjectName(QStringLiteral("lineEdit_time3"));
        lineEdit_time3->setFont(font);

        gridLayout_4->addWidget(lineEdit_time3, 3, 1, 1, 3);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_15, 0, 0, 1, 1);

        btn_Enventory2 = new QPushButton(groupBox_4);
        btn_Enventory2->setObjectName(QStringLiteral("btn_Enventory2"));
        btn_Enventory2->setFont(font);

        gridLayout_4->addWidget(btn_Enventory2, 5, 3, 1, 1);

        comboBox_supermarket = new QComboBox(groupBox_4);
        comboBox_supermarket->setObjectName(QStringLiteral("comboBox_supermarket"));
        comboBox_supermarket->setFont(font);

        gridLayout_4->addWidget(comboBox_supermarket, 0, 1, 1, 3);

        lineEdit_value2 = new QLineEdit(groupBox_4);
        lineEdit_value2->setObjectName(QStringLiteral("lineEdit_value2"));
        lineEdit_value2->setFont(font);

        gridLayout_4->addWidget(lineEdit_value2, 1, 1, 1, 3);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        lineEdit_ReadId2 = new QLineEdit(groupBox_4);
        lineEdit_ReadId2->setObjectName(QStringLiteral("lineEdit_ReadId2"));
        lineEdit_ReadId2->setFont(font);

        gridLayout_4->addWidget(lineEdit_ReadId2, 2, 1, 1, 3);

        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_19, 3, 0, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_17, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_21);

        remark2 = new QTextEdit(groupBox_4);
        remark2->setObjectName(QStringLiteral("remark2"));
        remark2->setFont(font);

        verticalLayout_6->addWidget(remark2);


        verticalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btn_Return2 = new QPushButton(groupBox_4);
        btn_Return2->setObjectName(QStringLiteral("btn_Return2"));
        btn_Return2->setFont(font);

        horizontalLayout_6->addWidget(btn_Return2);

        btn_OK2 = new QPushButton(groupBox_4);
        btn_OK2->setObjectName(QStringLiteral("btn_OK2"));
        btn_OK2->setFont(font);

        horizontalLayout_6->addWidget(btn_OK2);


        verticalLayout_5->addLayout(horizontalLayout_6);


        gridLayout_7->addLayout(verticalLayout_5, 0, 1, 1, 1);

        gridLayout_7->setColumnStretch(0, 3);
        gridLayout_7->setColumnStretch(1, 2);

        gridLayout_3->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font);
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_26, 3, 0, 1, 1);

        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_23, 1, 0, 1, 1);

        lineEdit_value3 = new QLineEdit(groupBox_5);
        lineEdit_value3->setObjectName(QStringLiteral("lineEdit_value3"));
        lineEdit_value3->setFont(font);

        gridLayout_5->addWidget(lineEdit_value3, 1, 1, 1, 3);

        lineEdit_time4 = new QLineEdit(groupBox_5);
        lineEdit_time4->setObjectName(QStringLiteral("lineEdit_time4"));
        lineEdit_time4->setFont(font);

        gridLayout_5->addWidget(lineEdit_time4, 3, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 5, 2, 1, 1);

        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_27, 4, 0, 1, 1);

        btn_Enventory3 = new QPushButton(groupBox_5);
        btn_Enventory3->setObjectName(QStringLiteral("btn_Enventory3"));
        btn_Enventory3->setFont(font);

        gridLayout_5->addWidget(btn_Enventory3, 5, 3, 1, 1);

        lineEdit_tagId3 = new QLineEdit(groupBox_5);
        lineEdit_tagId3->setObjectName(QStringLiteral("lineEdit_tagId3"));
        lineEdit_tagId3->setFont(font);

        gridLayout_5->addWidget(lineEdit_tagId3, 4, 1, 1, 3);

        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_24, 2, 0, 1, 1);

        lineEdit_ReadId3 = new QLineEdit(groupBox_5);
        lineEdit_ReadId3->setObjectName(QStringLiteral("lineEdit_ReadId3"));
        lineEdit_ReadId3->setFont(font);

        gridLayout_5->addWidget(lineEdit_ReadId3, 2, 1, 1, 3);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_22, 0, 0, 1, 2);

        comboBox_castType = new QComboBox(groupBox_5);
        comboBox_castType->setObjectName(QStringLiteral("comboBox_castType"));
        comboBox_castType->setFont(font);

        gridLayout_5->addWidget(comboBox_castType, 0, 2, 1, 2);


        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_28);

        remark3 = new QTextEdit(groupBox_5);
        remark3->setObjectName(QStringLiteral("remark3"));
        remark3->setFont(font);

        verticalLayout_8->addWidget(remark3);


        verticalLayout_7->addLayout(verticalLayout_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        btn_Return3 = new QPushButton(groupBox_5);
        btn_Return3->setObjectName(QStringLiteral("btn_Return3"));
        btn_Return3->setFont(font);

        horizontalLayout_8->addWidget(btn_Return3);

        btn_OK3 = new QPushButton(groupBox_5);
        btn_OK3->setObjectName(QStringLiteral("btn_OK3"));
        btn_OK3->setFont(font);

        horizontalLayout_8->addWidget(btn_OK3);


        verticalLayout_7->addLayout(horizontalLayout_8);


        gridLayout_8->addLayout(verticalLayout_7, 0, 1, 1, 1);

        gridLayout_8->setColumnStretch(0, 3);
        gridLayout_8->setColumnStretch(1, 2);

        gridLayout_3->addWidget(groupBox_5, 1, 1, 1, 1);


        verticalLayout_9->addLayout(gridLayout_3);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(ConsumePage);

        QMetaObject::connectSlotsByName(ConsumePage);
    } // setupUi

    void retranslateUi(QWidget *ConsumePage)
    {
        ConsumePage->setWindowTitle(QApplication::translate("ConsumePage", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ConsumePage", "\345\210\267\345\215\241\346\250\241\346\213\237", Q_NULLPTR));
        label_Tips->setText(QString());
        groupBox_2->setTitle(QApplication::translate("ConsumePage", "\346\210\277\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConsumePage", "\346\210\277\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_tagId->setText(QString());
        label->setText(QApplication::translate("ConsumePage", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        btn_Enventory->setText(QApplication::translate("ConsumePage", "\350\257\206\345\210\253", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConsumePage", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        lineEdit_time1->setText(QString());
        label_7->setText(QApplication::translate("ConsumePage", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConsumePage", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ConsumePage", "\345\244\207\346\263\250", Q_NULLPTR));
        btn_Cancel->setText(QApplication::translate("ConsumePage", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_OK->setText(QApplication::translate("ConsumePage", "\345\274\200\351\227\250", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ConsumePage", "\345\201\245\350\272\253\346\210\277", Q_NULLPTR));
        label_8->setText(QApplication::translate("ConsumePage", "\345\225\206\345\223\201\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("ConsumePage", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("ConsumePage", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        lineEdit_time2->setText(QString());
        lineEdit_tagId1->setText(QString());
        label_13->setText(QApplication::translate("ConsumePage", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("ConsumePage", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        btn_Enventory1->setText(QApplication::translate("ConsumePage", "\350\257\206\345\210\253", Q_NULLPTR));
        label_14->setText(QApplication::translate("ConsumePage", "\345\244\207\346\263\250", Q_NULLPTR));
        btn_Return1->setText(QApplication::translate("ConsumePage", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_OK1->setText(QApplication::translate("ConsumePage", "\347\273\223\350\264\246", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("ConsumePage", "\350\266\205\345\270\202", Q_NULLPTR));
        lineEdit_tagId2->setText(QString());
        label_20->setText(QApplication::translate("ConsumePage", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_time3->setText(QString());
        label_15->setText(QApplication::translate("ConsumePage", "\350\266\205\345\270\202\357\274\232", Q_NULLPTR));
        btn_Enventory2->setText(QApplication::translate("ConsumePage", "\350\257\206\345\210\253", Q_NULLPTR));
        label_16->setText(QApplication::translate("ConsumePage", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("ConsumePage", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("ConsumePage", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("ConsumePage", "\345\244\207\346\263\250", Q_NULLPTR));
        btn_Return2->setText(QApplication::translate("ConsumePage", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_OK2->setText(QApplication::translate("ConsumePage", "\347\273\223\350\264\246", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("ConsumePage", "\346\264\227\350\241\243\346\210\277", Q_NULLPTR));
        label_26->setText(QApplication::translate("ConsumePage", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("ConsumePage", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        lineEdit_time4->setText(QString());
        label_27->setText(QApplication::translate("ConsumePage", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        btn_Enventory3->setText(QApplication::translate("ConsumePage", "\350\257\206\345\210\253", Q_NULLPTR));
        lineEdit_tagId3->setText(QString());
        label_24->setText(QApplication::translate("ConsumePage", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("ConsumePage", "\346\266\210\350\264\271\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        label_28->setText(QApplication::translate("ConsumePage", "\345\244\207\346\263\250", Q_NULLPTR));
        btn_Return3->setText(QApplication::translate("ConsumePage", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_OK3->setText(QApplication::translate("ConsumePage", "\347\273\223\350\264\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConsumePage: public Ui_ConsumePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSUMEPAGE_H
