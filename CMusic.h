#pragma once

#include "cocos2d.h"
//#include "AudioEngine.h"
#include "SimpleAudioEngine.h"
#include "common.h"


class CMusic
{
private:
	// count
	int _beat; 
	int _measure;
	int _frame;
	int count;

	// max measures
	int _measures;

	// durring frames don't play effect
	int _frameDelay;

	// per time
	float _bpm; // beats per minute
	float _fps; // frames per second

	// name file background music
	cocos2d::String _musicFileName;

	// is background music playing ?
	bool _playing;

public:
	virtual bool init();
	static CMusic* create(cocos2d::String fileName, float bpm);
	static CMusic* create(cocos2d::String fileName, float bpm, int measures);
	void playMusic();
	void update(float dt);
	bool isPlaying();

	// setter
	void setFrameDelay(int frame);
	void setBeatDelay(int beat);
	void setMeasumes(int measumes);

	// getter
	int getFrameDelay();
	float getBeatDelay();
	int getMeasumes();
	int getFrame();
	float getFramePerMeasume();
	float getSecondPerMeasume();


private:
	CMusic();

	// if fps, bpm don't sync, beats don't sync
	CMusic(cocos2d::String fileName, int bpm, int measure = 4, float fps = 60);

	void updateBeat(float dt);

	void playEffectBeat();
	void playEffectMeasure();

	
};

