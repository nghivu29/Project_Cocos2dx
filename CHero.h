#pragma once
#include "cocos2d.h"

// ve viet lai lop nay
// thiet ke bi sai roi

enum EHeroStatus
{
	NORMAL_ATTACK
};

class CHero : public cocos2d::Sprite
{
private:
	cocos2d::Animate* _animateHitPerfect;
	cocos2d::Animate* _animateHitGood;
	cocos2d::Animate* _animateHitMiss;
	cocos2d::Animate* _animateRun;

	int _status;
	int _hitStatus;

public:

	virtual bool init();

	void update(float dt);

	CREATE_FUNC(CHero);

	// setter
	void setStatus(int status);
	void setHitStatus(int status);

	// getter
	int getStatus();
	int getHitStatus();

private:
	bool initKeyboard();
	bool initAnimate();
	bool initAnimateHitPerfect();
	bool initAnimateHitGood();
	bool initAnimateHitMiss();
	bool initAnimateRun();

	void updateAnimate(float dt);
};

