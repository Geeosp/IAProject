#pragma once
#include "GCompositeGoal.h"
class GCompositeGoal;




class GoalSearchForLife :
	public GCompositeGoal
{
public:
	GoalSearchForLife(BotController * botControl, GGoalStatus goalStatus);
	~GoalSearchForLife();
	/*
	void activate();
	 GGoalStatus process();
	 void terminate();
	 void  addSubGoal(GCompositeGoal * newGoal);
	 */
	 };

