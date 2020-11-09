﻿#pragma once
#include "CActor.h"

class CHero : public CActor
{
private:

public:
	virtual bool init();
	CREATE_FUNC(CHero);

	// gọi hero thực hiện animate; i vị trí được định nghị như bên dưới hàm initAnimates
	void runAnimate(EActorStatus status, int i);
	void runSkillAnimate(cocos2d::Animate* animate);
	void runJumpAnimate(cocos2d::Animate* animate);

	 
private:
	bool initAnimate();

	// các animate của NomalAttack
	bool initAnimatesNormalAttack(); // length = 3
	bool initAnimateNormalAttackPerfect(); // i = 0
	bool initAnimateNormalAttackGood(); // i = 1
	bool initAnimateNormalAttackMiss(); // i = 2

	// các animate của Run
	bool initAnimatesRun(); // length = 1
	bool initAnimateNormalRun(); // i = 0

	// các animate của Jump
	bool initAnimatesJump();
};

