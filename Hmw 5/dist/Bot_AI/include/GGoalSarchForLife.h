#pragma once
#include "GCompositeGoal.h"

class GCompositeGoal;

class GGoalSarchForLife :
	public GCompositeGoal
{
public:
	GGoalSarchForLife(BotController * botControl, GGoalStatus goalStatus);
	~GGoalSarchForLife();
	void Activate();
	GGoalStatus Process();
	void Terminate();

};

