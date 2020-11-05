#include "SceneGamePlay.h"

USING_NS_CC;

cocos2d::Scene * SceneGamePlay::createScene()
{
	return SceneGamePlay::create();
}

bool SceneGamePlay::init()
{
	if (!( Scene::init() && initBeatSlider() && initHero() && initEventListenerKeyboard()))
	{
		return false;
	}

	// loop test music
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch*, Event*) {
		Director::getInstance()->replaceScene(SceneGamePlay::createScene());
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

	return true;
}

void SceneGamePlay::update(float dt)
{
	_beatSlider->update(dt);
}

bool SceneGamePlay::initBeatSlider()
{
	US_VISIBLE;
	US_ORIGIN;
	_beatSlider = CBeatSlider::createSlider();
	_beatSlider->setPosition(origin.x + visibleSize.width * (1-BEATSLIDER_WIDTH_RATIO) / 2, origin.y + visibleSize.height * 0.8);
	addChild(_beatSlider);
	return true;
}

bool SceneGamePlay::initHero()
{
	US_ORIGIN;
	US_VISIBLE;
	_hero = CHero::create();
	_hero->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_hero->setPosition(origin.x + visibleSize.width*0.1f, origin.y + visibleSize.height*GROUND_HEIGHT_RATIO);
	this->addChild(_hero);
	return true;
}

/*
* Key Z: là NORMAL_ATTACK
* Key X: là STRONG_ATTACK
*/
bool SceneGamePlay::initEventListenerKeyboard()
{
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = [&](EventKeyboard::KeyCode k, Event* e) {
		_beatSlider->onKeyPressed(k, e);
		switch (_beatSlider->getHitStatus())
		{
		case EHitStatus::PERFECT:
			_hero->runAnimate(EHeroStatus::NORMAL_ATTACK, 0);
			break;
		case EHitStatus::GOOD:
			_hero->runAnimate(EHeroStatus::NORMAL_ATTACK, 1);
			break;
		case EHitStatus::MISS:
			_hero->runAnimate(EHeroStatus::NORMAL_ATTACK, 2);
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	return true;
}






