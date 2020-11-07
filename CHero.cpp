#include "CHero.h"
#include "common.h"
#include "CBeatSlider.h"

USING_NS_CC;

bool CHero::init()
{
	if (!(Sprite::initWithFile("ninjaadventurenew/png/Run__000.png") && initAnimate()))
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
	case JUMP:
		runJumpAnimate(_animatesJump.at(i));
	default:
		break;
	}
}

void CHero::runSkillAnimate(cocos2d::Animate * animate)
{
	stopAllActions();
	runAction(Sequence::create(animate, _animatesRun.at(0), nullptr));
}

void CHero::runJumpAnimate(cocos2d::Animate * animate)
{
	stopAllActions();
	runAction(Sequence::create(MoveBy::create(0.5, Vec2(0, 100)), MoveBy::create(0.5, Vec2(0, -100)), nullptr));
	runAction(Sequence::create(animate, _animatesRun.at(0), nullptr));

}


bool CHero::initAnimate()
{
	if (! (initAnimatesNormalAttack() && initAnimatesRun() && initAnimatesJump()))
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
	Vector<SpriteFrame*> list;
	Sprite* sp0 = nullptr;
	for (size_t i = 0; i < 9; i++)
	{
		sp0 = Sprite::create(StringUtils::format("ninjaadventurenew/png/Attack__00%d.png", i));
		list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));
	}

	_animatesNormalAttack.pushBack(Animate::create(Animation::createWithSpriteFrames(list, 0.05f)));
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
	Vector<SpriteFrame*> list;
	Sprite* sp0 = nullptr;
	for (size_t i = 0; i < 9; i++)
	{
		sp0 = Sprite::create(StringUtils::format("ninjaadventurenew/png/Run__00%d.png", i));
		list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));
	}
	auto animate = Animate::create(Animation::createWithSpriteFrames(list, 0.1, -1));
	_animatesRun.pushBack(animate);
	return true;
}

bool CHero::initAnimatesJump()
{
	Vector<SpriteFrame*> list;
	Sprite* sp0 = nullptr;
	for (size_t i = 0; i < 9; i++)
	{
		sp0 = Sprite::create(StringUtils::format("ninjaadventurenew/png/Jump__00%d.png", i));
		list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));
	}
	auto animate = Animate::create(Animation::createWithSpriteFrames(list, 0.1));
	_animatesJump.pushBack(animate);
	return true;
}
