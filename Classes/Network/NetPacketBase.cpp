//
//  NetPacketBase.cpp
//  NanChangQiPai
//
//  Created by NextCY on 16/10/12.
//
//

#include "NetPacketBase.hpp"

NetPacketBase::NetPacketBase()
{
    m_toalPacketLen = 0;
    m_curPacketLen = 0;
    memset(m_packetStr, 0, PACKET_BUFFER_SIZE);
}

NetPacketBase::~NetPacketBase()
{
    m_toalPacketLen = 0;
    m_curPacketLen = 0;
}

bool NetPacketBase::onWrite(const char *pin, int len)
{
    if (m_toalPacketLen <0 || m_toalPacketLen + len > PACKET_BUFFER_SIZE) {
        return false;
    }
    memcpy(m_packetStr + m_toalPacketLen, pin, len);
    m_toalPacketLen += len;
    return true;
}

// 写入头部,预留12个字节
bool NetPacketBase::onWriteHeader()
{
    for (int i = 0; i < 12; ++i) {
        onWriteInt(0);
    }
    return true;
}

bool NetPacketBase::onWriteByte(BYTE value)
{
    return onWrite((char *)&value, sizeof(BYTE));
}

bool NetPacketBase::onWriteInt(int value)
{
    return onWrite((char *)&value, sizeof(int));
}

bool NetPacketBase::onWriteInt64(INT64 value)
{
    return onWrite((char *)&value, sizeof(INT64));
}

bool NetPacketBase::onWriteString(string value)
{
    const char *temp = value.c_str();
    int len = temp ? (int)strlen(temp) : 0;
    return onWriteInt(len + 1) && onWrite(temp, len) && onWrite((char *)'\0', 1);
}

bool NetPacketBase::onWriteCharStr(char* value)
{
    int len = value ? (int)strlen(value) : 0;
    return onWriteInt(len + 1) && onWrite(value, len) && onWrite((char *)'\0', 1);
}

bool NetPacketBase::onEnd()
{
    return true;
}

bool NetPacketBase::onRead(char *pout, int len)
{
    if((len + m_curPacketLen) > m_toalPacketLen || (len + m_curPacketLen) > PACKET_BUFFER_SIZE)
        return false;
    memcpy(pout, m_packetStr + m_curPacketLen, len);
    m_curPacketLen += len;
    return true;
}
BYTE NetPacketBase::onReadByte()
{
    BYTE value = -1;
    onRead((char *)&value, sizeof(BYTE));
    return value;
}

int NetPacketBase::onReadInt()
{
    
}

INT64 NetPacketBase::onReadInt64()
{
    
}

string NetPacketBase::onReadString()
{
    
}

char* NetPacketBase::onReadCharStr()
{
    
}

