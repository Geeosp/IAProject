#pragma once
#ifndef FOLLOWPATH_GOAL
#define FOLLOW_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalFollowPath
	:public GCompositeGoal
{
public:
	GGoalFollowPath(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalFollowPath();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
};









#endif