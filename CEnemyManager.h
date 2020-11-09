#pragma once
#include "cocos2d.h"
#include "CEnemy.h"
#include "CBeatSlider.h"

class CEnemyManager
{
private:
	CEnemy** _enemies;
	float* positionY;
	CBeatSlider* _beatSlider;

public:
	CEnemyManager();
	bool initEnemiesInScene(cocos2d::Scene* scene);
	void updateEnemy();
	void setBeatSlider(CBeatSlider* beatSlider);

private:
	void setRandomPositionY(CEnemy* enemy);
	void moveEnemy(CEnemy* enemy);

};

