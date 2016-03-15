#include "Goal_Composite.h"

Goal_Composite::Goal_Composite(BotController * _botControl, GOAL_TYPE _type)
	: Goal(_botControl, _type, GOAL_STATUS::inactive)
{}

Goal_Composite::~Goal_Composite()
{

}

void Goal_Composite::RemoveAllSubGoals()
{
	for (std::list<Goal *>::iterator it = SubGoalList.begin(); it != SubGoalList.end(); ++it)
	{
		(*it)->Terminate();

		delete *it;
	}

	SubGoalList.clear();
}

void Goal_Composite::AddSubGoal(Goal * _g)
{
	SubGoalList.push_back(_g);
}

GOAL_STATUS Goal_Composite::ProcessSubGoals()
{

	//remove all completed and failed goals from the front of the subgoal list
	while (!SubGoalList.empty())
	{
		if (SubGoalList.front()->isComplete() || SubGoalList.front()->hasFailed())
		{
			SubGoalList.front()->Terminate();
			delete SubGoalList.front();
			SubGoalList.pop_front();
		}
		else
		{
			break;
		}
	}

	//if any subgoals remain, process the one at the front of the list
	if (!SubGoalList.empty())
	{
		//grab the status of the front-most subgoal
		GOAL_STATUS StatusOfSubGoals = SubGoalList.front()->Process();

		//we have to test for the special case where the front-most subgoal
		//reports 'completed' *and* the subgoal list contains additional goals.When
		//this is the case, to ensure the parent keeps processing its subgoal list
		//we must return the 'active' status.
		if (StatusOfSubGoals == completed && SubGoalList.size() > 1)
		{
			status = active;
		}

	}
	else
	{
		status = completed;
	}


	return status;
}