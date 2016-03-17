#pragma once
#ifndef GET_LASER_AMNO_GOAL
#define GET_LASER_AMNO_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalGetLaserAmno
	:public GCompositeGoal
{
public:
	GGoalGetLaserAmno(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalGetLaserAmno();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
};









#endif