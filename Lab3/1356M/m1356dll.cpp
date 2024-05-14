#include "m1356dll.h"
QString CharStringtoHexString(QString space, const char * src, int start, int end);
M1356Dll::M1356Dll()
{
}
///普通字符串转为16进制字符串
QString CharStringtoHexString(QString space, const char * src, int start, int end)
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

//发送请求帧
uint8* M1356Dll::RC632_SendCmdReq(uint16 cmd, const uint8 *data, uint16 len)
{
    uint8 *p;
    uint16 frameLen, uartdatalen;
    frameLen = len+9;   // 9 = sop(2)+len(2)+nc(2)+cmd(2)+fcs(1)
    uartdatalen = frameLen;
    for(uint16 i=0; i<len; i++)
        if(data[i] == 0xAA)  uartdatalen++;
    p = new uint8[uartdatalen+2];  // p[0] is used return frameLen
    p[0] = LO_UINT16(uartdatalen);
    p[1] = HI_UINT16(uartdatalen);
    p[2] = LO_UINT16(RC632_FRAME_SOP);
    p[3] = HI_UINT16(RC632_FRAME_SOP);
    p[4] = LO_UINT16(frameLen-4);  // 4 = sop(2)+len(2)
    p[5] = HI_UINT16(frameLen-4);  // 4 = sop(2)+len(2)
    p[6] = 0;  // NC
    p[7] = 0;  // NC
    p[8] = LO_UINT16(cmd);
    p[9] = HI_UINT16(cmd);
    //memcpy(p+10, data, len);
    int k=0;
    for(int j=0; j<len; j++, k++){
        p[10+k] = data[j];
        if(data[j]==0xAA)  p[10+ ++k] = 0x00;
    }
    p[10+k] = RC632_UartCalcFCS(p+5, uartdatalen-4);

    return p;
}

uint8 M1356Dll::RC632_UartCalcFCS( uint8 *msg_ptr, uint8 len )
{
    uint8 x;
    uint8 xorResult;
    xorResult = 0;
    for ( x = 0; x < len; x++, msg_ptr++ )
      xorResult = xorResult ^ *msg_ptr;
    return ( xorResult );
}
//解析某一帧数据
uint8 M1356Dll::RC632_AnalysisFrame(uint8 *frame, uint16 cmd)
{
    uint16 sof = BUILD_UINT16(frame[RC632_RPC_SOP], frame[RC632_RPC_SOP+1]);
    uint16 len = BUILD_UINT16(frame[RC632_RPC_LEN], frame[RC632_RPC_LEN+1]);
    uint16 rxCmd = BUILD_UINT16(frame[RC632_RPC_CMD], frame[RC632_RPC_CMD+1]);
    if(sof == RC632_FRAME_SOP)
    {
        int tempLen = len,i=0,j=0;
        while(tempLen > i){  //
            frame[RC632_RPC_NC+i] = frame[RC632_RPC_NC+j];
            if(frame[RC632_RPC_NC+i] == 0xAA)  j++;
            i++; j++;
        }
        if(rxCmd == cmd)
        {
            uint8 fcs = RC632_UartCalcFCS(&frame[RC632_RPC_LEN+1], len);
            if(fcs == frame[RC632_RPC_LEN+len+1])
                return frame[RC632_RPC_DAT];
            else{
                qDebug()<<"[ERR-RC632 Frame FCS ERR]";
                qDebug("%02X!=%02X", fcs, frame[RC632_RPC_LEN+len+1]);
            }
        }
        else
        {
            qDebug()<<"[ERR-RC632 Frame CMD ERR]";
        }
    }
    else
    {
        qDebug()<<"[ERR-RC632] Frame SOP ERR";
    }

    return RC632_FAULT255;  // frame fcs error
}

/**
 * @brief GET_ERROR_STRING
 * @param error 错误码
 * @return  错误信息
 * 获取错误码
 */
