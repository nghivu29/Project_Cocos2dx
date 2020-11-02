#include "CSpGround.h"
USING_NS_CC;

cocos2d::Sprite * CSpGround::createSprite()
{
	auto spGround = Sprite::create();
	return nullptr;
}

bool CSpGround::init()
{
	if (Sprite::init())
	{
		return false;
	}

	// initialization physic body
	initBody();

	return true;
}

void CSpGround::initBody()
{
	// test luc nay director lúc này đã được khởi tạo chưa
	auto body = PhysicsBody::create();
}
