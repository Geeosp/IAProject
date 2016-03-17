#pragma once
#ifndef GEEO_BRAIN
#define GEEO_BRAIN
#include <list>
//#include "Bot.h"

using namespace std;


class BotController;
class Bot;
//class BaseGoal;
class GCompositeGoal;



class GBrain
{
public:
	GBrain(Bot* bot, BotController* controller);
	~GBrain();
	void process();
	void think();

private:
	Bot* bot;
	BotController * botController;

	int getBotLife();
	int getBotRifleAmno();
	int getBotLaserAmno();

	int getBotRocketAmno();
	float getEnemyDistance();
	list<GCompositeGoal*> subgoals;
	void clearGoals();
	void changeToThisGoal(GCompositeGoal* newGoal);
	void queueGoal(GCompositeGoal* newGoal);
	bool enemyIsInBulletRange();
	bool enemyIsInSight();


};

#endif