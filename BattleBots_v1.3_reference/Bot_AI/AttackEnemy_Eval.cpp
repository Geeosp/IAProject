#include "AttackEnemy_Eval.h"
#include "Goal_Funcs.h"
#include "GameManager.h"
#include "BotController.h"
#include "Goal_Think.h"

float AttackEnemy_Eval::CalculateDesirability(Bot * _bot)
{
	float Desirability = 0.0;

	//only do the calculation if there is a target present
	
	const float Tweaker = 1.0f;


	Desirability = Tweaker *
		Goal_Funcs::Health(_bot) *
		1 / Goal_Funcs::Health(GameManager::getEnemyHealth(_bot->getID()))
		* Goal_Funcs::TotalWeaponStrength(_bot);

	////bias the value according to the personality of the bot
	//Desirability *= biasValue;

	return Desirability;

}


void AttackEnemy_Eval::SetGoal(BotController * _control)
{
	_control->getBrain()->AddGoal_AttackEnemy();
}