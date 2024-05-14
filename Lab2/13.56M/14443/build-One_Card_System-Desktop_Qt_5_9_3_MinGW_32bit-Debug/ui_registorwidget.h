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
    QLineEdit *lineEdit_Name;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboBox_UserType;
    QTextEdit *textEdit_PersonMark;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_CardId;
    QPushButton *btn_Inventory;
    QLabel *label_6;
    QTextEdit *textEdit_CardMark;
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
        RegistorWidget->resize(686, 541);
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 200));
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
        lineEdit_Name = new QLineEdit(groupBox);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));
        lineEdit_Name->setFont(font);

        gridLayout->addWidget(lineEdit_Name, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_UserType = new QComboBox(groupBox);
        comboBox_UserType->setObjectName(QStringLiteral("comboBox_UserType"));
        comboBox_UserType->setFont(font);

        gridLayout->addWidget(comboBox_UserType, 1, 2, 1, 1);

        textEdit_PersonMark = new QTextEdit(groupBox);
        textEdit_PersonMark->setObjectName(QStringLiteral("textEdit_PersonMark"));
        textEdit_PersonMark->setFont(font);

        gridLayout->addWidget(textEdit_PersonMark, 2, 2, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(330, 0));
        groupBox_2->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

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

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        textEdit_CardMark = new QTextEdit(groupBox_2);
        textEdit_CardMark->setObjectName(QStringLiteral("textEdit_CardMark"));
        textEdit_CardMark->setFont(font);

        gridLayout_2->addWidget(textEdit_CardMark, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
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

        horizontalLayout->addWidget(btn_Refresh);

        btn_Reset = new QPushButton(groupBox_3);
        btn_Reset->setObjectName(QStringLiteral("btn_Reset"));
        btn_Reset->setFont(font);

        horizontalLayout->addWidget(btn_Reset);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addWidget(frame);

        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFont(font);

        verticalLayout_3->addWidget(tableView);


        verticalLayout_2->addWidget(groupBox_4);


        retranslateUi(RegistorWidget);

        QMetaObject::connectSlotsByName(RegistorWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistorWidget)
    {
        RegistorWidget->setWindowTitle(QApplication::translate("RegistorWidget", "Form", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("RegistorWidget", "\346\263\250\345\206\214\347\256\241\347\220\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RegistorWidget", "\350\272\253\344\273\275\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("RegistorWidget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegistorWidget", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegistorWidget", "\350\272\253\344\273\275\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        comboBox_UserType->clear();
        comboBox_UserType->insertItems(0, QStringList()
         << QApplication::translate("RegistorWidget", "\346\231\256\351\200\232\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\346\231\256\351\200\232\350\200\201\345\270\210", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "\347\256\241\347\220\206\350\200\201\345\270\210", Q_NULLPTR)
         << QApplication::translate("RegistorWidget", "custom", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("RegistorWidget", "M1\345\215\241\344\277\241\346\201\257", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegistorWidget", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        btn_Inventory->setText(QApplication::translate("RegistorWidget", "\350\257\206\345\210\253", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegistorWidget", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
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
