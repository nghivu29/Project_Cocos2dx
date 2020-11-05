#include "CHero.h"
#include "common.h"
#include "CBeatSlider.h"

USING_NS_CC;

bool CHero::init()
{
	if (!(Sprite::initWithFile(PNG_HERO1_00) && initAnimate()))
	{
		return false;
	}
	this->setScale(0.2);
	return true;
}

void CHero::runAnimate(EHeroStatus status, int i)
{
	switch (status)
	{
	case NORMAL_ATTACK:
		runSkillAnimate(_animatesNormalAttack.at(i));
		break;
	case STRONG_ATTACK:
		runSkillAnimate(_animatesStrongAttack.at(i));
		break;
	case RUN:
		runAction(_animatesRun.at(i));
		break;
	default:
		break;
	}
}

void CHero::runSkillAnimate(cocos2d::Animate * animate)
{
	runAction(Sequence::create(animate, _animatesRun.at(0), nullptr));
}

bool CHero::initAnimate()
{
	if (! (initAnimatesNormalAttack() && initAnimatesRun()))
	{
		return false;
	}
	return true;
}

bool CHero::initAnimatesNormalAttack()
{
	if (! (initAnimateNormalAttackPerfect() && initAnimateNormalAttackGood() && initAnimateNormalAttackMiss()))
	{
		return false;
	}
	return true;
}

bool CHero::initAnimateNormalAttackPerfect()
{
	auto sp0 = Sprite::create(PNG_HERO1_01);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animatesNormalAttack.pushBack(Animate::create(Animation::createWithSpriteFrames(list, 0.2)));
	return true;
}

bool CHero::initAnimateNormalAttackGood()
{
	auto sp0 = Sprite::create(PNG_HERO1_02);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animatesNormalAttack.pushBack( Animate::create(Animation::createWithSpriteFrames(list, 0.2)) );
	return true;
}

bool CHero::initAnimateNormalAttackMiss()
{
	auto sp0 = Sprite::create(PNG_HERO1_03);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animatesNormalAttack.pushBack(Animate::create(Animation::createWithSpriteFrames(list, 0.2)));
	return true;
}

bool CHero::initAnimatesRun()
{
	if (! initAnimateNormalRun())
	{
		return false;
	}
	return true;
}

bool CHero::initAnimateNormalRun()
{
	auto sp0 = Sprite::create(PNG_HERO1_00);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animatesRun.pushBack(Animate::create(Animation::createWithSpriteFrames(list, 0.2)));
	return true;
}
