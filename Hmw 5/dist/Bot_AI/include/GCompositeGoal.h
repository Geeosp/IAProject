#ifndef GGOAL_H
#define GGOAL_H

#include "GGoalTypes.h"
#include "Bot.h"
#include "BotController.h"
#include <list>

class BotController;
class Bot;
using namespace std;
class GCompositeGoal
{

public:
	GCompositeGoal(BotController * _botControl, GGoalType goalType, GGoalStatus goalStatus);

	virtual ~GCompositeGoal();

	virtual void Activate() = 0;
	virtual GGoalStatus Process() = 0;
	virtual void Terminate() = 0;

	void AddSubGoal(GCompositeGoal * newGoal);//ok
	bool isComplete();//ok
	bool isActive();//ok
	bool isInactive();//ok
	bool hasFailed();//ok
	GGoalType getType();

protected:
	BotController * botControl;
	Bot * bot;
	GGoalType type;
	GGoalStatus goalStatus;
	list<GCompositeGoal*>  subGoals;

};


#endif