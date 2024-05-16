/********************************************************************************
** Form generated from reading UI file 'writeoffperson.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITEOFFPERSON_H
#define UI_WRITEOFFPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WriteOffPerson
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_RoomId;
    QPushButton *btn_Inventory;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_Mark;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_LogOff;
    QPushButton *btn_Return;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *WriteOffPerson)
    {
        if (WriteOffPerson->objectName().isEmpty())
            WriteOffPerson->setObjectName(QStringLiteral("WriteOffPerson"));
        WriteOffPerson->resize(370, 161);
        horizontalLayout_3 = new QHBoxLayout(WriteOffPerson);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(WriteOffPerson);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit_RoomId = new QLineEdit(WriteOffPerson);
        lineEdit_RoomId->setObjectName(QStringLiteral("lineEdit_RoomId"));
        lineEdit_RoomId->setFont(font);

        horizontalLayout->addWidget(lineEdit_RoomId);

        btn_Inventory = new QPushButton(WriteOffPerson);
        btn_Inventory->setObjectName(QStringLiteral("btn_Inventory"));
        btn_Inventory->setEnabled(false);
        btn_Inventory->setFont(font);

        horizontalLayout->addWidget(btn_Inventory);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(WriteOffPerson);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        textEdit_Mark = new QTextEdit(WriteOffPerson);
        textEdit_Mark->setObjectName(QStringLiteral("textEdit_Mark"));
        textEdit_Mark->setFont(font);

        horizontalLayout_2->addWidget(textEdit_Mark);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_LogOff = new QPushButton(WriteOffPerson);
        btn_LogOff->setObjectName(QStringLiteral("btn_LogOff"));
        btn_LogOff->setFont(font);

        verticalLayout->addWidget(btn_LogOff);

        btn_Return = new QPushButton(WriteOffPerson);
        btn_Return->setObjectName(QStringLiteral("btn_Return"));
        btn_Return->setFont(font);

        verticalLayout->addWidget(btn_Return);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(WriteOffPerson);

        QMetaObject::connectSlotsByName(WriteOffPerson);
    } // setupUi

    void retranslateUi(QDialog *WriteOffPerson)
    {
        WriteOffPerson->setWindowTitle(QApplication::translate("WriteOffPerson", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("WriteOffPerson", "\346\210\277\345\217\267\357\274\232", Q_NULLPTR));
        btn_Inventory->setText(QApplication::translate("WriteOffPerson", "\350\257\206\345\210\253", Q_NULLPTR));
        label_2->setText(QApplication::translate("WriteOffPerson", "\345\216\237\345\233\240\357\274\232", Q_NULLPTR));
        btn_LogOff->setText(QApplication::translate("WriteOffPerson", "\351\200\200\346\210\277", Q_NULLPTR));
        btn_Return->setText(QApplication::translate("WriteOffPerson", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WriteOffPerson: public Ui_WriteOffPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEOFFPERSON_H
