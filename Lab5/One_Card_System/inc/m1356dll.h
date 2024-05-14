#ifndef M1356DLL_H
#define M1356DLL_H

#include "m1356dll_global.h"
#include <QString>
#include <QDebug>

typedef signed   char   int8;
typedef unsigned char   uint8;

typedef signed   short  int16;
typedef unsigned short  uint16;

typedef signed   long   int32;
typedef unsigned long   uint32;
/*******************************************
 *  RC632 BAUDRATE defined  ****************
*******************************************/
#define RC632_B4800     0
#define RC632_B9600     1
#define RC632_B14400    2
#define RC632_B19200    3
#define RC632_B28800    4
#define RC632_B38400    5
#define RC632_B57600    6
#define RC632_B115200   7
/***********************命令帧次序********************/
#define RC632_RPC_SOP    0
#define RC632_RPC_LEN    2
#define RC632_RPC_NC     4
#define RC632_RPC_CMD    6
#define RC632_RPC_DAT    8
/*******************************************/
#define RC632_FRAME_SOP           0xBBAA
//设置波特率
#define RC632_CMD_SET_BAUDRATE    0x0101
//获取固件版本信息
#define RC632_CMD_GET_HARDMODEL   0x0104
//协议切换命令字
#define RC632_CMD_CONFIG_ISOTYPE  0x0108
//天线控制命令字
#define RC632_CMD_ANT_CONTROL     0x010C
/********************************************
*13.56MHz 14443协议命令字
*********************************************/
//请求A，发送寻卡命令
#define RC632_CMD_REQUEST_A       0x0201
//防冲撞命令字
#define RC632_CMD_ANTICOLL        0x0202
//选择命令字
#define RC632_CMD_SELECT          0x0203
//休眠命令字
#define RC632_CMD_SLEEP           0x0204
//授权命令字
#define RC632_CMD_AUTHENTICATION  0x0207
//M1卡读取标签数据命令字
#define RC632_CMD_M1READ          0x0208
//M1卡写入标签数据命令字
#define RC632_CMD_M1WRITE         0x0209
//M1卡钱包初始化命令字
#define RC632_CMD_M1INITVAL       0x020A
//M1卡读取钱包命令字
#define RC632_CMD_M1READVAL       0x020B
//M1卡钱包扣费命令字
#define RC632_CMD_M1DECREMENT     0x020C
//M1卡钱包充值命令字
#define RC632_CMD_M1INCREMENT     0x020D
//M1卡回传命令字
#define RC632_CMD_M1RESTORE       0x020E
//M1卡传送命令字
#define RC632_CMD_M1TRANSFER      0x020F
//TYPEA卡高级复位命令
#define RC632_CMD_TYPEA_RST       0x0210
//TYPEA COS命令
#define RC632_CMD_TYPEA_COS       0x0211
//ultra light防冲撞命令
#define RC632_CMD_ULTRA_ANTICOLL  0x0212
//ultra light写卡命令
#define RC632_CMD_ULTRA_WRITE     0x0213
/********************************************
*下面的这些命令都没用到，可参照下位机源码进行编程
*********************************************/
#define RC632_CMD_TYPEB_RST       0x0301
#define RC632_CMD_HLTB            0x0302
#define RC632_CMD_CL_DESELECT     0x0303

#define RC632_CMD_RF020CHECK      0x0401
#define RC632_CMD_RF020READ       0x0402
#define RC632_CMD_RF020WRITE      0x0403
#define RC632_CMD_RF020LOCK       0x0404
#define RC632_CMD_RF020COUNT      0x0405
#define RC632_CMD_RF020DESELECT   0x0406

