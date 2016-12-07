#ifndef __Lobby_SCENE_H__
#define __Lobby_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "base/CCMap.h"

#import "GCDAsyncSocket.h"

USING_NS_CC;
using namespace ui;

class LobbyScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);
    void onBtn_enterNanChangMahjongCallBack(Ref* pSender, int index);
    bool onLoadView();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LobbyScene);
    
//    GCDAsyncSocket *asynSocket;
};

#endif // __HELLOWORLD_SCENE_H__
