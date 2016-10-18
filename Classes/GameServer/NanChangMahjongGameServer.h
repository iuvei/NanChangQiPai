//
//  NanChangMahjongGameServer.hpp
//  NanChangQiPai
//
//  Created by NextCY on 16/9/27.
//
//

#ifndef NanChangMahjongGameServer_hpp
#define NanChangMahjongGameServer_hpp

#include "GameServer.h"

class NanChangMahjongGameServer :public GameServer{
    
public:
    NanChangMahjongGameServer(GameMananger *_mananger):GameServer(_mananger){
        m_mananger = _mananger;
    };
    
    
};

#endif /* NanChangMahjongGameServer_hpp */
