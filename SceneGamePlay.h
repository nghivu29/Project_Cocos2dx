#pragma once
#include "cocos2d.h"
#include "CMusic.h"
#include "CBeatSlider.h"

class SceneGamePlay : public cocos2d::Scene
{
private:
	CMusic* _music;
	CBeatSlider* _beatSlider;

public:
	//~SceneGamePlay();
	static cocos2d::Scene* createScene();
	
	virtual bool init();

	CREATE_FUNC(SceneGamePlay);
	void update(float dt);
	
private:
	bool initBeatSlider();
};

