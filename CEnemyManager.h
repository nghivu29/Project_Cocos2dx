#pragma once
#include "cocos2d.h"
#include "CEnemy.h"
#include "CMusic.h"

class CEnemyManager
{
private:
	CEnemy** _enemies;
	float* positionY;
	CMusic* _music;

public:
	CEnemyManager();
	bool initEnemiesInScene(cocos2d::Scene* scene);
	void setMusic(CMusic* music);

	void setRandomPositionY(int i);
	void moveEnemy(int i);
	void resetEnemy(int i);
	CEnemy* getEnemy(int i);

};

