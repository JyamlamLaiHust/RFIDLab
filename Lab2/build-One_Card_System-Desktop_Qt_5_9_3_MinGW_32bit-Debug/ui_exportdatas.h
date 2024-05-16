/********************************************************************************
** Form generated from reading UI file 'exportdatas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDATAS_H
#define UI_EXPORTDATAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExportDatas
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Return;
    QPushButton *btn_export;

    void setupUi(QDialog *ExportDatas)
    {
        if (ExportDatas->objectName().isEmpty())
            ExportDatas->setObjectName(QStringLiteral("ExportDatas"));
        ExportDatas->resize(348, 146);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExportDatas->sizePolicy().hasHeightForWidth());
        ExportDatas->setSizePolicy(sizePolicy);
        ExportDatas->setMaximumSize(QSize(400, 200));
        verticalLayout = new QVBoxLayout(ExportDatas);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ExportDatas);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(ExportDatas);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(ExportDatas);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_Return = new QPushButton(ExportDatas);
        btn_Return->setObjectName(QStringLiteral("btn_Return"));
        btn_Return->setFont(font);

        horizontalLayout_2->addWidget(btn_Return);

        btn_export = new QPushButton(ExportDatas);
        btn_export->setObjectName(QStringLiteral("btn_export"));
        btn_export->setFont(font);

        horizontalLayout_2->addWidget(btn_export);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ExportDatas);

        QMetaObject::connectSlotsByName(ExportDatas);
    } // setupUi

    void retranslateUi(QDialog *ExportDatas)
    {
        ExportDatas->setWindowTitle(QApplication::translate("ExportDatas", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ExportDatas", "\350\241\250\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ExportDatas", "\346\217\220\347\244\272\357\274\232\345\257\274\345\207\272\344\270\272csv\346\240\274\345\274\217\346\226\207\346\234\254\346\226\207\344\273\266\357\274\214\345\217\257\344\273\245\344\275\277\347\224\250excel\347\233\264\346\216\245\346\211\223\345\274\200", Q_NULLPTR));
        btn_Return->setText(QApplication::translate("ExportDatas", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_export->setText(QApplication::translate("ExportDatas", "\345\257\274\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExportDatas: public Ui_ExportDatas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDATAS_H
