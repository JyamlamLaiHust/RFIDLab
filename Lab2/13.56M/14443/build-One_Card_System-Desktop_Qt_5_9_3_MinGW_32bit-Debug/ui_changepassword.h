/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_Name;
    QLabel *label_2;
    QLineEdit *lineEdit_Pwd;
    QLabel *label_3;
    QLineEdit *lineEdit_NewPwd;
    QLabel *label_4;
    QLineEdit *lineEdit_EnsureNewPwd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Return;
    QPushButton *btn_Modify;

    void setupUi(QDialog *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QStringLiteral("ChangePassword"));
        ChangePassword->resize(207, 149);
        ChangePassword->setMaximumSize(QSize(280, 150));
        verticalLayout = new QVBoxLayout(ChangePassword);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ChangePassword);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        font.setItalic(false);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_Name = new QLineEdit(ChangePassword);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));
        lineEdit_Name->setFont(font);

        gridLayout->addWidget(lineEdit_Name, 0, 1, 1, 1);

        label_2 = new QLabel(ChangePassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_Pwd = new QLineEdit(ChangePassword);
        lineEdit_Pwd->setObjectName(QStringLiteral("lineEdit_Pwd"));
        lineEdit_Pwd->setFont(font);
        lineEdit_Pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Pwd, 1, 1, 1, 1);

        label_3 = new QLabel(ChangePassword);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_NewPwd = new QLineEdit(ChangePassword);
        lineEdit_NewPwd->setObjectName(QStringLiteral("lineEdit_NewPwd"));
        lineEdit_NewPwd->setFont(font);
        lineEdit_NewPwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_NewPwd, 2, 1, 1, 1);

        label_4 = new QLabel(ChangePassword);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_EnsureNewPwd = new QLineEdit(ChangePassword);
        lineEdit_EnsureNewPwd->setObjectName(QStringLiteral("lineEdit_EnsureNewPwd"));
        lineEdit_EnsureNewPwd->setFont(font);
        lineEdit_EnsureNewPwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_EnsureNewPwd, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Return = new QPushButton(ChangePassword);
        btn_Return->setObjectName(QStringLiteral("btn_Return"));
        btn_Return->setFont(font);

        horizontalLayout->addWidget(btn_Return);

        btn_Modify = new QPushButton(ChangePassword);
        btn_Modify->setObjectName(QStringLiteral("btn_Modify"));
        btn_Modify->setFont(font);

        horizontalLayout->addWidget(btn_Modify);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QDialog *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChangePassword", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangePassword", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangePassword", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChangePassword", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btn_Return->setText(QApplication::translate("ChangePassword", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_Modify->setText(QApplication::translate("ChangePassword", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
