#include "CBeatSprite.h"
#include "common.h"

USING_NS_CC;

CBeatSprite * CBeatSprite::createBeat()
{
	return CBeatSprite::create();
}

int CBeatSprite::getFrameStart()
{
	return _frameStart;
}

int CBeatSprite::getFrameTarget()
{
	return _frameTarget;
}

int CBeatSprite::getFrameMoving()
{
	return getFrameTarget() - getFrameStart();
}


void CBeatSprite::setFrameStart(int frameStart)
{
	_frameStart = frameStart;
}

void CBeatSprite::setFrameTarget(int frameTarget)
{
	_frameTarget = frameTarget;
}

bool CBeatSprite::init()
{
	if (!Sprite::initWithFile(PNG_BEAT_HEART))
	{
		return false;
	}
	return true;
}
