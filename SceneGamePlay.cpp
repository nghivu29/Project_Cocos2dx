#include "SceneGamePlay.h"

USING_NS_CC;

cocos2d::Scene * SceneGamePlay::createScene()
{
	return SceneGamePlay::create();
}

bool SceneGamePlay::init()
{
	if (!( Scene::init() && initBeatSlider() && initHero()))
	{
		return false;
	}

	// set debug raw
	//this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

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
	updateHeroStatus(dt);
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

void SceneGamePlay::updateHeroStatus(float dt)
{
	_hero->setHitStatus(_beatSlider->getHitStatus());
}




