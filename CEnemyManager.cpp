#include "CEnemyManager.h"
#include "common.h"

USING_NS_CC;

CEnemyManager::CEnemyManager()
{
	US_ORIGIN;
	US_VISIBLE;
	positionY = new float[3];
	positionY[0] = origin.y + visibleSize.height*GROUND_HEIGHT_RATIO;
	positionY[1] = origin.y + visibleSize.height*0.3;
	positionY[2] = origin.y + visibleSize.height*0.5;

}

bool CEnemyManager::initEnemiesInScene(cocos2d::Scene * scene)
{
	_enemies = new CEnemy*[BEATSLIDER_CAPACITY];
	for (size_t i = 0; i < BEATSLIDER_CAPACITY; i++)
	{
		_enemies[i] = CEnemy::createSmallSphericalMonster();
		_enemies[i]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
		setRandomPositionY(i);
		scene->addChild(_enemies[i]);
	}
	return true;
}

void CEnemyManager::setMusic(CMusic * music)
{
	_music = music;
}


void CEnemyManager::setRandomPositionY(int i)
{
	US_ORIGIN;
	US_VISIBLE;
	_enemies[i]->setPosition(
		origin.x + visibleSize.width*0.9f,
		positionY[RandomHelper::random_int(0, 3)]
		);
}

void CEnemyManager::moveEnemy(int i)
{
	US_ORIGIN;
	US_VISIBLE;
	float duration = _music->getSecondPerMeasume();
	auto moveInTime = MoveTo::create(duration, Vec2(origin.x + visibleSize.width*0.15f, _enemies[i]->getPositionY()));
	auto moveOver = MoveTo::create(BEATSLIDER_OVER_TIME, Vec2(origin.x + visibleSize.width*0.1f, _enemies[i]->getPositionY()));
	auto sequence = Sequence::create(moveInTime, moveOver, nullptr);
	_enemies[i]->runAction(sequence);
}

void CEnemyManager::resetEnemy(int i)
{
	_enemies[i]->stopAllActions();
	setRandomPositionY(i);
}

CEnemy * CEnemyManager::getEnemy(int i)
{
	return _enemies[i];
}


