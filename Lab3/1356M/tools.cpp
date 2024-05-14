#include "tools.h"
#include <QDebug>

Tools::Tools(QObject *parent) : QObject(parent)
{
    list = new QStringList();
}
//获取当前PC可用的串口名
QStringList Tools::getSerialName()
{
    QStringList temp;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
      {
          QSerialPort serial;
          serial.setPort(info);
          if (serial.open(QIODevice::ReadWrite))
          {
              if(! list->contains(info.portName(),Qt::CaseSensitive))
                  list->insert(0,info.portName());
              serial.close();
              temp << info.portName();
          }
      }
    for(int i = 0 ; i < list->size() ; i ++)
    {
        if(!temp.contains(list->at(i)))
            list->removeAt(i);
    }
    return *list;
}

///获取当前日期和时间
QString Tools::CurrentDateTime()
{
    QDateTime dt;
    QTime time;
    QDate date;

    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    return dt.toString("yyyy-MM-dd hh:mm:ss");
}
///获取当前的时间
QString Tools::CurrentTime()
{
    QTime time;
    return time.currentTime().toString("hh:mm:ss");
}
///获取当前的时间
QString Tools::CurrentMTime()
{
    QTime time;
    return time.currentTime().toString("hh:mm:ss.zzz");
}
///普通字符串转为16进制字符串
QString  Tools::CharStringtoHexString(QString space, const char * src, int len)
{
    QString hex = "";
    if(space == NULL)
    {
        for(int i = 0 ; i < len ; i ++)
        {
            hex += QString("%1").arg(src[i]&0xFF,2,16,QLatin1Char('0'));
        }
        return hex.toUpper();
    }
    else
    {
        for(int i = 0 ; i < len ; i ++)
        {
            hex += space + QString("%1").arg(src[i]&0xFF,2,16,QLatin1Char('0'));
        }
        return hex.right(hex.length() - space.length()).toUpper();
    }
}
//QString 转 Hex char *
quint8 Tools::StringToHex(QString string, quint8 *hex)
{
    QString temp;
    quint8 len = string.length();

    for(quint8 i=0; i<len; i+=2)
    {
         temp = string.mid(i, 2);
         hex[i/2] = (quint8)temp.toInt(0,16);
    }

    return len/2;
}
///普通字符串转为16进制字符串
QString  Tools::CharStringtoHexString(QString space, const char * src, int start, int end)
{
    QString hex = "";
    if(space == NULL)
    {
        for(int i = start ; i < end ; i ++)
        {
            hex += QString("%1").arg(src[i]&0xFF,2,16,QLatin1Char('0'));
        }
        return hex.toUpper();
    }
    else
    {
        for(int i = start ; i < end ; i ++)
        {
            hex += space + QString("%1").arg(src[i]&0xFF,2,16,QLatin1Char('0'));
        }
        return hex.right(hex.length() - space.length()).toUpper();
    }
}

//用于导出数据库中的数据到文件，csv格式的文件可以用Excel打开
void Tools::export_table(const QAbstractItemModel &model)
{
    QString fileName = QFileDialog::getSaveFileName(0, QObject::tr("保存记录"), "/", "files(*.csv)");
    QFile file(fileName);
    if(file.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream out(&file);
        QString str;
        str.clear();
        for(int i=0; i<model.columnCount(); i++)
            str.append(model.headerData(i, Qt::Horizontal).toString()).append(",");
        out<<str<<"\r\n";
        for(int row=0; row<model.rowCount(); row++){
            str.clear();
            for(int col=0; col<model.columnCount(); col++)
                str.append(model.data(model.index(row,col)).toString()).append(",");
            out<<str<<"\r\n";
        }
        file.close();
    }
}
