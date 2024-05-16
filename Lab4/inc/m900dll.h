#ifndef M900DLL_H
#define M900DLL_H

#include "m900dll_global.h"
#include <memory.h>
#include <QString>

typedef signed   char   int8;
typedef unsigned char   uint8;

typedef signed   short  int16;
typedef unsigned short  uint16;

typedef signed   long   int32;
typedef unsigned long   uint32;

typedef struct
{
    uint8 sof;
    uint8 len;
    uint8 cmd;     // bit-7:(0=没有crc-16, 1=带有crc-16)   bit<6-0>:(cmd-id)
    uint8 *data;   // <254
    uint8 datalen;
    uint16 crc;
    uint8 crclen;
    uint16 eof;
}UHF915M_ReqFrame_t;

typedef struct
{
    uint8 sof;
    uint8 len;
    uint8 cmd;
    uint8 sta;  // 执行结果
    uint8 *data;  // <253
    uint8 datalen;
    uint16 crc;
    uint8 crclen;
    uint8 eof;
}UHF915M_RspFrame_t;

enum UHF_CmdTable
{
    UHFCMD_GET_STATUS = 0x00,     // 询问状态
    UHFCMD_GET_POWER,             // 读取功率
    UHFCMD_SET_POWER,             // 设置功率
    UHFCMD_GET_FRE    = 0x05,     // 读取频率
    UHFCMD_SET_FRE,               // 设置频率
    UHFCMD_GET_VERSION,           // 读取版本信息
    UHFCMD_INVENTORY = 0x10,      // 识别标签（单标签识别）
    UHFCMD_INVENTORY_ANTI,        // 识别标签（防碰撞识别）
    UHFCMD_STOP_GET,              // 停止操作
    UHFCMD_READ_DATA,             // 读取标签数据
    UHFCMD_WRITE_DATA,            // 写入标签数据
    UHFCMD_ERASE_DATA,            // 擦除标签数据
    UHFCMD_LOCK_MEM,              // 锁定标签
    UHFCMD_KILL_TAG,              // 销毁标签
    UHFCMD_INVENTORY_SINGLE,      // 识别标签（单步识别）
    UHFCMD_WIEGAND_INVENTORY,     // 韦根识别
    UHFCMD_SINGLE_READ_DATA = 0x20,   // 读取标签数据（不指定UII）
    UHFCMD_SINGLE_WRITE_DATA          // 写入标签数据（不指定UII）
};

enum UHF_FrequenceMode
{
    UHF_FREMODE_CHINA_920_925MHZ,
    UHF_FREMODE_CHINA_840_845MHZ,
    UHF_FREMODE_ETSI,
    UHF_FREMODE_915MHZ,
    UHF_FREMODE_USER,
    UHF_FREMODE_OTHER
};

enum UHF_FrequenceBase
{
    UHF_FREBASE_50KHZ,
    UHF_FREBASE_125KHZ
};

enum UHF_FrequenceHopMode
{
    UHF_FREHOP_RANDOM,
    UHF_FREHOP_SEQUENCE_HL,
    UHF_FREHOP_SEQUENCE_LH
};

#define BUILD_FRE_BF(integer, decimal)    ((uint16)((integer<<5)&(decimal&0x1f)))

typedef struct
{
    uint8 sof;
    uint8 len;
    uint8 cmd;
    uint8 sta;
}UHF_RspPrefix_t;    // UHF915M模块响应帧前缀

typedef struct
{
    uint8 power;
}UHF_RspGetPower_t;

typedef struct
{
    uint8 freMode;   // H4-Bit: NC    L4-Bit:(0000:中国标准<920~925MHz>  0001:中国标准<840~845MHz>   0010:ETSI标准   0100:用户自定义  其他:中国标准（920~925MHz))
    uint8 freBase;   // H7-Bit: NC    L1-Bit:(0: 50KHz   1: 125KHz)
    uint16 bf;       // (15)-Bit: NC  (14~5)-Bit:起始频率（整数部分）   (4~0)-Bit:起始频率尾数积数（起始频率小数部分）
    uint8 cn;        // 频道数
    uint8 spc;       // H4-Bit: NC    L4-Bit:频道带宽积数
    uint8 freHop;    // H6-Bit: NC    L2-Bit:跳频顺序方式（00:随机跳频  01:从高往低顺序跳频  10:从低往高顺序跳频  其它:随机跳频）
}UHF_ReqSetFre_t;

