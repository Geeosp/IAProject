#ifndef GOAL_WIN_H
#define GOAL_WIN_H

#include "Goal.h"
class Bot;

class Goal_Win : public Goal
{
private:

public:
	Goal_Win(Bot * _bot);

	void Activate();

	GOAL_STATUS Process();

	void Terminate();

};



#endif