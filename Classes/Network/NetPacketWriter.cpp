//
//  NetPacketWriter.cpp
//  NanChangQiPai
//
//  Created by NextCY on 16/10/12.
//
//

#include "NetPacketWriter.hpp"

// 写入头部,预留12个字节
bool NetPacketWriter::onWriteHeader()
{
    for (int i = 0; i < 12; ++i) {
        onWriteInt(0);
    }
    m_toalPacketLen = 12;
    return true;
}

bool NetPacketWriter::onWriteInt(int value)
{
    m_toalPacketLen += 4;
    return true;
}

bool NetPacketWriter::onWriteByte(BYTE value)
{
    m_toalPacketLen += 1;
    return true;
}

bool NetPacketWriter::onWriteString(string value)
{
    
    
    return true;
}

