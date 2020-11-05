#pragma once
#include "cocos2d.h"
#include "CMusic.h"
#include "CBeatSprite.h"

enum EHitStatus
{
	PERFECT,
	GOOD,
	BAD,
	MISS,
	NOPE
};

class CBeatSlider : public cocos2d::Node
{
// thuộc tính
protected:
	CMusic* _music;
	cocos2d::Sprite* _spTarget;
	CBeatSprite** _spBeats;

	cocos2d::Label* _lbHitStatus;
	int _hitStatus;

private:
	// đây không phải thuộc tính
	float startFrame;

// phương thức
public:
	static CBeatSlider*  createSlider();
	void update(float dt);
	virtual bool init();

	// action
	void moveBeat(int i);
	void resetBeat(int i);

	// event listener
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);

	// getter
	int getHitStatus();

private:
	bool initSpTarget();
	bool initMusic();
	bool initSpBeats();
	bool initLbHitStatus();

	void updateMusic(float dt);
	void updateBeats(float dt);
	void updateStatus(float dt);
	
	void showHitStatus();
};

