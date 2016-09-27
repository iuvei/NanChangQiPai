#include "LobbyScene.h"
#include "SimpleAudioEngine.h"
#include "Common/CommonDefine.h"
#include "Mananger/GameMananger.h"

Scene* LobbyScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LobbyScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LobbyScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    return this->onLoadView();
}

void LobbyScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
    #endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

// private
void LobbyScene::onBtn_enterNanChangMahjongCallBack(Ref *psender, int index)
{
    log("onBtn_enterNanChangMahjongCallBack : %d", index);
    GameMananger *mananger = new GameMananger(kGameTypeNanChangMahjong);
}

// 初始化视图
bool LobbyScene::onLoadView()
{
    log("LobbyScene onLoadView");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    log("visibleSize : %lf, %lf", visibleSize.width, visibleSize.height);
    log("origin : %lf, %lf", origin.x, origin.y);
    log("winSize : %lf, %lf", winSize.width, winSize.height);
    
    auto sprite = Sprite::create("backGround.jpg");
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(0, 0));
    sprite->setAnchorPoint(Vec2(0, 0));
    sprite->setScale(winSize.width/sprite->getTextureRect().getMaxX(), winSize.height/sprite->getTextureRect().getMaxY());
    this->addChild(sprite, 0);
    
    for (int i = 1; i <= 3;  ++i) {
        // 点击进入房间
        auto btn_enterRoom = Button::create("res/Common/button1.png");
        // position the sprite on the center of the screen
        btn_enterRoom->setPosition(Vec2(0 + (i-1) * 200, winSize.height/2));
        btn_enterRoom->setAnchorPoint(Vec2(0, 0));
        btn_enterRoom->setTitleText("南昌麻将");
        //    btn_enterRoom->setScale(winSize.width/sprite->getTextureRect().getMaxX(), winSize.height/sprite->getTextureRect().getMaxY());
        this->addChild(btn_enterRoom, 1);
        //    btn_enterRoom->addTouchEventListener(CC_CALLBACK_2(LobbyScene::onBtn_enterNanChangMahjongCallBack, this));
        btn_enterRoom->addClickEventListener(CC_CALLBACK_1(LobbyScene::onBtn_enterNanChangMahjongCallBack, this, i));
    }
    return true;
}
