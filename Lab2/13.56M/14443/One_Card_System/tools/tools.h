#ifndef TOOLS_H
#define TOOLS_H
#include <QString>
#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QCryptographicHash>
#include <QByteArray>
#include <QSqlTableModel>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
//定义版本号
#define CURRENT_VERSION "一卡通管理系统 V1.0"
//获取当前日期和时间字符串
extern QString CurrentDateTime();
//将原字符串进行MD5编码
extern QString GetMD5String(QString src);
//导出表格到文件
extern bool export_table(const QString tableName);
//字符串转十六进制字节数组
extern quint8 StringToHex(QString string, quint8 *hex);
//QString 转十六进制数组
extern void QSTRING_TO_HEX(const QString &str, quint8 *buf, quint8 len);
//普通字符串转为16进制字符串
extern QString  CharStringtoHexString(QString space, const char * src, int start, int end);
//普通字符串转为16进制字符串
extern QString  CharStringtoHexString(QString space, const char * src, int len);
//获取当前的时间
extern QString CurrentTime();
//获取当前的时间到毫秒
extern QString CurrentMTime();
//获取当前PC的串口名
extern QStringList getSerialName();
#endif // TOOLS_H
