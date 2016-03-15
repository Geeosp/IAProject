#ifndef GOAL_ATTACKENEMY_H
#define GOAL_ATTACKENEMY_H

#include "Goal_Composite.h"
#include "Vect.h"
#include "Bot.h"

class Goal_AttackEnemy : public Goal_Composite
{

private:
	Vect * Destination;

	bool Arrived();

public:
	Goal_AttackEnemy(BotController * _control);

	void Activate();
	GOAL_STATUS Process();
	void Terminate(){};

};

#endif

