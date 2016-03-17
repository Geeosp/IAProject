#pragma once
#ifndef GGOAL_H
#define GGOAL_H

#include <list>
#include "Bot.h"
#include "BotController.h"
#include "GGoalTypes.h"

using namespace std;
class Bot;
class BotController;



class GCompositeGoal
{
public:
	GCompositeGoal(BotController * _botControl, GGoalType goalType, GGoalStatus goalStatus);
	~GCompositeGoal();
	virtual void activate() = 0;
	virtual GGoalStatus process() = 0;
	virtual void terminate() = 0;
	virtual void  addSubGoal(GCompositeGoal * newGoal) = 0;
	/*
	*/
	bool isComplete();//ok
	bool isActive();//ok
	bool isInactive();//ok
	bool hasFailed();//ok
	GGoalType getType();//ok
	virtual char* toString()=0;
	void activateIfInactive();
protected:
	BotController * botControl;
	Bot * bot;
	GGoalType type;
	GGoalStatus goalStatus;
	list<GCompositeGoal*>  subGoals;

};


#endif