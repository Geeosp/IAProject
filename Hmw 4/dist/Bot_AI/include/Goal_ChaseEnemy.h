#ifndef GOAL_CHASEENEMY_H
#define GOAL_CHASEENEMY_H

#include "Goal_Composite.h"
#include "Vect.h"
#include "Bot.h"

class Goal_ChaseEnemy : public Goal_Composite
{

private:

public:
	Goal_ChaseEnemy(BotController * _control);

	void Activate();
	GOAL_STATUS Process();
	void Terminate(){};

};

#endif

