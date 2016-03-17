#pragma once
#ifndef GEEO_BRAIN
#define GEEO_BRAIN
#include <list>
//#include "Bot.h"

using namespace std;


class BotController;
class Bot;
class GCompositeGoal;
class BaseGoal;



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




};

#endif