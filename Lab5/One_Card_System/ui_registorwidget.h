/********************************************************************************
** Form generated from reading UI file 'registorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTORWIDGET_H
#define UI_REGISTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistorWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *comboBox_RoomType;
    QLabel *label_RoomType;
    QLineEdit *lineEdit_IdCard;
    QTextEdit *textEdit_PersonMark;
    QLabel *label_checkInTime;
    QLabel *label_IdCard;
    QLabel *Label_PersonMark;
    QLabel *label;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_RoomId;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_checkInTime;
    QDateTimeEdit *dateTimeEdit_checkOutTime;
    QLabel *label_checkOutTime;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_4;
    QTextEdit *textEdit_CardMark;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_CardId;
    QPushButton *btn_Inventory;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Register;
    QPushButton *btn_Refresh;
    QPushButton *btn_Reset;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;

    void setupUi(QWidget *RegistorWidget)
    {
        if (RegistorWidget->objectName().isEmpty())
            RegistorWidget->setObjectName(QStringLiteral("RegistorWidget"));
        RegistorWidget->resize(807, 360);
        verticalLayout_2 = new QVBoxLayout(RegistorWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        groupBox_4 = new QGroupBox(RegistorWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        groupBox_4->setFont(font);
        groupBox_4->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 6, 1, 1);
        frame = new QFrame(groupBox_4);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 500));
        frame->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(330, 0));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_RoomType = new QComboBox(groupBox);
        comboBox_RoomType->setObjectName(QStringLiteral("comboBox_RoomType"));
        comboBox_RoomType->setFont(font);

        gridLayout->addWidget(comboBox_RoomType, 2, 2, 1, 1);

        label_RoomType = new QLabel(groupBox);
        label_RoomType->setObjectName(QStringLiteral("label_RoomType"));
        label_RoomType->setFont(font);
        label_RoomType->setTextFormat(Qt::AutoText);
        label_RoomType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_RoomType, 2, 0, 1, 1);

        lineEdit_IdCard = new QLineEdit(groupBox);
        lineEdit_IdCard->setObjectName(QStringLiteral("lineEdit_IdCard"));

        gridLayout->addWidget(lineEdit_IdCard, 1, 2, 1, 1);

        textEdit_PersonMark = new QTextEdit(groupBox);
        textEdit_PersonMark->setObjectName(QStringLiteral("textEdit_PersonMark"));
        textEdit_PersonMark->setFont(font);

        gridLayout->addWidget(textEdit_PersonMark, 6, 2, 1, 1);

        label_checkInTime = new QLabel(groupBox);
        label_checkInTime->setObjectName(QStringLiteral("label_checkInTime"));
        label_checkInTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_checkInTime, 4, 0, 1, 1);

        label_IdCard = new QLabel(groupBox);
        label_IdCard->setObjectName(QStringLiteral("label_IdCard"));
        label_IdCard->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_IdCard, 1, 0, 1, 1);

        Label_PersonMark = new QLabel(groupBox);
        Label_PersonMark->setObjectName(QStringLiteral("Label_PersonMark"));
        Label_PersonMark->setFont(font);
        Label_PersonMark->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Label_PersonMark, 6, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_Name = new QLineEdit(groupBox);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));
        lineEdit_Name->setFont(font);

        gridLayout->addWidget(lineEdit_Name, 0, 2, 1, 1);

        lineEdit_RoomId = new QLineEdit(groupBox);
        lineEdit_RoomId->setObjectName(QStringLiteral("lineEdit_RoomId"));

        gridLayout->addWidget(lineEdit_RoomId, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        dateTimeEdit_checkInTime = new QDateTimeEdit(groupBox);
        dateTimeEdit_checkInTime->setObjectName(QStringLiteral("dateTimeEdit_checkInTime"));

        gridLayout->addWidget(dateTimeEdit_checkInTime, 4, 2, 1, 1);

        dateTimeEdit_checkOutTime = new QDateTimeEdit(groupBox);
        dateTimeEdit_checkOutTime->setObjectName(QStringLiteral("dateTimeEdit_checkOutTime"));

        gridLayout->addWidget(dateTimeEdit_checkOutTime, 5, 2, 1, 1);

        label_checkOutTime = new QLabel(groupBox);
        label_checkOutTime->setObjectName(QStringLiteral("label_checkOutTime"));

        gridLayout->addWidget(label_checkOutTime, 5, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(330, 0));
        groupBox_2->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        textEdit_CardMark = new QTextEdit(groupBox_2);
        textEdit_CardMark->setObjectName(QStringLiteral("textEdit_CardMark"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit_CardMark->sizePolicy().hasHeightForWidth());
        textEdit_CardMark->setSizePolicy(sizePolicy2);
        textEdit_CardMark->setFont(font);

        gridLayout_2->addWidget(textEdit_CardMark, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_CardId = new QLineEdit(groupBox_2);
        lineEdit_CardId->setObjectName(QStringLiteral("lineEdit_CardId"));
        lineEdit_CardId->setFont(font);
        lineEdit_CardId->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_CardId);

        btn_Inventory = new QPushButton(groupBox_2);
        btn_Inventory->setObjectName(QStringLiteral("btn_Inventory"));
        btn_Inventory->setFont(font);

        horizontalLayout_2->addWidget(btn_Inventory);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Register = new QPushButton(groupBox_3);
        btn_Register->setObjectName(QStringLiteral("btn_Register"));
        btn_Register->setFont(font);

        horizontalLayout->addWidget(btn_Register);

        btn_Refresh = new QPushButton(groupBox_3);
        btn_Refresh->setObjectName(QStringLiteral("btn_Refresh"));
        btn_Refresh->setFont(font);
        btn_Refresh->setAutoDefault(false);

        horizontalLayout->addWidget(btn_Refresh);

        btn_Reset = new QPushButton(groupBox_3);
        btn_Reset->setObjectName(QStringLiteral("btn_Reset"));
        btn_Reset->setFont(font);

        horizontalLayout->addWidget(btn_Reset);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_2->addWidget(groupBox_3, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addWidget(frame);


        verticalLayout_2->addWidget(groupBox_4);

        tableView = new QTableView(RegistorWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);


        retranslateUi(RegistorWidget);

        QMetaObject::connectSlotsByName(RegistorWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistorWidget)
    {
        RegistorWidget->setWindowTitle(QApplication::translate("RegistorWidget", "Form", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("RegistorWidget", "\346\263\250\345\206\214\347\256\241\347\220\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RegistorWidget", "\350\272\253\344\273\275\344\277\241\346\201\257", Q_NULLPTR));
        comboBox_RoomType->clear();
        comboBox_RoomType->insertItems(0, QStringList()
         << QApplication::translate("RegistorWidget", "\346\240\207\345\207\206\345\217\214\345\272\212\346\210\277", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\350\261\252\345\215\216\345\217\214\345\272\212\346\210\277", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\346\240\207\345\207\206\345\244\247\345\272\212\346\210\277", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\350\261\252\345\215\216\345\244\247\345\272\212\346\210\277", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\346\200\273\347\273\237\345\245\227\346\210\277", Q_NULLPTR)
        );
        label_RoomType->setText(QApplication::translate("RegistorWidget", "\346\210\277\345\236\213\357\274\232", Q_NULLPTR));
        textEdit_PersonMark->setHtml(QApplication::translate("RegistorWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_checkInTime->setText(QApplication::translate("RegistorWidget", "\345\205\245\344\275\217\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_IdCard->setText(QApplication::translate("RegistorWidget", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        Label_PersonMark->setText(QApplication::translate("RegistorWidget", "\345\256\242\344\272\272\345\201\217\345\245\275\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("RegistorWidget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegistorWidget", "\346\210\277\345\217\267\357\274\232", Q_NULLPTR));
        label_checkOutTime->setText(QApplication::translate("RegistorWidget", "\351\200\200\346\210\277\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("RegistorWidget", "M1\345\215\241\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegistorWidget", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegistorWidget", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        btn_Inventory->setText(QApplication::translate("RegistorWidget", "\350\257\206\345\210\253", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        btn_Register->setText(QApplication::translate("RegistorWidget", "\346\263\250\345\206\214", Q_NULLPTR));
        btn_Refresh->setText(QApplication::translate("RegistorWidget", "\345\210\267\346\226\260\346\263\250\345\206\214\350\241\250", Q_NULLPTR));
        btn_Reset->setText(QApplication::translate("RegistorWidget", "\351\207\215\347\275\256\346\211\200\346\234\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegistorWidget: public Ui_RegistorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTORWIDGET_H
