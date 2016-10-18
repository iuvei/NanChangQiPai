//
//  GameServer.hpp
//  NanChangQiPai
//
//  Created by NextCY on 16/9/27.
//
//

#ifndef GameServer_hpp
#define GameServer_hpp

class GameMananger;

class GameServer{
public:
    GameServer(GameMananger *_mananger);
    ~GameServer();
    
//    virtual bool onInitGameServer();
//    bool onBDGameStart();
//    bool onBDG
    
    GameMananger *m_mananger;
};

#endif /* GameServer_hpp */
