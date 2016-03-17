#pragma once
#ifndef HUNT_GOAL
#define HUNT_GOAL

#include "GCompositeGoal.h"

class BotController;
enum GGoalStatus;

class GGoalHunt
	:public GCompositeGoal
{
public:
	GGoalHunt(BotController * _botControl, GGoalStatus goalStatus);
	~GGoalHunt();
	void activate();
	GGoalStatus process();
	void terminate();
	void  addSubGoal(GCompositeGoal * newGoal);
	char* toString();
private:
	int counter;
};









#endif