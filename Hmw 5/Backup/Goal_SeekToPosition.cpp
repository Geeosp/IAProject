#include "Goal_SeekToPosition.h"
#include "Bot.h"

Goal_SeekToPosition::Goal_SeekToPosition(BotController * control, const Vect &vect, const float _stopDistance)
	: Goal(control, goal_seekToPosition, inactive)
{
	pos = new Vect(vect.X(), vect.Y(), 0.0f);
	stopDistance = _stopDistance;
}

Goal_SeekToPosition::~Goal_SeekToPosition()
{
	delete pos;
}

void Goal_SeekToPosition::Activate()
{
	status = active;
}


GOAL_STATUS Goal_SeekToPosition::Process()
{
	float dist = (*pos - bot->getPos()).magSqr();

	if (dist < stopDistance * stopDistance)
	{
		status = completed;
	}

	bot->MoveToPosition(*pos);

	return status;
}

void Goal_SeekToPosition::Terminate()
{

	status = completed;
}