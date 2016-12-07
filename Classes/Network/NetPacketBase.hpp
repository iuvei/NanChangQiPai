//
//  NetPacketBase.hpp
//  NanChangQiPai
//
//  Created by NextCY on 16/10/12.
//
//

#ifndef NetPacketBase_hpp
#define NetPacketBase_hpp

#include "CommonDefine.h"
#include <string.h>
using namespace std;

const int PACKET_BUFFER_SIZE = 1024 * 8;

class NetPacketBase {
public:
    NetPacketBase();
    ~NetPacketBase();
    
    // 写入函数
    bool onWrite(const char* pin, int len);
    bool onWriteHeader();
    bool onWriteByte(BYTE value);
    bool onWriteInt(int value);
    bool onWriteInt64(INT64 value);
    bool onWriteString(string value);
    bool onWriteCharStr(char* value);
    bool onEnd();
    
    // 读函数
    bool   onRead(char* pout, int len);
    BYTE   onReadByte();
    int    onReadInt();
    INT64  onReadInt64();
    string onReadString();
    char* onReadCharStr();
    char *onReadPoint(int len);
    
    
    int m_toalPacketLen;
    int m_curPacketLen;
    
    char m_packetStr[PACKET_BUFFER_SIZE];
};

#endif /* NetPacketBase_hpp */
