#include "Goal.h"
#include "BotController.h"
#include "Bot.h"

Goal::Goal(BotController * _botController, GOAL_TYPE _type, GOAL_STATUS _status)
{
	botControl = _botController;
	bot = botControl->getBot();
	type = _type;
	status = _status;

}

bool Goal::isComplete()
{
	return (status == GOAL_STATUS::completed);
}

bool Goal::isActive()
{
	return (status == GOAL_STATUS::active);
}

bool Goal::hasFailed()
{
	return (status == GOAL_STATUS::failed);
}

bool Goal::isInactive()
{
	return (status == GOAL_STATUS::inactive);
}

GOAL_TYPE Goal::getType()
{
	return type;
}

void Goal::ActivateIfInactive()
{
	if (isInactive())
	{
		Activate();
	}

}

void Goal::ReactivateIfFailed()
{
	if (hasFailed())
	{
		status = inactive;
	}

}