#ifndef ATTACKENEMY_EVAL
#define ATTACKENEMY_EVAL


#include "Goal_Evaluator.h"
class BotController;
class Bot;

// Calculates the desirability on whether to attack the enemy
//
//	Calculation = MyHealth, EnemyHealth, MyTotalWeaponStrength
//

class AttackEnemy_Eval : public Goal_Evaluator
{
public:
	AttackEnemy_Eval(float bias) :Goal_Evaluator(bias){}

	float CalculateDesirability(Bot * _bot);

	void  SetGoal(BotController * _bot);

};





#endif