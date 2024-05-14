#ifndef M125DLL_H
#define M125DLL_H

#include "m125dll_global.h"

//125K模块上报卡号的起始字节
#define LF125K_SOF    0x00
//成功定义为0
#define SUCCESS      0
//失败定义为-1
#define FAILURE     -1

typedef unsigned char   uint8;
//125K模块上报卡号的结构
typedef struct
{
    uint8 sof;
    uint8 data[3];
    uint8 fcs;    // xor verify
}LF125K_RspFrame_t;

class M125DLLSHARED_EXPORT M125Dll
{

public:
    M125Dll();
	/**********************************************
	*函数名		：LF125K_FrameAnalysis
	*描述		：解析一帧数据是否有误
	*输入参数	：
	*	@frame	const uint8 *	125K的数据帧
	*输出参数	：无
	*返回值		：正确返回0，失败返回-1
	***********************************************/
    int LF125K_FrameAnalysis(const uint8 *frame);
};

#endif // M125DLL_H
