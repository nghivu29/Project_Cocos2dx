#pragma once
#include "cocos2d.h"

class CSpGround : public cocos2d::Sprite
{
public:
	static cocos2d::Sprite* createSprite();
	virtual bool init();
	CREATE_FUNC(CSpGround);


private:
	void initBody();
};

