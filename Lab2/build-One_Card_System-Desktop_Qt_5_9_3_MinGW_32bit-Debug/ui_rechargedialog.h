/********************************************************************************
** Form generated from reading UI file 'rechargedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHARGEDIALOG_H
#define UI_RECHARGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_RechargeDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_View_2;
    QLabel *label_currentValue;
    QLabel *label_View_3;
    QLabel *label_chargeValue;
    QLabel *label_View_5;
    QLabel *label_lastValue;
    QLabel *labelMessage;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEdit_cardId;
    QPushButton *btn_inventory;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_clear;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *lineEdit_money;
    QPushButton *btn_recharge;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_return;

    void setupUi(QDialog *RechargeDialog)
    {
        if (RechargeDialog->objectName().isEmpty())
            RechargeDialog->setObjectName(QStringLiteral("RechargeDialog"));
        RechargeDialog->resize(500, 280);
        RechargeDialog->setMaximumSize(QSize(500, 280));
        gridLayout = new QGridLayout(RechargeDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(RechargeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_View_2 = new QLabel(groupBox);
        label_View_2->setObjectName(QStringLiteral("label_View_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(16);
        label_View_2->setFont(font1);
        label_View_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_View_2, 0, 0, 1, 1);

        label_currentValue = new QLabel(groupBox);
        label_currentValue->setObjectName(QStringLiteral("label_currentValue"));
        label_currentValue->setFont(font1);
        label_currentValue->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_currentValue, 0, 1, 1, 1);

        label_View_3 = new QLabel(groupBox);
        label_View_3->setObjectName(QStringLiteral("label_View_3"));
        label_View_3->setFont(font1);
        label_View_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_View_3, 1, 0, 1, 1);

        label_chargeValue = new QLabel(groupBox);
        label_chargeValue->setObjectName(QStringLiteral("label_chargeValue"));
        label_chargeValue->setFont(font1);
        label_chargeValue->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_chargeValue, 1, 1, 1, 1);

        label_View_5 = new QLabel(groupBox);
        label_View_5->setObjectName(QStringLiteral("label_View_5"));
        label_View_5->setFont(font1);
        label_View_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_View_5, 2, 0, 1, 1);

        label_lastValue = new QLabel(groupBox);
        label_lastValue->setObjectName(QStringLiteral("label_lastValue"));
        label_lastValue->setFont(font1);
        label_lastValue->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_lastValue, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        labelMessage = new QLabel(groupBox);
        labelMessage->setObjectName(QStringLiteral("labelMessage"));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(18);
        labelMessage->setFont(font2);
        labelMessage->setScaledContents(false);
        labelMessage->setAlignment(Qt::AlignCenter);
        labelMessage->setWordWrap(true);

        gridLayout_3->addWidget(labelMessage, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label = new QLabel(RechargeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        lineEdit_cardId = new QLineEdit(RechargeDialog);
        lineEdit_cardId->setObjectName(QStringLiteral("lineEdit_cardId"));
        lineEdit_cardId->setFont(font);
        lineEdit_cardId->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_cardId);

        btn_inventory = new QPushButton(RechargeDialog);
        btn_inventory->setObjectName(QStringLiteral("btn_inventory"));
        btn_inventory->setFont(font);

        horizontalLayout_3->addWidget(btn_inventory);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        btn_clear = new QPushButton(RechargeDialog);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setFont(font);

        horizontalLayout_4->addWidget(btn_clear);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(RechargeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_money = new QLineEdit(RechargeDialog);
        lineEdit_money->setObjectName(QStringLiteral("lineEdit_money"));
        lineEdit_money->setFont(font);
        lineEdit_money->setMaxLength(6);
        lineEdit_money->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_money);

        btn_recharge = new QPushButton(RechargeDialog);
        btn_recharge->setObjectName(QStringLiteral("btn_recharge"));
        btn_recharge->setFont(font);

        horizontalLayout_2->addWidget(btn_recharge);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        btn_return = new QPushButton(RechargeDialog);
        btn_return->setObjectName(QStringLiteral("btn_return"));
        btn_return->setFont(font);

        horizontalLayout_5->addWidget(btn_return);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 6);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);

        retranslateUi(RechargeDialog);

        QMetaObject::connectSlotsByName(RechargeDialog);
    } // setupUi

    void retranslateUi(QDialog *RechargeDialog)
    {
        RechargeDialog->setWindowTitle(QApplication::translate("RechargeDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RechargeDialog", "\346\230\276\347\244\272\347\252\227\345\217\243", Q_NULLPTR));
        label_View_2->setText(QApplication::translate("RechargeDialog", "\345\275\223\345\211\215\344\275\231\351\242\235:", Q_NULLPTR));
        label_currentValue->setText(QApplication::translate("RechargeDialog", "0.00 \345\205\203", Q_NULLPTR));
        label_View_3->setText(QApplication::translate("RechargeDialog", "\345\205\205\345\200\274\351\207\221\351\242\235:", Q_NULLPTR));
        label_chargeValue->setText(QApplication::translate("RechargeDialog", "0.00 \345\205\203", Q_NULLPTR));
        label_View_5->setText(QApplication::translate("RechargeDialog", "\346\234\200\347\273\210\344\275\231\351\242\235:", Q_NULLPTR));
        label_lastValue->setText(QApplication::translate("RechargeDialog", "0.00 \345\205\203", Q_NULLPTR));
        labelMessage->setText(QString());
        label->setText(QApplication::translate("RechargeDialog", "\345\215\241\345\217\267:", Q_NULLPTR));
        btn_inventory->setText(QApplication::translate("RechargeDialog", "\350\257\206\345\210\253", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("RechargeDialog", "\346\270\205\351\231\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("RechargeDialog", "\351\207\221\351\242\235:", Q_NULLPTR));
        btn_recharge->setText(QApplication::translate("RechargeDialog", "\345\205\205\345\200\274", Q_NULLPTR));
        btn_return->setText(QApplication::translate("RechargeDialog", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RechargeDialog: public Ui_RechargeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHARGEDIALOG_H
