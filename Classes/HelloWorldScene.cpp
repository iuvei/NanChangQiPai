#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("backGround.jpg");
    auto winSize = Director::getInstance()->getWinSize();
    // position the sprite on the center of the screen
    sprite->setPosition(winSize.width/2, winSize.height/2);
//    sprite->setAnchorPoint(Vec2(0.5, 0.5));
    float spx = sprite->getTextureRect().getMaxX();
    float spy = sprite->getTextureRect().getMaxY();
    sprite->setScale(winSize.width/spx, winSize.height/spy);
//    sprite->setContentSize(Size(visibleSize.width, visibleSize.height));

    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
//    auto *sprite1 = Sprite::create("backGround.jpg");
//    sprite1->setPosition(Vec2(20,40));
//    sprite1->setAnchorPoint(Vec2(0,0));
//    this->addChild(sprite1);  //此时添加到的是世界坐标系，也就是OpenGL坐标系
    
    auto *sprite2 = Sprite::create("backGround.jpg");
    sprite2->setPosition(Vec2(-5,-20));
    sprite2->setAnchorPoint(Vec2(1,1));
    this->addChild(sprite2); //此时添加到的是世界坐标系，也就是OpenGL坐标系
    
    //将 sprite2 这个节点的坐标ccp(-5,-20) 转换为 sprite1节点 下的本地(节点)坐标系统的 位置坐标
//    Point point1 = sprite1->convertToNodeSpace(sprite2->getPosition());
    
    //将 sprite2 这个节点的坐标ccp(-5,-20) 转换为 sprite1节点 下的世界坐标系统的 位置坐标
//    Point point2 = sprite1->convertToWorldSpace(sprite2->getPosition());
    
//    log("position = (%f,%f)",point1.x,point1.y);
//    log("position = (%f,%f)",point2.x,point2.y);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
