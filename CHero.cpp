#include "CHero.h"
#include "common.h"
#include "CBeatSlider.h"

USING_NS_CC;

bool CHero::init()
{
	if (!(Sprite::initWithFile(PNG_HERO1_00) && initAnimate() && initKeyboard()))
	{
		return false;
	}
	this->setScale(0.2);
	_hitStatus == EHitStatus::NOPE;
	return true;
}

void CHero::update(float dt)
{
	
}

bool CHero::initKeyboard()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = [&](EventKeyboard::KeyCode k, Event* e) {
		switch (k)
		{
		case EventKeyboard::KeyCode::KEY_SPACE:
			_status = EHeroStatus::NORMAL_ATTACK;
			if (_hitStatus == EHitStatus::PERFECT)
			{
				runAction(Sequence::create(_animateHitPerfect, _animateRun, nullptr));
			}
			else
			{
				runAction(Sequence::create(_animateHitMiss, _animateRun, nullptr));
			}
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void CHero::setStatus(int status)
{
	_status = status;
}

void CHero::setHitStatus(int status)
{
	_hitStatus = status;
}

int CHero::getStatus()
{
	return _status;
}

int CHero::getHitStatus()
{
	return _hitStatus;
}

bool CHero::initAnimate()
{
	if (! (initAnimateRun() && initAnimateHitPerfect() && initAnimateHitGood() && initAnimateHitMiss()))
	{
		return false;
	}
	return true;
}

bool CHero::initAnimateHitPerfect()
{
	auto sp0 = Sprite::create(PNG_HERO1_01);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animateHitPerfect = Animate::create(Animation::createWithSpriteFrames(list, 0.1));
	_animateHitPerfect->retain();
	return true;
}

bool CHero::initAnimateHitGood()
{
	auto sp0 = Sprite::create(PNG_HERO1_02);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animateHitGood = Animate::create(Animation::createWithSpriteFrames(list, 0.1));
	_animateHitGood->retain();
	return true;
}

bool CHero::initAnimateHitMiss()
{
	auto sp0 = Sprite::create(PNG_HERO1_03);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animateHitMiss = Animate::create(Animation::createWithSpriteFrames(list, 0.1));
	_animateHitMiss->retain();
	return true;
}

bool CHero::initAnimateRun()
{
	auto sp0 = Sprite::create(PNG_HERO1_00);

	Vector<SpriteFrame*> list;
	list.pushBack(SpriteFrame::createWithTexture(sp0->getTexture(), sp0->getTextureRect()));

	_animateRun = Animate::create(Animation::createWithSpriteFrames(list, 0.1));
	_animateRun->retain();
	return true;
}

void CHero::updateAnimate(float dt)
{
	
}
