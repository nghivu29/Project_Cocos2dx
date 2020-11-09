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
		setRandomPositionY(_enemies[i]);
		scene->addChild(_enemies[i]);
	}
	return true;
}

void CEnemyManager::updateEnemy()
{
	for (size_t i = 0; i < BEATSLIDER_CAPACITY; i++)
	{
		if (_beatSlider->getMusic()->getFrame() == _beatSlider->getSpBeats()[i]->getFrameStart())
		{
			moveEnemy(_enemies[i]);
		}

		if (_beatSlider->getMusic()->getFrame() == _beatSlider->getSpBeats()[i]->getFrameTarget() + 20)
		{
			//resetEnemy(_enemies[i]);
		}
	}
}

void CEnemyManager::setBeatSlider(CBeatSlider * beatSlider)
{
	_beatSlider = beatSlider;
}

void CEnemyManager::setRandomPositionY(CEnemy * enemy)
{
	US_ORIGIN;
	US_VISIBLE;
	enemy->setPosition(
		origin.x + visibleSize.width*0.9f,
		positionY[RandomHelper::random_int(0, 3)]
		);
}

void CEnemyManager::moveEnemy(CEnemy * enemy)
{
	US_ORIGIN;
	US_VISIBLE;
	float duration = _beatSlider->getMusic()->getSecondPerMeasume();
	auto moveInTime = MoveTo::create(duration, Vec2(origin.x + visibleSize.width*0.1f, enemy->getPositionY()));
	auto moveOver = MoveTo::create(BEATSLIDER_OVER_TIME, Vec2(origin.x + visibleSize.width*0.1f, enemy->getPositionY()));
	auto sequence = Sequence::create(moveInTime, moveOver, nullptr);
	enemy->runAction(sequence);
}


