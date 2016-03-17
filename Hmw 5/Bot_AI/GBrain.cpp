#include "GBrain.h"
#include "BotController.h"
#include "BaseGoal.h"
#include "GGoalGetALife.h"
#include "Defs.h"




GBrain::GBrain(Bot* bot, BotController* controller)
{
	this->bot = bot;
	this->botController = controller;
}


GBrain::~GBrain()
{
}
void GBrain::think(){
	DebugMsg::out("Thinking\n");

	if (getBotLife() > 60){
		//TODO:add hunt enemy		
	}
	else{
		if (getBotLife() < 60){
			GoalGetALife* goal = new GoalGetALife(botController, GGoalStatus::INACTIVE);
			changeToThisGoal(goal);
			DebugMsg::out("Need to get a life\n");
		}
	}
	if (enemyIsInBulletRange()){
		//fireBullet;
	}
}

void GBrain::process(){
	if (!subgoals.empty()){
	GCompositeGoal* currentGoal = subgoals.front();
	currentGoal;
	DebugMsg::out(currentGoal->toString());
	DebugMsg::out("\n");

	}
}

int GBrain::getBotLife(){//ok
	return bot->getHealth();
}
int GBrain::getBotRifleAmno(){//ok
	return bot->getRifleAmmo();
}
int GBrain::getBotLaserAmno(){//ok
	return  bot->getLaserAmmo();
}
float GBrain::getEnemyDistance(){//ok
	return (bot->getPos() - GameManager::getEnemyPos(bot->getID())).mag();
}
void GBrain::clearGoals(){//ok
	subgoals.clear();
}
void GBrain::changeToThisGoal(GCompositeGoal* newGoal){//ok
	subgoals.push_front(newGoal);
}
void GBrain::queueGoal(GCompositeGoal* newGoal){//ok
	subgoals.push_back(newGoal);
}
bool GBrain::enemyIsInBulletRange(){//ok
	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	Vect botPos = bot->getPos();
	return (getEnemyDistance() <= BULLETFIRERANGE);
}
bool GBrain::enemyIsInSight(){//ok
	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	Vect botPos = bot->getPos();
	return GameManager::isPathObstructed(bot->getID(), enemyPos, botPos);
}
