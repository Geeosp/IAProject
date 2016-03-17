#pragma once
#ifndef CALCULATEPATH_GOAL
#define CALCULATEPATH_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalCalculatePathTo
	:public GCompositeGoal
{
public:
	GGoalCalculatePathTo(BotController * _botControl, GGoalStatus goalStatus, Vect* target);
	~GGoalCalculatePathTo();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
	Vect* target;
};









#endif