#define RC632_CMD_SELECT_SR       0x0501
#define RC632_CMD_COMPLETION_SR   0x0502
#define RC632_CMD_READ_SR176      0x0503
#define RC632_CMD_WRITE_SR176     0x0504
#define RC632_CMD_PROTECT_SR176   0x0505
#define RC632_CMD_READ_SR4K       0x0506
#define RC632_CMD_WRITE_SR4K      0x0507
#define RC632_CMD_AUTH_SR4K       0x0508
#define RC632_CMD_GETUID_SR4K     0x0509
#define RC632_CMD_PROTECT_SR4K    0x050A
/****************************************************
*15693协议
*****************************************************/
//寻命令字，可以寻多卡
#define RC632_CMD_ISO15693_INVENTORY16               0x1000
//寻卡命令字，只能寻单卡，能否寻到标签和标签的状态相关
#define RC632_CMD_ISO15693_INVENTORY                 0x1001
//静默态命令字
#define RC632_CMD_ISO15693_STAY_QUIET                0x1002
//选择态命令字
#define RC632_CMD_ISO15693_SELECT                    0x1003
//重置到准备态命令字
#define RC632_CMD_ISO15693_RESET_TO_READY            0x1004
//读单个数据块或多个数据块命令字
#define RC632_CMD_ISO15693_READ_SM                   0x1005
//写单个块或多个块命令字，多个块可能不支持
#define RC632_CMD_ISO15693_WRITE_SM                  0x1006
//锁定数据块命令字
#define RC632_CMD_ISO15693_LOCK_BLOCK                0x1007
//写入AFI命令字
#define RC632_CMD_ISO15693_WRITE_AFI                 0x1008
//锁定AFI命令字
#define RC632_CMD_ISO15693_LOCK_AFI                  0x1009
//写DSFID命令字
#define RC632_CMD_ISO15693_WRITE_DSFID               0x100A
//锁定DSFID命令字
#define RC632_CMD_ISO15693_LOCK_DSFID                0x100B
//获取系统信息命令字
#define RC632_CMD_ISO15693_GET_SYSINFO               0x100C
//获取多个块的安全状态命令字
#define RC632_CMD_ISO15693_GET_MULTIBLOCK_SECURITY   0x100D

/************************************************
*标识符的定义
************************************************/
//15693工作模式参数值
#define RC632_WORK_MODEL_15693                      0x31
//14443A工作参数值
#define RC632_WORK_MODEL_1443A                      0x41
//14443B工作参数值
#define RC632_WORK_MODEL_1443B                      0x42
//14443A寻卡参数值（所有卡）
#define RC632_14443_ALL                              0x52
//14443A寻卡参数值（寻未休眠卡）
#define RC632_14443_IDL                              0x26
//构建uint32类型的整数
#define BUILD_UINT32(Byte0, Byte1, Byte2, Byte3) \
          ((uint32)((uint32)((Byte0) & 0x00FF) \
          + ((uint32)((Byte1) & 0x00FF) << 8) \
          + ((uint32)((Byte2) & 0x00FF) << 16) \
          + ((uint32)((Byte3) & 0x00FF) << 24)))
//构建int32类型的整数
#define BUILD_INT32(Byte0, Byte1, Byte2, Byte3) \
          ((int32)((uint32)((Byte0) & 0x00FF) \
          + ((int32)((Byte1) & 0x00FF) << 8) \
          + ((int32)((Byte2) & 0x00FF) << 16) \
          + ((int32)((Byte3) & 0x00FF) << 24)))

//构建uint16类型的整数
#define BUILD_UINT16(loByte, hiByte) \
          ((uint16)(((loByte) & 0x00FF) + (((hiByte) & 0x00FF) << 8)))
//取uint16类型的高8位
#define HI_UINT16(a) (((a) >> 8) & 0xFF)
//取uint16类型的低8位
#define LO_UINT16(a) ((a) & 0xFF)
//构建uint8类型的整数
#define BUILD_UINT8(hiByte, loByte) \
          ((uint8)(((loByte) & 0x0F) + (((hiByte) & 0x0F) << 4)))
//取uint8类型的高4位
#define HI_UINT8(a) (((a) >> 4) & 0x0F)
//取uint8类型的低4位
#define LO_UINT8(a) ((a) & 0x0F)

/*******************************************************
 * 和上位机的通讯错误代码定义
*******************************************************/
#define  RC632_OK 0                          //请求操作成功
#define  RC632_FAULT255  255                 //帧校验失败

#define  RC632_FAULT10   10                  //通用错误
#define  RC632_FAULT11   11                  //不支持该命令
#define  RC632_FAULT12   12                  //命令参数错
#define  RC632_FAULT13   13                  //无卡
#define  RC632_FAULT14   14                  //射频基站损坏

