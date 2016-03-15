#include "Goal_Think.h"
#include "Goal_MoveToPosition.h"
#include "AttackEnemy_Eval.h"
#include "Goal_Attack.h"
#include "BotController.h"

Goal_Think::Goal_Think(BotController * _control) : Goal_Composite(_control, goal_think)
{
	botControl = _control;
	bot = _control->getBot();

	GoalEvaluators.push_back(new AttackEnemy_Eval(1.0f));

}

Goal_Think::~Goal_Think()
{
	std::vector<Goal_Evaluator*>::iterator it = GoalEvaluators.begin();
	for (it; it != GoalEvaluators.end(); ++it)
	{
		delete *it;
	}

}

void Goal_Think::Activate()
{

}

GOAL_STATUS Goal_Think::Process()
{
	ActivateIfInactive();

	GOAL_STATUS SubGoalStatus = ProcessSubGoals();

	if (SubGoalStatus == completed || SubGoalStatus == failed)
	{
		status = inactive;
	}
	
	return status;
}

void Goal_Think::Arbitrate()
{
	float best = 0;
	Goal_Evaluator * MostDesirable = 0;

	std::vector<Goal_Evaluator*>::iterator curDes = GoalEvaluators.begin();

	for(curDes; curDes != GoalEvaluators.end(); ++curDes)
	{
		float desirability = (*curDes)->CalculateDesirability(bot);

		if (desirability >= best)
		{
			best = desirability;
			MostDesirable = *curDes;
		}
	}

	MostDesirable->SetGoal(botControl);

}

bool Goal_Think::notPresent(GOAL_TYPE _type)
{
	bool isPresent = true;

	if (!SubGoalList.empty())
	{
		isPresent = SubGoalList.front()->getType() != _type;
	}

	return isPresent;

}


void Goal_Think::AddGoal_MoveToPosition(const Vect& _pos)
{
	AddSubGoal(new Goal_MoveToPosition(botControl, _pos));

}

void Goal_Think::AddGoal_AttackEnemy()
{
	if (notPresent(GOAL_TYPE::goal_attack))
	{
		AddSubGoal(new Goal_Attack(botControl));
	}
}