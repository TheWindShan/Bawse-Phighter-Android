#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "Missile.h"
#include "GameScene.h"

class Boss2 : public cocos2d::Sprite{
public:
	static Boss2 * create(void);
	void initBoss2();
	void move(int directionParam);
	void update(Level1* world);
	void Defeated();
	void deleteBossBullet(Level1* world, int i);
	void deleteBossBullet2(Level1* world, int i);
	void deleteBossBullet3(Level1* world, int i);
	void loseLives();

	bool Hit();

	float getLives();

	std::vector<Missile*> getBullets();
	std::vector<Missile*> getBullets2();
	std::vector<Missile*> getBullets3();
private:
	const short SECOND = 60;
	int direction, lives;
	bool hit;
	short bossCounter;
	short bossBulletCounter, bossBulletCounter2, bossBulletCounter3;

	std::vector<Missile*> currentBossBullets;
	std::vector<Missile*> currentBossBullets2;
	std::vector<Missile*> currentBossBullets3;
};
