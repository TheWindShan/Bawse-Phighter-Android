#include "BulletManager.h"

bool BulletManager::instanceFlag = false;
BulletManager* BulletManager::instance = NULL;

BulletManager* BulletManager::GetInstance() {
	if (!instanceFlag){
		instance = new BulletManager;
		instanceFlag = true;
		return instance;
	}
	else{
		return instance;
	}
}

void BulletManager::deleteBossBullet(GameScreen* world, BossBullet* &bossBullet)
{
	world->removeChild(bossBullet);
}

void BulletManager::deletePlayerBullet(GameScreen* world, Bullet* &playerBullet)
{
	world->removeChild(playerBullet);
}

void BulletManager::update(GameScreen* world, Bullet* &playerBullet, BossBullet* &bossBullet)
{
	if (bossCounter % (SECOND) == 0){
		bossBullet = BossBullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
		world->addChild(bossBullet, 5);
		bossCounter = 0;
	}

	if (playerCounter % (SECOND / 4) == 0){
		playerBullet = Bullet::createPlayerBullet();
		currentPlayerBullets.push_back(playerBullet);
		world->addChild(playerBullet, 5);
		playerCounter = 0;
	}

	//like a for each statement
	for (Bullet* e : currentPlayerBullets) {
		//had to change from for each e was out of scope before it would compile apk
		e->updatePlayerBullet();
		if (pBullet){
			deletePlayerBullet(world, playerBullet);
		}
	} 

	for (BossBullet* f : currentBossBullets) {
		f->update();
		if (bBullet){
			deleteBossBullet(world, bossBullet);
		}
	}

	playerCounter++;
	bossCounter++;

	return;
}
