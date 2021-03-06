#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameData.h"
#include "GameOverScene.h"
#include "GameStates.h"

#include "Bullet.h"
#include "BossBullet.h"
#include "HealthBar.h"
#include "GameScene.h"

#include "SimpleAudioEngine.h"  

#include <iostream>

class Level2 : public cocos2d::Layer
{
private:
	GameStates m_gameState;
	//Boss2 * boss2;
	//Player * player;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over
	void activateGameOverScene(Ref *pSender);
	//call menu
	void activateMainMenuScene(Ref *pSender);
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	void update(float dt);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	CREATE_FUNC(Level2);
};