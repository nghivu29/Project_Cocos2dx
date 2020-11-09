#pragma once
#include "CActor.h"

enum EEnemy
{
	SMALL_SPHERICAL_MONSTER
};

class CEnemy : public CActor
{
private:
	int _species;

public:
	static CEnemy* createSmallSphericalMonster();
	virtual bool init();
	CREATE_FUNC(CEnemy);

	// gọi hero thực hiện animate; i vị trí được định nghị như bên dưới hàm initAnimates
	void runAnimate(EActorStatus status, int i);
	void runSkillAnimate(cocos2d::Animate* animate);
	void runJumpAnimate(cocos2d::Animate* animate);


private:
	bool initAnimate();

	// các animate của NomalAttack
	bool initAnimatesNormalAttack(); // length = 3

	// các animate của Run
	bool initAnimatesRun(); // length = 1

	// các animate của Jump
	bool initAnimatesJump();
};
