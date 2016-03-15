#include "Goal_Attack.h"
#include "GameManager.h"
#include "BotController.h"
#include "Goal_Hunt.h"
#include "Goal_SeekToPosition.h"

Goal_Attack::Goal_Attack(BotController * _control)
	: Goal_Composite(_control, GOAL_TYPE::goal_attack)
{

}

void Goal_Attack::Activate()
{
	status = active;

	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	bool canSeeEnemy = !GameManager::isPathObstructed(bot->getID(), bot->getPos(), enemyPos);

	if (canSeeEnemy)
	{
		AddSubGoal(new Goal_SeekToPosition(botControl, enemyPos, 50.0f));
	}
	else
	{
		AddSubGoal(new Goal_Hunt(botControl));
	}


}


GOAL_STATUS Goal_Attack::Process()
{
	ActivateIfInactive();

	//process the subgoals
	status = ProcessSubGoals();

	ReactivateIfFailed();

	return status;
}