#include "Goal_MoveToPosition.h"
#include "BotController.h"
#include "Goal_SeekToPosition.h"

Goal_MoveToPosition::Goal_MoveToPosition(BotController * _control, const Vect &vect)
	: Goal_Composite(_control, GOAL_TYPE::goal_moveToPosition)
{
	Destination = new Vect(vect.X(), vect.Y(), 0.0f);


}

void Goal_MoveToPosition::Activate()
{
	status = active;

	RemoveAllSubGoals();

	botControl->CreatePathToPosition(bot->getPos(), *Destination);

	if (botControl->havePath())
	{
		Vect target = botControl->GetNextPosInPath();

		AddSubGoal(new Goal_SeekToPosition(botControl, target, 5.0f));
	}
	else
	{
		status = failed;
	}

}

GOAL_STATUS Goal_MoveToPosition::Process()
{
	ActivateIfInactive();

	status = ProcessSubGoals();

	if (!Arrived() && status == completed)
	{
		status = active;

		if (botControl->havePath())
		{
			Vect target = botControl->GetNextPosInPath();

			AddSubGoal(new Goal_SeekToPosition(botControl, target, 5.0f));
		}
		else
		{
			status = failed;
		}

	}

	ReactivateIfFailed();

	return status;


}


bool Goal_MoveToPosition::Arrived()
{
	bool output = false;

	const float stopDistance = 5.0f;

	float dest = (*Destination - bot->getPos()).magSqr();

	if (dest < stopDistance * stopDistance)
	{
		output = true;
	}

	return output;

}