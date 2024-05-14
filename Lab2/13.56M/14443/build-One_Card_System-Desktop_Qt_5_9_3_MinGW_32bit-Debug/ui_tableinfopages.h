/********************************************************************************
** Form generated from reading UI file 'tableinfopages.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEINFOPAGES_H
#define UI_TABLEINFOPAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableInfoPages
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDateTimeEdit *dtEditStart;
    QLabel *label_5;
    QDateTimeEdit *dtEditEnd;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *btn_Enventory;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *btn_Query;
    QTableView *tableView;

    void setupUi(QWidget *TableInfoPages)
    {
        if (TableInfoPages->objectName().isEmpty())
            TableInfoPages->setObjectName(QStringLiteral("TableInfoPages"));
        TableInfoPages->resize(737, 690);
        horizontalLayout_2 = new QHBoxLayout(TableInfoPages);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(TableInfoPages);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        groupBox_2->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_3->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        dtEditStart = new QDateTimeEdit(page);
        dtEditStart->setObjectName(QStringLiteral("dtEditStart"));

        horizontalLayout->addWidget(dtEditStart);

        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        dtEditEnd = new QDateTimeEdit(page);
        dtEditEnd->setObjectName(QStringLiteral("dtEditEnd"));

        horizontalLayout->addWidget(dtEditEnd);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(1, 1, 1, 1);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        btn_Enventory = new QPushButton(page_2);
        btn_Enventory->setObjectName(QStringLiteral("btn_Enventory"));

        horizontalLayout_4->addWidget(btn_Enventory);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout_5 = new QHBoxLayout(page_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(1, 1, 1, 1);
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_5->addWidget(lineEdit_2);

        stackedWidget->addWidget(page_3);

        horizontalLayout_3->addWidget(stackedWidget);

        btn_Query = new QPushButton(groupBox);
        btn_Query->setObjectName(QStringLiteral("btn_Query"));
        btn_Query->setFont(font);

        horizontalLayout_3->addWidget(btn_Query);


        verticalLayout->addWidget(groupBox);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFont(font);

        verticalLayout->addWidget(tableView);


        horizontalLayout_2->addWidget(groupBox_2);


        retranslateUi(TableInfoPages);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TableInfoPages);
    } // setupUi

    void retranslateUi(QWidget *TableInfoPages)
    {
        TableInfoPages->setWindowTitle(QApplication::translate("TableInfoPages", "Form", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TableInfoPages", "\350\256\260\345\275\225\346\237\245\350\257\242\347\252\227\345\217\243", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TableInfoPages", "\346\235\241\344\273\266\351\200\211\346\213\251", Q_NULLPTR));
        label->setText(QApplication::translate("TableInfoPages", "\346\237\245\350\257\242\344\276\235\346\215\256\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("TableInfoPages", "\345\274\200\345\247\213\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("TableInfoPages", "\347\273\223\346\235\237\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("TableInfoPages", "\345\215\241\345\217\267=", Q_NULLPTR));
        btn_Enventory->setText(QApplication::translate("TableInfoPages", "\350\257\206\345\210\253", Q_NULLPTR));
        label_3->setText(QApplication::translate("TableInfoPages", "\345\247\223\345\220\215 = ", Q_NULLPTR));
        btn_Query->setText(QApplication::translate("TableInfoPages", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TableInfoPages: public Ui_TableInfoPages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEINFOPAGES_H