typedef struct
{
    uint8 freMode;
    uint16 bf;
    uint8 cn;
    uint8 spc;
    uint8 freHop;
}UHF_RspGetFre_t;

typedef struct
{
    uint8 uii[26];
}UHF_Inventory_t;

typedef struct
{
    uint8 apwd[4];
    uint8 bank;
    uint8 ptr;
    uint8 cnt;
}UHF_ReqReadData_t;

typedef struct
{
    uint8 apwd[4];
    uint8 bank;
    uint8 ptr;
    uint8 cnt;
    uint8 data[2];
}UHF_ReqWriteData_t;

typedef struct
{
    uint8 apwd[4];
    uint8 bank;
    uint8 ptr;
    uint8 cnt;
}UHF_ReqEraseData_t;

typedef struct
{
    uint32 apwd;
    uint8 lockData[3];   // H4-Bit: NC     L20-Bit: Lock-CommandPayload
    uint8 uii[26];
}UHF_ReqLockMem_t;

typedef struct
{
    uint8 killpwd[4];
    uint8 uii[26];
}UHF_ReqKillTag_t;

#define UHF_POWER_VALUE(power)   ((power)&0x7f)   //  POWER字段定义(H1-Bit:NC    L7-Bit: valid power value)
enum UHF_OptionPower
{
    UHF_OPTION_POWER_0  = 0x00,    // 设置输出功率控制位（常量）
    UHF_OPTION_POWER_1  = 0x01     // POWER的L7-Bit有效
};

#define UHF_RSP_TIME   200      // UHF响应等待时间为 200 ms

#define UHF_SOF      0xAA
#define UHF_EOF      0x55

#define UHF_RPC_SOF    0
#define UHF_RPC_LEN    1
#define UHF_RPC_CMD    2
#define UHF_RPC_STA    3
#define UHF_RPC_DAT    4
#define UHF_RPC_EOF    5

class M900DLLSHARED_EXPORT M900Dll
{

public:
    M900Dll();
    uint8* UHF_Connect(void);
    uint8* UHF_GetPower(void);
    uint8* UHF_SetPower(uint8 opt, uint8 pwr);
    uint8* UHF_GetFrequency(void);
    uint8* UHF_SetFrequency(UHF_ReqSetFre_t *data);
    uint8* UHF_Inventory(void);
    uint8* UHF_Inventory(uint8 Q);
    uint8* UHF_InventorySingle(void);
    uint8* UHF_StopGet(void);
    uint8* UHF_ReadData(UHF_ReqReadData_t *data, uint8* uii, uint8 uiiLen);   // 指定UII
    uint8* UHF_ReadDataSingle(UHF_ReqReadData_t *data);    // 不指定UII
    uint8* UHF_WriteData(UHF_ReqWriteData_t *data, uint8 *uii, uint8 uiiLen);   // 指定UII
    uint8* UHF_WriteDataSingle(UHF_ReqWriteData_t *data);   // 不指定UII
    uint8* UHF_EraseData(UHF_ReqEraseData_t *data, uint8 *uii, uint8 uiiLen);   // 指定UII
    uint8* UHF_LockMen(UHF_ReqLockMem_t *data);
    uint8* UHF_KillTag(UHF_ReqKillTag_t *data);
    uint8* UHF_GetVersion(void);
    UHF915M_ReqFrame_t UHF_RequestFrameConstructor(uint8 *data,int len);
    UHF915M_RspFrame_t UHF_RsponseFrameConstructor(uint8 *data , int len);
};

#endif // M900DLL_H
