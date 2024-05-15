/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *serialPortInfoListBox;
    QPushButton *btn_Refresh;
    QLabel *serialNumberLabel;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *parametersBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Apply;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(607, 346);
        SettingsDialog->setMaximumSize(QSize(1920, 1080));
        horizontalLayout_3 = new QHBoxLayout(SettingsDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectBox->sizePolicy().hasHeightForWidth());
        selectBox->setSizePolicy(sizePolicy);
        selectBox->setMinimumSize(QSize(180, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        selectBox->setFont(font);
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));
        serialPortInfoListBox->setFont(font);

        horizontalLayout_2->addWidget(serialPortInfoListBox);

        btn_Refresh = new QPushButton(selectBox);
        btn_Refresh->setObjectName(QStringLiteral("btn_Refresh"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_Refresh->sizePolicy().hasHeightForWidth());
        btn_Refresh->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btn_Refresh);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QStringLiteral("serialNumberLabel"));
        serialNumberLabel->setFont(font);

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setFont(font);

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));
        manufacturerLabel->setFont(font);

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));
        locationLabel->setFont(font);

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));
        vidLabel->setFont(font);

        gridLayout->addWidget(vidLabel, 5, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));
        pidLabel->setFont(font);

        gridLayout->addWidget(pidLabel, 6, 0, 1, 1);


        horizontalLayout_3->addWidget(selectBox);

        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(parametersBox->sizePolicy().hasHeightForWidth());
        parametersBox->setSizePolicy(sizePolicy2);
        parametersBox->setFont(font);
        verticalLayout = new QVBoxLayout(parametersBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));
        baudRateLabel->setFont(font);

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));
        baudRateBox->setFont(font);

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));
        dataBitsLabel->setFont(font);

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));
        dataBitsBox->setFont(font);

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));
        parityLabel->setFont(font);

        gridLayout_2->addWidget(parityLabel, 2, 0, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        parityBox->setFont(font);

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));
        stopBitsLabel->setFont(font);

        gridLayout_2->addWidget(stopBitsLabel, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));
        stopBitsBox->setFont(font);

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));
        flowControlLabel->setFont(font);

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));
        flowControlBox->setFont(font);

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Apply = new QPushButton(parametersBox);
        btn_Apply->setObjectName(QStringLiteral("btn_Apply"));
        btn_Apply->setFont(font);

        horizontalLayout->addWidget(btn_Apply);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(parametersBox);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", Q_NULLPTR));
        selectBox->setTitle(QApplication::translate("SettingsDialog", "\344\270\262\345\217\243\351\200\211\346\213\251", Q_NULLPTR));
        btn_Refresh->setText(QApplication::translate("SettingsDialog", "\345\210\267\346\226\260", Q_NULLPTR));
        serialNumberLabel->setText(QApplication::translate("SettingsDialog", "\345\272\217\345\210\227\345\217\267:", Q_NULLPTR));
        descriptionLabel->setText(QApplication::translate("SettingsDialog", "\346\217\217\350\277\260:", Q_NULLPTR));
        manufacturerLabel->setText(QApplication::translate("SettingsDialog", "\345\210\266\351\200\240\345\225\206:", Q_NULLPTR));
        locationLabel->setText(QApplication::translate("SettingsDialog", "\344\275\215\347\275\256:", Q_NULLPTR));
        vidLabel->setText(QApplication::translate("SettingsDialog", "\345\216\202\345\225\206\346\240\207\350\257\206:", Q_NULLPTR));
        pidLabel->setText(QApplication::translate("SettingsDialog", "\344\272\247\345\223\201ID:", Q_NULLPTR));
        parametersBox->setTitle(QApplication::translate("SettingsDialog", "\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR));
        baudRateLabel->setText(QApplication::translate("SettingsDialog", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        dataBitsLabel->setText(QApplication::translate("SettingsDialog", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("SettingsDialog", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("SettingsDialog", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        flowControlLabel->setText(QApplication::translate("SettingsDialog", "\346\265\201  \346\216\247\357\274\232", Q_NULLPTR));
        btn_Apply->setText(QApplication::translate("SettingsDialog", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
