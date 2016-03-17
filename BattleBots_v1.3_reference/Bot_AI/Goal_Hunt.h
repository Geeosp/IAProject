#ifndef GOAL_HUNT_H
#define GOAL_HUNT_H

#include "Goal_Composite.h"
#include "Vect.h"
#include "Bot.h"

class Goal_Hunt : public Goal_Composite
{

private:


public:
	Goal_Hunt(BotController * _control);

	void Activate();
	GOAL_STATUS Process();
	void Terminate(){};

};

#endif