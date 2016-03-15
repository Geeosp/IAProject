#ifndef GOAL_THINK_H
#define GOAL_THINK_H

#include "Goal_Composite.h"
#include "Goal_Evaluator.h"
#include "Bot.h"
#include <vector>

class Goal_Think : public Goal_Composite
{

private:
	std::vector<Goal_Evaluator *> GoalEvaluators;

	Bot * bot;

public:
	Goal_Think(BotController * _botControl);
	~Goal_Think();

	//this method iterates through each goal evaluator and selects the one
	//that has the highest score as the current goal
	void Arbitrate();

	//the usual suspects
	GOAL_STATUS  Process();
	void Activate();
	void Terminate(){}


	void AddGoal_MoveToPosition(const Vect& _pos);
	void AddGoal_AttackEnemy();



	//returns true if the given goal is not at the front of the subgoal list
	bool notPresent(GOAL_TYPE _type);
};



#endif


