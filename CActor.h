#pragma once
#include "cocos2d.h"
#include "Weapon.h"

enum EActorStatus
{
	NORMAL_ATTACK,
	STRONG_ATTACK,
	RUN,
	JUMP
};

class CActor : public cocos2d::Sprite
{
protected:
	// các danh sách cách các animate. Xếp theo thứ tự cấp độ đẹp giảm dần
	cocos2d::Vector <cocos2d::Animate*> _animatesNormalAttack;
	cocos2d::Vector <cocos2d::Animate*> _animatesStrongAttack;
	cocos2d::Vector <cocos2d::Animate*> _animatesRun;
	cocos2d::Vector <cocos2d::Animate*> _animatesJump;

	// các thuộc tính của hero
	EWeapon _weapon;

public:
	virtual bool init();

	// gọi actor thực hiện animate; i vị trí được định nghị như bên dưới hàm initAnimates
	virtual void runAnimate(EActorStatus status, int i) = 0;
	virtual void runSkillAnimate(cocos2d::Animate* animate) = 0;
	virtual void runJumpAnimate(cocos2d::Animate* animate) = 0;


protected:
	virtual bool initAnimate() = 0;

	// các animate của NomalAttack
	virtual bool initAnimatesNormalAttack() = 0;

	// các animate của Run
	virtual bool initAnimatesRun() = 0;

	// các animate của Jump
	virtual bool initAnimatesJump() = 0;
};

