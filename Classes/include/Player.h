#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "GameScene.h"
#include "Bullet.h"

class Player : public cocos2d::Sprite{
public:
	static Player * create(void);

	void move(float x, float y);
	void update(GameScreen* world);
	std::vector<Bullet*> getBullets();
	void Boundaries();
	void idle();
	void LoseLives();
	void deletePlayerBullet(GameScreen* world, int i);

private:
	void initPlayer();

	float dirX, dirY;
	float speed;
	float lives = 100;

	bool moving;
	bool hit;

	short counter;
	const short SECOND = 60;

	std::vector<Bullet*> currentPlayerBullets;
};