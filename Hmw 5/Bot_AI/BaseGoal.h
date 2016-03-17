#pragma once
#ifndef BASE_GOAL
#define BASE_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class BaseGoal
	:public GCompositeGoal
{
public:
	BaseGoal(BotController * _botControl, GGoalStatus goalStatus);
	~BaseGoal();
	 void activate();
	GGoalStatus process();
	void terminate() ;
	 void  addSubGoal(GCompositeGoal * newGoal);
	 char* toString();
};









#endif