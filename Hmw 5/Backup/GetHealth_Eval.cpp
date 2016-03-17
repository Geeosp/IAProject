#include "GetHealth_Eval.h"
#include "Goal_Funcs.h"

float GetHealth_Eval::CalculateDesirability(Bot * _bot)
{
	float Desirability = 1.0f;

	float distance = Goal_Funcs::DistanceToItem(_bot, HEALTH);


	if (distance != 1.0f)
	{
		//value used to tweak the desirability
		const float Tweaker = 0.2f;

		Desirability = Tweaker * (1 - Goal_Funcs::Health(_bot)) / (distance);

		Goal_Funcs::clamp(Desirability, 0, 1);
	}

	Desirability *= biasValue;

	return Desirability;

}


void GetHealth_Eval::SetGoal(BotController * _control)
{
	(void)_control;

}