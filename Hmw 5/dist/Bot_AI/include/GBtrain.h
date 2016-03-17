#pragma once
#ifndef GEEO_BRAIN
#define GEEO_BRAIN
#include <list>
#include "Bot.h"
#include "BotController.h"


using namespace std;

class GBtrain
{
public:
	GBtrain(Bot* bot, BotController* controller);
	~GBtrain();


private:
	Bot* bot;
	BotController * botController;

	float getBotLife();
	float getBotRifleAmno();
	float getBotLaserAmno();
	float getEnemyDistance();





};

#endif