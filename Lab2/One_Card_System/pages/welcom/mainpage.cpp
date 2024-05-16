#include "mainpage.h"
#include "ui_mainpage.h"
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 默认主页,显示一张图片,无其他相关操作
***************************************/
MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}
