#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include <QString>
#include <QDate>
#include <QDateTime>
#include <QAbstractItemModel>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QVariant>
class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = 0);
    QStringList getSerialName();
    QString CurrentDateTime();
    QString CurrentTime();
    QString CurrentMTime();
    QString CharStringtoHexString(QString space,const char * src,int len);
    QString CharStringtoHexString(QString space,const char * src,int start,int end);
    quint8 StringToHex(QString string, quint8 *hex);
    void export_table(const QAbstractItemModel &model);

private:
    QStringList *list;
signals:

public slots:
};

#endif // TOOLS_H
