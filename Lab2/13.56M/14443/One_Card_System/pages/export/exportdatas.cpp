#include "exportdatas.h"
#include "ui_exportdatas.h"
#include "database/dbmanager.h"
#include "tools/tools.h"
#include <QMessageBox>

/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 导出sql数据表到文本文件,可以使用excel打开
***************************************/
ExportDatas::ExportDatas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDatas)
{
    ui->setupUi(this);
    ui->comboBox->addItems(getTableNames());

}

ExportDatas::~ExportDatas()
{
    delete ui;
}
/**
 * @brief ExportDatas::on_btn_export_clicked
 * 导出按钮点击事件
 */
void ExportDatas::on_btn_export_clicked()
{
    if(export_table(ui->comboBox->currentText()))//调用导出方法
    {
        QMessageBox::information(this,tr("温馨提示"),ui->comboBox->currentText() + tr("保存成功"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this,tr("温馨提示"),ui->comboBox->currentText() + tr("保存失败！"),QMessageBox::Ok);
    }
}
/**
 * @brief ExportDatas::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void ExportDatas::on_btn_Return_clicked()
{
    this->close();
}
