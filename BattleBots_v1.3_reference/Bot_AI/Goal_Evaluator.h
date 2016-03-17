#ifndef GOAL_EVALUATOR_H
#define GOAL_EVALUATOR_H


class BotController;
class Bot;

class Goal_Evaluator
{
protected:

	//when the desirability score for a goal has been evaluated it is multiplied 
	//by this value. It can be used to create bots with preferences based upon
	//their personality
	float       biasValue;

public:

	Goal_Evaluator(float _biasValue) :biasValue(_biasValue){}

	virtual ~Goal_Evaluator(){}

	//returns a score between 0 and 1 representing the desirability of the
	//strategy the concrete subclass represents
	virtual float CalculateDesirability(Bot * pBot) = 0;

	//adds the appropriate goal to the given bot's brain
	virtual void  SetGoal(BotController * pControl) = 0;
};

#endif