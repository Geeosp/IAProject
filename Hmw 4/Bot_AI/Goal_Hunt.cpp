#include "Goal_Hunt.h"
#include "GameManager.h"
#include "BotController.h"
#include "Goal_MoveToPosition.h"

Goal_Hunt::Goal_Hunt(BotController * _control)
	: Goal_Composite(_control, GOAL_TYPE::goal_huntEnemy)
{

}

void Goal_Hunt::Activate()
{
	status = active;

	Vect enemyPos = GameManager::getEnemyPos(bot->getID());

	AddSubGoal(new Goal_MoveToPosition(botControl, enemyPos));

}


GOAL_STATUS Goal_Hunt::Process()
{
	ActivateIfInactive();

	status = ProcessSubGoals();

	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	bool canSeeEnemy = !GameManager::isPathObstructed(bot->getID(), bot->getPos(), enemyPos);

	if (canSeeEnemy)
	{
		status = completed;
	}

	return status;
}