#define  RC632_FAULT20   20                  //寻卡失败
#define  RC632_FAULT21   21                  //卡复位失败
#define  RC632_FAULT22   22                  //密码验证失败
#define  RC632_FAULT23   23                  //读卡失败
#define  RC632_FAULT24   24                  //写卡失败

#define  RC632_FAULT100  100                 //未响应
/******************************************************
*结构体的定义
*******************************************************/
//请求帧结构体的定义(按照命令字类型定义)
typedef struct
{
    uint16 sof;
    uint16 len;
    uint16 nc;
    uint16 cmd;
    uint8 *data;
    uint8 fcs;
}RC632_ReqFrame_t;
//请求帧结构体的定义（按照上位机可操作类型定义）
typedef struct
{
    QString sof;
    QString len;
    QString dev_id;
    QString cmd;
    QString vdata;
    QString fcs;
}M1356_ReqFrame_t;
//响应帧结构体的定义（按照上位机可操作类型定义）
typedef struct
{
    QString sof;
    QString len;
    QString dev_id;
    QString cmd;
    QString status;
    QString vdata;
    QString fcs;
}M1356_RspFrame_t;
//响应帧数据
typedef struct
{
    uint8 data;
}RC632_RspFrame_t;

class M1356DLLSHARED_EXPORT M1356Dll
{

public:
    M1356Dll();
	/**********************************************
	*函数名		：RC632_SendCmdReq
	*描述		：构造一帧请求命令帧
	*输入参数	：
	*	@cmd	uint8	命令字，具体值参照上面定义的各个命令字
	*	@data	uint8 *	请求命令待传输的参数数据，例如块号、地址、扇区等参数信息
	*	@len	uint8	参数按照字节计算的长度
	*输出参数	：无
	*返回值		：uint8型指针，指向请求命令帧的起始位置
	***********************************************/
    uint8* RC632_SendCmdReq(uint16 cmd, const uint8 *data, uint16 len);
	/**********************************************
	*函数名		：RC632_AnalysisFrame
	*描述		：分析一帧命令
	*输入参数	：
	*	@frame	uint8 *	指向一帧数据的开始
	*	@cmd	uint8	命令字，具体值参照上面定义的各个命令字（这里是响应帧的解析，命令字应该输入请求帧对应的CMD）
	*输出参数	：无
	*返回值		：uint8型标志字节，如果帧格式正确返回帧对应的状态字节，不正确返回255
	***********************************************/
    uint8 RC632_AnalysisFrame(uint8 *frame, uint16 cmd);
	/**********************************************
	*函数名		：RC632_UartCalcFCS
	*描述		：计算校验和
	*输入参数	：
	*	@msg_ptr	uint8 *	指向待计算部分的开始字节
	*	@len		uint8	待计算的长度
	*输出参数	：无
	*返回值		：uint8型校验和字节
	***********************************************/
    uint8 RC632_UartCalcFCS( uint8 *msg_ptr, uint8 len );
	/**********************************************
	*函数名		：GET_ERROR_STRING
	*描述		：获取错误字符串
	*输入参数	：
	*	@error	QString	错误码，此处运用前面定义的结构体M1356_RspFrame_t变量传入status即可
	*输出参数	：无
	*返回值		：QString类型的具体错误文本描述
	***********************************************/
    QString GET_ERROR_STRING(QString error);
	/**********************************************
	*函数名		：M1356_RspFrameConstructor
	*描述		：构造M1356_RspFrame_t结构体
	*输入参数	：
	*	@bytes	QByteArray	从串口读取的响应帧字节数组
	*输出参数	：无
	*返回值		：M1356_RspFrame_t型结构体
	***********************************************/
    M1356_RspFrame_t M1356_RspFrameConstructor(QByteArray bytes);
	/**********************************************
	*函数名		：M1356_ReqFrameConstructor
	*描述		：构造M1356_ReqFrame_t结构体
	*输入参数	：
	*	@msg	uint8 *	指向请求命令帧的起始位置
	*	@len	uint8	该帧的长度
	*输出参数	：无
	*返回值		：M1356_ReqFrame_t型结构体
	***********************************************/
    M1356_ReqFrame_t M1356_ReqFrameConstructor(const char *msg, int len);
};

#endif // M1356DLL_H
