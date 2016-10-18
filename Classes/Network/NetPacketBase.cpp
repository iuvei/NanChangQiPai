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
}

NetPacketBase::~NetPacketBase()
{
    m_toalPacketLen = 0;
    m_curPacketLen = 0;
}

