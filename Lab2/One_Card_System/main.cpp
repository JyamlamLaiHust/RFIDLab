#include "mainwindow.h"
#include <QApplication>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: Qt应用程序的入口,此处可以初始化模块,加载一些耗时的模块,可以添加加载动画,类似Photoshop
***************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DB_Init();//数据库初始化
    w.show();
    return a.exec();
}
