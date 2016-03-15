#ifndef GOAL_MOVETOPOSITION_H
#define GOAL_MOVETOPOSITION_H

#include "Goal_Composite.h"
#include "Vect.h"
#include "Bot.h"

class Goal_MoveToPosition : public Goal_Composite
{

private:
	Vect * Destination;

	bool Arrived();

public:
	Goal_MoveToPosition(BotController * _control, const Vect &vect);

	void Activate();
	GOAL_STATUS Process();
	void Terminate(){};

};


#endif