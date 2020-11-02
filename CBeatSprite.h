#pragma once
#include "cocos2d.h"

class CBeatSprite : public cocos2d::Sprite
{
protected:
	// frame sprite create
	int _frameStart;
	int _frameTarget;

public:
	static CBeatSprite* createBeat();

	// getter
	int getFrameStart();
	int getFrameTarget();
	int getFrameMoving();

	// setter
	void setFrameStart(int frameStart);
	void setFrameTarget(int frameTarget);

	CREATE_FUNC(CBeatSprite);
protected:
	virtual bool init();
};

