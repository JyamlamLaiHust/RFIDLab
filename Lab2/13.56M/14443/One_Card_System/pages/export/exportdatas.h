#ifndef EXPORTDATAS_H
#define EXPORTDATAS_H

#include <QDialog>

namespace Ui {
class ExportDatas;
}
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 数据库表导出到文本文档中,存储为*.CSV,可以使用excel打开
***************************************/
class ExportDatas : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDatas(QWidget *parent = 0);
    ~ExportDatas();

private slots:
    void on_btn_export_clicked();//导出

    void on_btn_Return_clicked();//返回

private:
    Ui::ExportDatas *ui;
};

#endif // EXPORTDATAS_H