QString M1356Dll::GET_ERROR_STRING(QString error)
{
    QString result="未知错误";
    bool ok = true;
    if(error.length() == 2)
    {
        int id = error.toInt(&ok,16);
        switch (id) {
        case RC632_FAULT10:
            result = "通用错误";
            break;
        case RC632_FAULT11:
            result = "不支持该命令";
            break;
        case RC632_FAULT12:
            result = "无卡";
            break;
        case RC632_FAULT13:
            result = "射频基站损坏";
            break;
        case RC632_FAULT14:
            result = "射频基站损坏";
            break;
        case RC632_FAULT20:
            result = "寻卡失败";
            break;
        case RC632_FAULT21:
            result = "卡复位失败";
            break;
        case RC632_FAULT22:
            result = "密码验证失败";
            break;
        case RC632_FAULT23:
            result = "读卡失败";
            break;
        case RC632_FAULT24:
            result = "写卡失败";
            break;
        case RC632_FAULT100:
            result = "未响应";
            break;
        default:
            result = "未知错误";
            break;
        }
    }
   return result;
}

//构造一个请求帧显示到UI界面
M1356_ReqFrame_t M1356Dll::M1356_ReqFrameConstructor( const char *msg,int len)
{
    M1356_ReqFrame_t frame;
    if(len >= 9)
    {
        int16 frame_len = BUILD_UINT16(msg[2], msg[3]);
        frame.sof = CharStringtoHexString(QObject::tr(" "),msg,0,2);
        frame.len = CharStringtoHexString(QObject::tr(" "),msg,2,4);
        frame.dev_id = CharStringtoHexString(QObject::tr(" "),msg,4,6);
        frame.cmd = CharStringtoHexString(QObject::tr(" "),msg,6,8);
        frame.vdata = CharStringtoHexString(QObject::tr(" "),msg,8,frame_len + 3);
        frame.fcs = CharStringtoHexString(QObject::tr(" "),msg,frame_len + 3,frame_len + 4);
        return frame;
    }
    return frame;
}

//构建一个响应帧显示到UI界面
M1356_RspFrame_t M1356Dll::M1356_RspFrameConstructor(QByteArray bytes )
{
    M1356_RspFrame_t frame;
    if(bytes.length() >= 9)
    {
        int16 frame_len = BUILD_UINT16(bytes[2], bytes[3]);
        if(frame_len == bytes.length() - 4)
        {
            char *msg = bytes.data();
            frame.sof = CharStringtoHexString(QObject::tr(" "),msg,0,2);
            frame.len = CharStringtoHexString(QObject::tr(" "),msg,2,4);
            frame.dev_id = CharStringtoHexString(QObject::tr(" "),msg,4,6);
            frame.cmd = CharStringtoHexString(QObject::tr(" "),msg,6,8);
            if(frame_len == 6)
            {
                frame.status = CharStringtoHexString(QObject::tr(" "),msg,8,9);
                frame.vdata = CharStringtoHexString(QObject::tr(" "),msg,9,frame_len + 3);
            }
            else
            {
                short cmd = BUILD_UINT16(msg[6],msg[7]);
                if(cmd == RC632_CMD_ISO15693_INVENTORY16 || cmd == RC632_CMD_ISO15693_INVENTORY)
                {
                    frame.status = CharStringtoHexString(QObject::tr(" "),msg,8,10);
                    frame.vdata = CharStringtoHexString(QObject::tr(" "),msg,10,frame_len + 3);
                }
                else{
                    frame.status = CharStringtoHexString(QObject::tr(" "),msg,8,9);
                    frame.vdata = CharStringtoHexString(QObject::tr(" "),msg,9,frame_len + 3);
                }
                int frame_vadatalen = frame.vdata.length();
                int frame_vadatalen_t = frame_vadatalen - 23;
                if(frame_vadatalen_t > 0 && (frame_vadatalen_t % 27 == 0))
                {
                    QString temp = "";
                    int temp_len = frame.vdata.length() / 27 + 1;
                    for(int count = 0 ; count < temp_len ; count ++)
                    {
                        temp += frame.vdata.mid(27*count,23);
                        temp += QObject::tr(";");
                    }
                    frame.vdata = temp.left(temp.length() - 1);
                }
            }
            frame.fcs = CharStringtoHexString(QObject::tr(" "),msg,frame_len + 3,frame_len + 4);
            return frame;
        }
    }
    return frame;
}
