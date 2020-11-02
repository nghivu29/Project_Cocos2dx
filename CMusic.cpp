#include "CMusic.h"

USING_NS_CC;
//using namespace cocos2d::experimental;
using namespace CocosDenshion;

void CMusic::update(float dt)
{
	_fps = 1/dt;
	_frame++;
	count++;
	updateBeat(dt); 
}


bool CMusic::isPlaying()
{
	return _playing;
}

void CMusic::setFrameDelay(int frame)
{
	_frameDelay = frame;
}

void CMusic::setBeatDelay(int beat)
{
	setFrameDelay( _bpm / 60 * _fps * beat );
}

void CMusic::setMeasumes(int measumes)
{
	_measures = measumes;
}

int CMusic::getFrameDelay()
{
	return _frameDelay;
}

float CMusic::getBeatDelay()
{
	return (float) _frameDelay / (_bpm/60 * _fps);
}

int CMusic::getMeasumes()
{
	return _measures;
}

int CMusic::getFrame()
{
	return _frame;
}

float CMusic::getFramePerMeasume()
{
	return (_fps*(_bpm/60)) / _measures;
}

float CMusic::getSecondPerMeasume()
{
	return this->getFramePerMeasume() / _fps;
}

bool CMusic::init()
{
	log("init sussection");

	return true;
}

CMusic * CMusic::create(cocos2d::String fileName, float bpm)
{
	return new CMusic(fileName, bpm);
}



CMusic * CMusic::create(cocos2d::String fileName, float bpm, int measures)
{
	return new CMusic(fileName, bpm, measures);
}

void CMusic::playMusic()
{
	try
	{
		//int audio_id = AudioEngine::play2d(_musicFileName.getCString());
		//AudioEngine::setVolume(audio_id, 1.0f);
		
		SimpleAudioEngine::getInstance()->playBackgroundMusic(_musicFileName.getCString());
		_playing = true;
	}
	catch (const std::exception&)
	{
		log("%s %d", "My error: can't load", _musicFileName.getCString());
	}
}


CMusic::CMusic()
{
	_beat = 0;
	_measure = 0;
	_frame = 0;
	count = 0;
	_fps = 60;
	_bpm = 120;
	_frameDelay = 0;
	_playing = false;
}

CMusic::CMusic(cocos2d::String fileName, int bpm, int measures, float fps) : CMusic()
{
	_musicFileName = fileName;
	_bpm = bpm;
	_fps = fps;
	_measures = measures;
}

void CMusic::updateBeat(float dt)
{
	float bps = _bpm / 60;
	if (_frame >= _frameDelay)
	{
		if (_frame == 1)
		{
			_measure++;
			//playEffectMeasure();
			log("clap2");
		}
		if ((count >= _fps * bps / _measures))
		{
			_measure++;
			count = 0;
			//playEffectMeasure();
			log("clap");

		}
	}
	
	// code end of method
	if (_measure > _measures)
	{
		_beat++;
		_measure = 0;
		//playEffectBeat();
	}

	log(" frame:%d\n measume: %d\n count: %d\n\n",_frame, _measure, count);
}

void CMusic::playEffectBeat()
{
	try
	{
		SimpleAudioEngine::getInstance()->playEffect(WAV_BEAT);
	}
	catch (const std::exception& e)
	{
		log("%s %s", "My error: can't load", WAV_BEAT);
	}
}

void CMusic::playEffectMeasure()
{
	try
	{
		SimpleAudioEngine::getInstance()->playEffect(WAV_BEAT);
	}
	catch (const std::exception& e)
	{
		log("%s %s", "My error: can't load", WAV_BEAT);
	}
}

