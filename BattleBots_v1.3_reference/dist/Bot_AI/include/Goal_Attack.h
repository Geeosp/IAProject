#ifndef GOAL_ATTACK_H
#define GOAL_ATTACK_H

#include "Goal_Composite.h"
#include "Vect.h"
#include "Bot.h"

class Goal_Attack : public Goal_Composite
{

private:

public:
	Goal_Attack(BotController * _control);

	void Activate();
	GOAL_STATUS Process();
	void Terminate(){};

};

#endif