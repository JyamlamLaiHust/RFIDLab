/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_login;
    QAction *actionquit;
    QAction *action_export;
    QAction *action_register;
    QAction *action_writeoff;
    QAction *action_changepwd;
    QAction *actionGhuj;
    QAction *action_recordtable;
    QAction *action_writeofftable;
    QAction *action_registtable;
    QAction *action_persontable;
    QAction *actionAsdf_7;
    QAction *action_about;
    QAction *action_connect;
    QAction *action_Disconnect;
    QAction *actionAsdf;
    QAction *action_recharge;
    QAction *action_consume;
    QAction *action_mainPage;
    QAction *action_recharges;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(780, 515);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        action_login = new QAction(MainWindow);
        action_login->setObjectName(QStringLiteral("action_login"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/login.png"), QSize(), QIcon::Normal, QIcon::On);
        action_login->setIcon(icon);
        action_login->setFont(font);
        actionquit = new QAction(MainWindow);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/logout.png"), QSize(), QIcon::Normal, QIcon::On);
        actionquit->setIcon(icon1);
        actionquit->setFont(font);
        action_export = new QAction(MainWindow);
        action_export->setObjectName(QStringLiteral("action_export"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/export.png"), QSize(), QIcon::Normal, QIcon::On);
        action_export->setIcon(icon2);
        action_export->setFont(font);
        action_register = new QAction(MainWindow);
        action_register->setObjectName(QStringLiteral("action_register"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/regester.png"), QSize(), QIcon::Normal, QIcon::On);
        action_register->setIcon(icon3);
        action_register->setFont(font);
        action_writeoff = new QAction(MainWindow);
        action_writeoff->setObjectName(QStringLiteral("action_writeoff"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/changePwd.png"), QSize(), QIcon::Normal, QIcon::On);
        action_writeoff->setIcon(icon4);
        action_writeoff->setFont(font);
        action_changepwd = new QAction(MainWindow);
        action_changepwd->setObjectName(QStringLiteral("action_changepwd"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/record3.png"), QSize(), QIcon::Normal, QIcon::On);
        action_changepwd->setIcon(icon5);
        action_changepwd->setFont(font);
        actionGhuj = new QAction(MainWindow);
        actionGhuj->setObjectName(QStringLiteral("actionGhuj"));
        action_recordtable = new QAction(MainWindow);
        action_recordtable->setObjectName(QStringLiteral("action_recordtable"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/record4.png"), QSize(), QIcon::Normal, QIcon::On);
        action_recordtable->setIcon(icon6);
        action_recordtable->setFont(font);
        action_writeofftable = new QAction(MainWindow);
        action_writeofftable->setObjectName(QStringLiteral("action_writeofftable"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/recoder1.png"), QSize(), QIcon::Normal, QIcon::On);
        action_writeofftable->setIcon(icon7);
        action_writeofftable->setFont(font);
        action_registtable = new QAction(MainWindow);
        action_registtable->setObjectName(QStringLiteral("action_registtable"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/record.png"), QSize(), QIcon::Normal, QIcon::On);
        action_registtable->setIcon(icon8);
        action_registtable->setFont(font);
        action_persontable = new QAction(MainWindow);
        action_persontable->setObjectName(QStringLiteral("action_persontable"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/record2.png"), QSize(), QIcon::Normal, QIcon::On);
        action_persontable->setIcon(icon9);
        action_persontable->setFont(font);
        actionAsdf_7 = new QAction(MainWindow);
        actionAsdf_7->setObjectName(QStringLiteral("actionAsdf_7"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/help.png"), QSize(), QIcon::Normal, QIcon::On);
        action_about->setIcon(icon10);
        action_about->setFont(font);
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QStringLiteral("action_connect"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/connect.png"), QSize(), QIcon::Normal, QIcon::On);
        action_connect->setIcon(icon11);
        action_connect->setFont(font);
        action_Disconnect = new QAction(MainWindow);
        action_Disconnect->setObjectName(QStringLiteral("action_Disconnect"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/disconnect.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Disconnect->setIcon(icon12);
        action_Disconnect->setFont(font);
        actionAsdf = new QAction(MainWindow);
        actionAsdf->setObjectName(QStringLiteral("actionAsdf"));
        action_recharge = new QAction(MainWindow);
        action_recharge->setObjectName(QStringLiteral("action_recharge"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/prefix1/cast.png"), QSize(), QIcon::Normal, QIcon::On);
        action_recharge->setIcon(icon13);
        action_recharge->setFont(font);
        action_consume = new QAction(MainWindow);
        action_consume->setObjectName(QStringLiteral("action_consume"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/prefix1/pay.png"), QSize(), QIcon::Normal, QIcon::On);
        action_consume->setIcon(icon14);
        action_consume->setFont(font);
        action_mainPage = new QAction(MainWindow);
        action_mainPage->setObjectName(QStringLiteral("action_mainPage"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/new/prefix1/main.png"), QSize(), QIcon::Normal, QIcon::On);
        action_mainPage->setIcon(icon15);
        action_mainPage->setFont(font);
        action_recharges = new QAction(MainWindow);
        action_recharges->setObjectName(QStringLiteral("action_recharges"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/new/prefix1/record5.png"), QSize(), QIcon::Normal, QIcon::On);
        action_recharges->setIcon(icon16);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFont(font);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 780, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(action_login);
        menu->addSeparator();
        menu->addAction(action_connect);
        menu->addAction(action_Disconnect);
        menu->addAction(action_export);
        menu->addSeparator();
        menu->addAction(action_mainPage);
        menu->addAction(actionquit);
        menu_2->addAction(action_register);
        menu_2->addAction(action_writeoff);
        menu_2->addAction(action_recharge);
        menu_2->addSeparator();
        menu_2->addAction(action_changepwd);
        menu_2->addSeparator();
        menu_2->addAction(action_consume);
        menu_3->addAction(action_writeofftable);
        menu_3->addAction(action_registtable);
        menu_3->addSeparator();
        menu_3->addAction(action_recordtable);
        menu_3->addAction(action_recharges);
        menu_3->addSeparator();
        menu_3->addAction(action_persontable);
        menu_4->addAction(action_about);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_login->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_login->setStatusTip(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225\346\216\245\345\217\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionquit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionquit->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_export->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_export->setStatusTip(QApplication::translate("MainWindow", "\345\260\206\346\225\260\346\215\256\350\241\250\346\240\274\345\257\274\345\207\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_register->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_register->setStatusTip(QApplication::translate("MainWindow", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_writeoff->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\263\250\351\224\200", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_writeoff->setStatusTip(QApplication::translate("MainWindow", "\346\263\250\351\224\200\350\264\246\346\210\267", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_changepwd->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_changepwd->setStatusTip(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\224\250\344\272\216\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionGhuj->setText(QApplication::translate("MainWindow", "ghuj", Q_NULLPTR));
        action_recordtable->setText(QApplication::translate("MainWindow", "\346\266\210\350\264\271\350\256\260\345\275\225", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_recordtable->setStatusTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\266\210\350\264\271\350\256\260\345\275\225\350\241\250", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_writeofftable->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200\350\256\260\345\275\225", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_writeofftable->setStatusTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\263\250\351\224\200\350\241\250", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_registtable->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\350\256\260\345\275\225", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_registtable->setStatusTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\263\250\345\206\214\350\241\250", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_persontable->setText(QApplication::translate("MainWindow", "\344\272\272\345\221\230\344\277\241\346\201\257", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_persontable->setStatusTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\263\250\345\206\214\347\224\250\346\210\267\350\241\250", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionAsdf_7->setText(QApplication::translate("MainWindow", "asdf", Q_NULLPTR));
        action_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_about->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\350\275\257\344\273\266\347\232\204\347\233\270\345\205\263\350\257\264\346\230\216", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_connect->setStatusTip(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\257\273\345\215\241\345\231\250\346\250\241\345\235\227", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_Disconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_Disconnect->setStatusTip(QApplication::translate("MainWindow", "\344\270\216\350\257\273\345\215\241\345\231\250\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionAsdf->setText(QApplication::translate("MainWindow", "asdf", Q_NULLPTR));
        action_recharge->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\205\205\345\200\274", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_recharge->setStatusTip(QApplication::translate("MainWindow", "\347\273\231M1\345\215\241\345\205\205\345\200\274", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_consume->setText(QApplication::translate("MainWindow", "\346\266\210\350\264\271\346\250\241\346\213\237", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_consume->setStatusTip(QApplication::translate("MainWindow", "\346\250\241\346\213\237\344\270\200\344\272\233\346\266\210\350\264\271\345\234\272\346\231\257", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_mainPage->setText(QApplication::translate("MainWindow", "\344\270\273\351\241\265", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_mainPage->setStatusTip(QApplication::translate("MainWindow", "\350\277\224\345\233\236\345\210\260\350\275\257\344\273\266\347\232\204\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        action_recharges->setText(QApplication::translate("MainWindow", "\345\205\205\345\200\274\350\256\260\345\275\225", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_recharges->setStatusTip(QApplication::translate("MainWindow", "\345\205\205\345\200\274\350\256\260\345\275\225\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        menu->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\256\260\345\275\225\346\237\245\350\257\242", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
