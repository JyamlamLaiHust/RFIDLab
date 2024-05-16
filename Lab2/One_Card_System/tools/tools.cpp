/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 采用C的方式写的一些工具类方法
***************************************/
#include "tools.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
static QStringList list;
///获取当前日期和时间
QString CurrentDateTime()
{
    QDateTime dt;
    QTime time;
    QDate date;
    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    return dt.toString("yyyy-MM-dd hh:mm:ss");
}
/**
 * @param src 用户输入的字符串
 * @return MD5字符串
 * MD5加密
 */
QString GetMD5String(QString src)
{
    QString result;
    QByteArray ba;
    ba = QCryptographicHash::hash(src.toLatin1(), QCryptographicHash::Md5);
    result.append(ba.toHex());
    return result;
}
///获取当前的时间
QString CurrentTime()
{
    QTime time;
    return time.currentTime().toString("hh:mm:ss");
}
///获取当前的时间
QString CurrentMTime()
{
    QTime time;
    return time.currentTime().toString("hh:mm:ss.zzz");
}
///普通字符串转为16进制字符串
QString  CharStringtoHexString(QString space, const char * src, int len)
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
quint8 StringToHex(QString string, quint8 *hex)
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

/**
 * @brief QSTRING_TO_HEX
 * @param str QString指针
 * @param buf 字节数组指针
 * @param len 要转化的长度
 * QString 转十六进制数组
 */
void QSTRING_TO_HEX(const QString &str, quint8 *buf, quint8 len)
{
    quint8 strlen = ((quint8)str.count()+1)/2;
    quint8 buflen = (strlen>len) ? len : strlen;
    QString strHex;
    for(quint8 i=0; i<buflen; i++){
        strHex = str.mid((i<<1), 2);
        buf[i] = (quint8)(strHex.toInt(0, 16));
    }
}
///普通字符串转为16进制字符串
QString  CharStringtoHexString(QString space, const char * src, int start, int end)
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
bool export_table(const QString tableName)
{
    bool result = false;
    QString fileName = QFileDialog::getSaveFileName(0, QObject::tr("保存记录"), "/", "files(*.csv)");
    QSqlTableModel *exportModel = new QSqlTableModel();
    exportModel->setTable(tableName);
    exportModel->select();
    QStringList strList;//记录数据库中的一行报警数据
    QString strString;
    QFile csvFile(fileName);
    if (csvFile.open(QIODevice::ReadWrite))
    {
        for (int i=0;i<exportModel->rowCount();i++)
        {
            for(int j=0;j<exportModel->columnCount();j++)
            {
                strList.insert(j,exportModel->data(exportModel->index(i,j)).toString());//把每一行的每一列数据读取到strList中
            }
            strString = strList.join(", ")+"\n";//给两个列数据之前加“,”号，一行数据末尾加回车
            strList.clear();//记录一行数据后清空，再记下一行数据
            QByteArray bytes = strString.toLocal8Bit();
            //写入到文件
            if(bytes.length() == csvFile.write(bytes))
                result = true;
        }
        csvFile.close();
    }
    return result;
}

//获取当前PC的串口名
QStringList getSerialName()
{
    QStringList temp;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            if(!list.contains(info.portName(),Qt::CaseSensitive))
                list.insert(0,info.portName());
            serial.close();
            temp << info.portName();
        }
    }
    for(int i = 0 ; i < list.size() ; i ++)
    {
        if(!temp.contains(list.at(i)))
            list.removeAt(i);
    }
    return list;
}
