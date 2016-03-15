#ifndef GETHEALTH_EVAL
#define GETHEALTH_EVAL


#include "Goal_Evaluator.h"
class Bot;
class BotController;


class GetHealth_Eval : public Goal_Evaluator
{
public:
	GetHealth_Eval(float bias) :Goal_Evaluator(bias){}

	float CalculateDesirability(Bot * _bot);

	void  SetGoal(BotController * _bot);

};





#endif