#ifndef GOAL_COMPOSITE_H
#define GOAL_COMPOSITE_H


#include <list>
#include "Goal.h"

class Goal_Composite : public Goal
{

	
protected:
	std::list<Goal * > SubGoalList;

	GOAL_STATUS ProcessSubGoals();

public:
	Goal_Composite(BotController * _botControl, GOAL_TYPE _type);

	virtual ~Goal_Composite();

	void RemoveAllSubGoals();
	void AddSubGoal(Goal * _g);

	virtual void Activate() = 0;
	virtual GOAL_STATUS Process() = 0;
	virtual void Terminate() = 0;


};


#endif

