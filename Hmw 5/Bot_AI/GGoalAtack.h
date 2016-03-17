#pragma once
#ifndef ATACK_GOAL
#define ATACK_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalAtack
	:public GCompositeGoal
{
public:
	GGoalAtack(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalAtack();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
};


#endif