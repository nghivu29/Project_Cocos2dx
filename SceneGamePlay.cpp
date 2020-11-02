#include "SceneGamePlay.h"

USING_NS_CC;

cocos2d::Scene * SceneGamePlay::createScene()
{
	return SceneGamePlay::create();
}

bool SceneGamePlay::init()
{
	if (!( Scene::init() && initBeatSlider() ))
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




