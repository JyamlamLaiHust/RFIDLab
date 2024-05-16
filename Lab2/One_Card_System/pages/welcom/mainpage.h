#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

namespace Ui {
class MainPage;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 主页面
***************************************/
class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
