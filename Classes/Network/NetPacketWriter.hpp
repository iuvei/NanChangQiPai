//
//  NetPacketWriter.hpp
//  NanChangQiPai
//
//  Created by NextCY on 16/10/12.
//
//

#ifndef NetPacketWriter_hpp
#define NetPacketWriter_hpp

#include "NetPacketBase.hpp"

using namespace std;

class NetPacketWriter:public NetPacketBase {
public:
    bool onWriteHeader();
    bool onWriteByte(BYTE);
    bool onWriteInt(int);
    bool onWriteString(string);
};

#endif /* NetPacketWriter_hpp */
