#pragma once
#include "GCompositeGoal.h"
#include "GGoalTypes.h"

class BotController;
class GCompositeGoal;

class GGoalSearchForLife
	//:	public GCompositeGoal
{
public:
	GGoalSearchForLife(BotController * _botControl,  GGoalStatus goalStatus);
	~GGoalSearchForLife();
	void activate();
};

