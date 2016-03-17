#ifndef GOAL_H
#define GOAL_H

#include <assert.h>
#include "Goal_Types.h"

class BotController;
class Bot;

class Goal
{

public:
	Goal(BotController * _botControl, GOAL_TYPE _type, GOAL_STATUS _status);

	virtual ~Goal(){}

	virtual void Activate() = 0;
	virtual GOAL_STATUS Process() = 0;
	virtual void Terminate() = 0;

	virtual void AddSubGoal(Goal * _g)
	{
		(void)_g;
		// You did something wrong, override if you use it.
	}

	bool isComplete();
	bool isActive();
	bool isInactive();
	bool hasFailed();
	GOAL_TYPE getType();

protected:
	BotController * botControl;
	Bot * bot;
	GOAL_TYPE type;
	GOAL_STATUS status;

	//if m_iStatus = inactive this method sets it to active and calls Activate()
	void ActivateIfInactive();
	void ReactivateIfFailed();

};


#endif