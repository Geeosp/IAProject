#pragma once
#ifndef GET_RIFLE_AMNO_GOAL
#define GET_RIFLE_AMNO_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalGetRifleAmno
	:public GCompositeGoal
{
public:
	GGoalGetRifleAmno(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalGetRifleAmno();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
};









#endif