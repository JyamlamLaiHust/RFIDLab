#include "mainwindow.h"
#include <QApplication>
/**
 * @brief main
 * @param argc
 * @param argv
 * @return exit时的代码
 * Qt应用程序的入口
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
