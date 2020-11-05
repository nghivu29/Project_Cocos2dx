#pragma once
#include "cocos2d.h"

// ve viet lai lop nay
// thiet ke bi sai roi

enum EHeroStatus
{
	NORMAL_ATTACK,
	STRONG_ATTACK,
	RUN
};

class CHero : public cocos2d::Sprite
{
private:
	// các danh sách cách các animate. Xếp theo thứ tự cấp độ đẹp giảm dần
	cocos2d::Vector <cocos2d::Animate*> _animatesNormalAttack;
	cocos2d::Vector <cocos2d::Animate*> _animatesStrongAttack;
	cocos2d::Vector <cocos2d::Animate*> _animatesRun;

public:
	virtual bool init();
	CREATE_FUNC(CHero);

	// gọi hero thực hiện animate; i vị trí được định nghị như bên dưới hàm initAnimates
	void runAnimate(EHeroStatus status, int i);
	void runSkillAnimate(cocos2d::Animate* animate);

	 
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
};

