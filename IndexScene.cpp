//
//  IndexScene.cpp
//  Leidian
//
//  Created by niuguoming on 14-4-16.
//
//

#include "IndexScene.h"
#include "BLGameScene.h"
#include "AppDelegate.h"

IndexScene::IndexScene()
{
    
}

IndexScene::~IndexScene()
{

}

void IndexScene::setTTF(CCObject *data)
{

}

void IndexScene::update(float dt)
{
 
}

CCScene* IndexScene::scene() {
    CCScene *scene = CCScene::create();
    
    IndexScene *layer = IndexScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

void IndexScene::onEnter() {
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
}

void IndexScene::onExit() {
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
 
    
}


bool IndexScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void IndexScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    
}
void IndexScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    
}

bool IndexScene::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size= CCDirector::sharedDirector()->getWinSize();
 
   
  
    ttfDian=CCLabelTTF::create("您好，您即将看到的，是由北京掌上酷游科技有限公司开发的《火柴人联盟》游戏，此版本仅对合作伙伴演示之用，不得用于各种渠道的各类申报、评审、上线等活动，也不得在未经本公司同意的情况下，转交于任何第三方。如因上述情况所引发的一切问题、纠纷与争议，本公司将保留追诉的权利。由此给您带来的不便请多谅解。", "", 30);
    ttfDian->setPosition(ccp(size.width/2, size.height/4*3));
    ttfDian->setDimensions(
                            CCSizeMake(size.width/3*2,
                                       size.height));
    ttfDian->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
    
    ttfDian->setHorizontalAlignment(kCCTextAlignmentLeft);
    this->addChild(ttfDian);
    
    CCMenu* menu=CCMenu::create();
    menu->setPosition(CCPointZero);
    this->addChild(menu,2);
    
    
    CCMenuItemFont* lab1=CCMenuItemFont::create("同意", this, menu_selector(IndexScene::domenu));
    lab1->setAnchorPoint(ccp(0, 0));
    lab1->setPosition(ccp(0,0));
    lab1->setTag(0);
    menu->addChild(lab1);
    
    CCMenuItemFont* lab2=CCMenuItemFont::create("拒绝", this, menu_selector(IndexScene::domenu));
    lab2->setAnchorPoint(ccp(1, 0));
    lab2->setPosition(ccp(size.width,0));
    lab2->setTag(1);
    menu->addChild(lab2);
    
    

    return true;
}

void IndexScene::domenu(CCObject * obj){
    int iTag=((CCNode*)obj)->getTag();
    switch (iTag) {
        case 0:
        {
          CCDirector::sharedDirector()->replaceScene(BLGameScene::scene());
        }
            break;
        case 1:
        {
            CCDirector::sharedDirector()->end();
        }
            break;
            
        default:
            break;
    }
}




