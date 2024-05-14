/********************************************************************************
** Form generated from reading UI file 'dialogcardconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCARDCONFIG_H
#define UI_DIALOGCARDCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCardConfig
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonA;
    QRadioButton *radioButtonB;
    QLineEdit *lineEdit_Pwd;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *initValue;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditMemData;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Init;
    QPushButton *btn_MemData;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Return;

    void setupUi(QDialog *DialogCardConfig)
    {
        if (DialogCardConfig->objectName().isEmpty())
            DialogCardConfig->setObjectName(QStringLiteral("DialogCardConfig"));
        DialogCardConfig->resize(422, 139);
        DialogCardConfig->setMaximumSize(QSize(500, 200));
        verticalLayout = new QVBoxLayout(DialogCardConfig);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButtonA = new QRadioButton(DialogCardConfig);
        radioButtonA->setObjectName(QStringLiteral("radioButtonA"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        radioButtonA->setFont(font);

        horizontalLayout_2->addWidget(radioButtonA);

        radioButtonB = new QRadioButton(DialogCardConfig);
        radioButtonB->setObjectName(QStringLiteral("radioButtonB"));
        radioButtonB->setFont(font);

        horizontalLayout_2->addWidget(radioButtonB);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        lineEdit_Pwd = new QLineEdit(DialogCardConfig);
        lineEdit_Pwd->setObjectName(QStringLiteral("lineEdit_Pwd"));
        lineEdit_Pwd->setFont(font);

        horizontalLayout_3->addWidget(lineEdit_Pwd);

        checkBox = new QCheckBox(DialogCardConfig);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(DialogCardConfig);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        initValue = new QLineEdit(DialogCardConfig);
        initValue->setObjectName(QStringLiteral("initValue"));
        initValue->setFont(font);

        horizontalLayout_4->addWidget(initValue);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        lineEditMemData = new QLineEdit(DialogCardConfig);
        lineEditMemData->setObjectName(QStringLiteral("lineEditMemData"));
        lineEditMemData->setFont(font);
        lineEditMemData->setReadOnly(true);

        verticalLayout->addWidget(lineEditMemData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_Init = new QPushButton(DialogCardConfig);
        btn_Init->setObjectName(QStringLiteral("btn_Init"));
        btn_Init->setFont(font);

        horizontalLayout->addWidget(btn_Init);

        btn_MemData = new QPushButton(DialogCardConfig);
        btn_MemData->setObjectName(QStringLiteral("btn_MemData"));
        btn_MemData->setFont(font);

        horizontalLayout->addWidget(btn_MemData);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_Return = new QPushButton(DialogCardConfig);
        btn_Return->setObjectName(QStringLiteral("btn_Return"));
        btn_Return->setFont(font);

        horizontalLayout->addWidget(btn_Return);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogCardConfig);

        QMetaObject::connectSlotsByName(DialogCardConfig);
    } // setupUi

    void retranslateUi(QDialog *DialogCardConfig)
    {
        DialogCardConfig->setWindowTitle(QApplication::translate("DialogCardConfig", "Dialog", Q_NULLPTR));
        radioButtonA->setText(QApplication::translate("DialogCardConfig", "\347\247\230\351\222\245A", Q_NULLPTR));
        radioButtonB->setText(QApplication::translate("DialogCardConfig", "\347\247\230\351\222\245B", Q_NULLPTR));
        lineEdit_Pwd->setText(QString());
        checkBox->setText(QApplication::translate("DialogCardConfig", "\346\230\276\347\244\272\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("DialogCardConfig", "\345\210\235\345\247\213\345\214\226\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        btn_Init->setText(QApplication::translate("DialogCardConfig", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        btn_MemData->setText(QApplication::translate("DialogCardConfig", "\346\237\245\347\234\213\345\206\205\345\255\230", Q_NULLPTR));
        btn_Return->setText(QApplication::translate("DialogCardConfig", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCardConfig: public Ui_DialogCardConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCARDCONFIG_H
