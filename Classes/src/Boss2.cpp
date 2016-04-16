#include "Boss2.h"

USING_NS_CC;

Boss2 * Boss2::create()
{
	Boss2 * boss2 = new Boss2();
	if (boss2 && boss2->initWithFile("GameScreen/boss2.png", Rect(0, 0, 139, 199)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(4);
		char str[100] = { 0 };
		for (int i = 0; i < 4; i++)
		{
			sprintf(str, "GameScreen/boss2.png");
			auto frame = SpriteFrame::create(str, Rect(139 * i, 0, 139, 199));
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(139, 199);
		auto boss2Body = PhysicsBody::createBox(size * 0.75f);
		boss2Body->setCollisionBitmask(0x000005);
		boss2Body->setContactTestBitmask(true);
		boss2Body->setTag(50);
		boss2->setPhysicsBody(boss2Body);
		boss2->runAction(animate);
		boss2->autorelease();
		boss2->initBoss2();
		boss2->setTag(50);
		return boss2;
	}

	CC_SAFE_DELETE(boss2);
	return NULL;
}

void Boss2::move(int directionParam)
{
	direction = directionParam;
	moving = true;
}

/*bool Boss::Hit()
{
hit = true;
}*/

std::vector<BossBullet*> Boss2::getBullets()
{
	return currentBossBullets;
}

void Boss2::deleteBossBullet(Level1* world, int i)
{
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss2::update(Level1* world)
{
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	setPosition(Vec2(s.width / 2, s.height / 2));

	//make boss look l
	if (bossCounter >= 30){
		setRotation(5.0f);
		// increases just X scale by 2.0
	}
	if (bossCounter >= 60){
		// rotate sprite by -20 degrees
		setRotation(-10.0f);
		bossCounter = 0;
		// increases just X scale by 2.0
	}

	bossCounter++;
	return;
}

float Boss2::getLives(){
	return lives;
}

void Boss2::loseLives(){
	lives--;
}

void Boss2::idle()
{
	moving = false;
}

void Boss2::initBoss2(){
	lives = 100;
	bossCounter = 0;
}