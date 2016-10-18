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

class NetPacketBase {
public:
    NetPacketBase();
    ~NetPacketBase();
    
    
    int m_toalPacketLen;
    int m_curPacketLen;
};

#endif /* NetPacketBase_hpp */
