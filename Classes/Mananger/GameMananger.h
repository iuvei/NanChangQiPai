//
//  GameMananger.hpp
//  NanChangQiPai
//
//  Created by NextCY on 16/9/27.
//
//

#ifndef GameMananger_hpp
#define GameMananger_hpp

#include "RoomScene.h"
#include "GameServer.h"

class GameMananger{
public:
    GameMananger(int _GameType);
    virtual ~GameMananger();
    
    
    int m_gameType;
private:
    RoomScene *m_scene;
    GameServer *m_server;
};

#endif /* GameMananger_hpp */
