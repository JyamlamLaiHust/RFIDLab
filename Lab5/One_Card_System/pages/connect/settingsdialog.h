#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 串口配置
***************************************/
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };//缓存串口配置信息

    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    Settings settings() const;

signals:
    void applySettings();//apply信号

private slots:
    void showPortInfo(int idx);//处理显示串口信息
    void apply();//apply
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);

    void on_btn_Refresh_clicked();//刷新

private:
    void fillPortsParameters();//填充串口参数
    void fillPortsInfo();//填充串口
    void updateSettings();//更新串口配置

private:
    Ui::SettingsDialog *ui;
    Settings currentSettings;//存储当前的配置信息
    QIntValidator *intValidator;//Int Validator
};

#endif // SETTINGSDIALOG_H
