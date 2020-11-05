#include "CBeatSlider.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

CBeatSlider * CBeatSlider::createSlider()
{
	CBeatSlider* beatSlider = new CBeatSlider();
	if (!beatSlider->init())
	{
		return beatSlider;
	}
	// code dưới đây sẽ chạy nếu khởi tạo thành công

	return beatSlider;
}

void CBeatSlider::update(float dt)
{
	updateMusic(dt);
	updateBeats(dt);
}

bool CBeatSlider::init()
{
	// init sp target
	if (! (initMusic() && initSpTarget() && initSpBeats() && initLbHitStatus()) )
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = [&](EventKeyboard::KeyCode k, Event* e) {
		onKeyPressed(k, e); 
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}

// move sprite beat to sprite target with duration = sencond/measume
void CBeatSlider::moveBeat(int i)
{
	float duration = _music->getSecondPerMeasume();
	auto moveInTime = MoveTo::create(duration, _spTarget->getPosition());
	auto moveOver = MoveTo::create(BEATSLIDER_OVER_TIME, _spTarget->getPosition() - Vec2(BEATSLIDER_OVER_SPACE, 0));
	auto sequence = Sequence::create(moveInTime, moveOver, nullptr);
	_spBeats[i]->runAction(sequence);
}

void CBeatSlider::resetBeat(int i)
{
	US_VISIBLE;
	_spBeats[i]->setPosition(visibleSize.width*BEATSLIDER_WIDTH_RATIO, 0);
	_spBeats[i]->setFrameStart(startFrame);
	_spBeats[i]->setFrameTarget(startFrame += _music->getFramePerMeasume());
	_spBeats[i]->stopAllActions();
}

int CBeatSlider::getHitStatus()
{
	return _hitStatus;
}

bool CBeatSlider::initSpTarget()
{
	_spTarget = Sprite::create(PNG_SLIDER_TARGET);
	//_spTarget = Sprite::create("img/all_pet_5223.png");

	_spTarget->setPosition(Vec2(0, 0));
	_spTarget->setScale((float)1 / 10);
	addChild(_spTarget, 0);
	return true;
}

// init test music
bool CBeatSlider::initMusic()
{
	_music = CMusic::create(TEST_MUSIC, 120, 1);
	_music->setBeatDelay(3);
	return true;
}

// must call affer init music
bool CBeatSlider::initSpBeats()
{
	US_VISIBLE;
	_spBeats = new CBeatSprite*[BEATSLIDER_CAPACITY];
	startFrame = _music->getFrameDelay();
	for (size_t i = 0; i < BEATSLIDER_CAPACITY; i++)
	{
		_spBeats[i] = CBeatSprite::createBeat();
		_spBeats[i]->setFrameStart(startFrame);
		_spBeats[i]->setFrameTarget(startFrame += _music->getFramePerMeasume());
		_spBeats[i]->setPosition(visibleSize.width*BEATSLIDER_WIDTH_RATIO, 0);
		_spBeats[i]->setScale((float)1 / 15);
		addChild(_spBeats[i], 1);
	}
	return true;
}

bool CBeatSlider::initLbHitStatus()
{
	_lbHitStatus = Label::createWithTTF("nope", TTF_MARKER_FELT, 30);
	_lbHitStatus->setPosition(0, -_spTarget->getContentSize().height * _spTarget->getScale() * 0.5 - 10);
	addChild(_lbHitStatus, 3);
	return true;
}

void CBeatSlider::updateMusic(float dt)
{
	if (!_music->isPlaying())
	{
		_music->playMusic();
	}
	_music->update(dt);
}

void CBeatSlider::updateBeats(float dt)
{
	US_VISIBLE;
	for (size_t i = 0; i < BEATSLIDER_CAPACITY; i++)
	{
		if (_music->getFrame() == _spBeats[i]->getFrameStart())
		{
			moveBeat(i);
		}

		if (_music->getFrame() == _spBeats[i]->getFrameTarget() + 20)
		{
			resetBeat(i);
		}
	}

}

void CBeatSlider::updateStatus(float dt)
{
	_hitStatus = EHitStatus::MISS;
	for (size_t i = 0; i < BEATSLIDER_CAPACITY; i++)
	{
		if (_spBeats[i]->getBoundingBox().containsPoint(_spTarget->getPosition()))
		{
			_hitStatus = EHitStatus::PERFECT;
		}
		else if (_spBeats[i]->getBoundingBox().intersectsRect(_spTarget->getBoundingBox()))
		{
			_hitStatus = EHitStatus::GOOD;
		}
	}
}

void CBeatSlider::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event *)
{
	/*switch (key)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
		SimpleAudioEngine::getInstance()->playEffect(WAV_BEAT);
		updateStatus(0);
		showHitStatus();
		break;
	default:
		break;
	}*/
	SimpleAudioEngine::getInstance()->playEffect(WAV_BEAT);
	updateStatus(0);
	showHitStatus();
}

void CBeatSlider::showHitStatus()
{
	_lbHitStatus->setOpacity(255);
	switch (_hitStatus)
	{
	case EHitStatus::PERFECT:
		_lbHitStatus->setString("perfect");
		break;
	case EHitStatus::GOOD:
		_lbHitStatus->setString("good");
		break;
	case EHitStatus::BAD:
		_lbHitStatus->setString("bad");
		break;
	case EHitStatus::MISS:
		_lbHitStatus->setString("miss");
		break;
	case EHitStatus::NOPE:
		_lbHitStatus->setString("nope");
		break;
	default:
		break;
	}
	_lbHitStatus->runAction(FadeOut::create(1));

}


