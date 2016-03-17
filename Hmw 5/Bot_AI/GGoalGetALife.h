#pragma once
#ifndef GET_A_LIFE_GOAL
#define GET_A_LIFE_BASE_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GoalGetALife
	:public GCompositeGoal
{
public:
	GoalGetALife(BotController * _botControl, GGoalStatus goalStatus);
	~GoalGetALife();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
};









#endif