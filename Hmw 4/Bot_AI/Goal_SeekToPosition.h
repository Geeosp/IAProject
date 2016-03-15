#ifndef GOAL_SEEKTOPOSITION_H
#define GOAL_SEEKTOPOSITION_H

#include "Goal.h"
#include "Vect.h"
class BotController;

class Goal_SeekToPosition : public Goal
{
private:
	Vect * pos;
	float stopDistance;

public:

	Goal_SeekToPosition(BotController * bot, const Vect &vect, const float _stopDistance);
	~Goal_SeekToPosition();

	//the usual suspects
	void Activate();
	GOAL_STATUS  Process();
	void Terminate();
};

#endif