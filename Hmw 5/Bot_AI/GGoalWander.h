#pragma once
#ifndef WANDER_GOAL
#define WANDER_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalWander
	:public GCompositeGoal
{
public:
	GGoalWander(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalWander();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
private:
	 int  myangle;
};









#endif