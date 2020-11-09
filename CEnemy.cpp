#include "CEnemy.h"
#include "common.h"

USING_NS_CC;

CEnemy * CEnemy::createSmallSphericalMonster()
{
	auto enemy =  CEnemy::create();
	if (! enemy->initWithFile(PNG_SMALL_SPHERICAL_MONSTER))
	{
		return nullptr;
	}
	return enemy;
}

bool CEnemy::init()
{
	if (! Sprite::init())
	{
		return false;
	}
	setScale(0.5f);
	return true;
}

void CEnemy::runAnimate(EActorStatus status, int i)
{
}

void CEnemy::runSkillAnimate(cocos2d::Animate * animate)
{
}

void CEnemy::runJumpAnimate(cocos2d::Animate * animate)
{
}

bool CEnemy::initAnimate()
{
	return false;
}

bool CEnemy::initAnimatesNormalAttack()
{
	return false;
}

bool CEnemy::initAnimatesRun()
{
	return false;
}

bool CEnemy::initAnimatesJump()
{
	return false;
}
