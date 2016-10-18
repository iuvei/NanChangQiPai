//
//  GameMananger.cpp
//  NanChangQiPai
//
//  Created by NextCY on 16/9/27.
//
//

#include "GameMananger.h"
#include "CommonDefine.h"
#include "NanChangMahjongGameServer.h"
#include "NanChangMahjongRoomScene.h"

GameMananger::GameMananger(int _GameType){
    m_gameType = _GameType;
    CCLOG("m_gameType = %d", m_gameType);
    switch (m_gameType) {
        case kGameTypeNanChangMahjong:
            m_server = new NanChangMahjongGameServer(this);
            m_scene = new NanChangMahjongRoomScene();
            break;
        default:
            break;
    }
    int i = 1;
    char *s = (char *) &i;
    CCLOG("%d", *s);
}

GameMananger::~GameMananger()
{
    CCLOG("GameMananger dtor");
    CC_SAFE_DELETE(m_server);
    CC_SAFE_DELETE(m_scene);
}