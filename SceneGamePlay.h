#pragma once
#include "cocos2d.h"
#include "CMusic.h"
#include "CBeatSlider.h"
#include "CHero.h"
#include "CEnemyManager.h"

class SceneGamePlay : public cocos2d::Scene
{
private:
	CMusic* _music;
	CBeatSlider* _beatSlider;
	CHero* _hero;
	CEnemyManager* enemyManager;

public:
	//~SceneGamePlay();
	static cocos2d::Scene* createScene();
	
	virtual bool init();

	CREATE_FUNC(SceneGamePlay);
	void update(float dt);
	
private:
	bool initBeatSlider();
	bool initHero();
	bool initEnemies();
	bool initEventListenerKeyboard();
	
	void onNomarlAttackKeyPress();
	void onStrongAttackKeyPress();
	void onJumpKeyPress();

};

