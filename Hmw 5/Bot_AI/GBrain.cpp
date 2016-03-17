#include "GBrain.h"
#include "BotController.h"
#include "BaseGoal.h"
#include "GGoalGetALife.h"
#include "GGoalGetLaserAmno.h"
#include "GGoalGetRifleAmno.h"
#include "GGoalAtack.h"
#include "GGoalHunt.h"
#include "GGoalWander.h"
#include "Defs.h"
#include "GGoalTypes.h"
#include <list>
using namespace std;

GBrain::GBrain(Bot* bot, BotController* controller)
{
	this->bot = bot;
	this->botController = controller;
	GGoalAtack* goal = new GGoalAtack(botController, GGoalStatus::ACTIVE);
	parallelgoals.push_back(goal);
}


GBrain::~GBrain()
{
}
void GBrain::think(){
	DebugMsg::out("Thinking\n");
	std::vector<ItemDrop> items = GameManager::getItemDrops();
	//bool found = false;
	bool hasHealth = false;
	bool hasRiffle = false;
	bool hasLaser = false;

	for (unsigned int i = 0; i < items.size(); i++){
		ItemDrop item = items[i];
		if (item.type == ITEM_TYPE::HEALTH){
			hasHealth = true;
		}
		else if (item.type == ITEM_TYPE::RIFLE_AMMO){
			hasRiffle = true;
		}
		else if (item.type == ITEM_TYPE::LASER_AMMO){
			hasLaser = true;
		}
	}
	if (!hasLaser&&!hasRiffle&&!hasHealth){
		if (getEnemyDistance() > HUNTDISTANCE){
			GGoalHunt* goal = new GGoalHunt(botController, GGoalStatus::ACTIVE);
			changeToThisGoal(goal);
		}
		else{
		GGoalWander* goal = new GGoalWander(botController, GGoalStatus::ACTIVE);
		changeToThisGoal(goal);
		}
	}
	if (hasLaser){
		GGoalGetLaserAmno* goal = new GGoalGetLaserAmno(botController, GGoalStatus::INACTIVE);
		changeToThisGoal(goal);
	}
	if (hasRiffle){
		GGoalGetRifleAmno* goal = new GGoalGetRifleAmno(botController, GGoalStatus::INACTIVE);
		changeToThisGoal(goal);
	}
	if (hasHealth){
		if (getBotLife() <= 50||getBotLife()<GameManager::getEnemyHealth(bot->getID())){
			GoalGetALife* goal = new GoalGetALife(botController, GGoalStatus::INACTIVE);
			changeToThisGoal(goal);
		}
		else if (getBotLife() <= 100){
			GoalGetALife* goal = new GoalGetALife(botController, GGoalStatus::INACTIVE);
			queueGoal(goal);
		}
	}
	
}

void GBrain::process(){


	
	if (!subgoals.empty()){
		GCompositeGoal* currentGoal = subgoals.front();
		currentGoal->process();
		if (currentGoal->isComplete() || currentGoal->hasFailed()){
			currentGoal->terminate();
			subgoals.pop_front();
		}
		
	}
	else{
		think();
	}
	for (unsigned int i = 0; i < parallelgoals.size(); i++){
		parallelgoals.at(i)->process();
	}
	DebugMsg::out("\n");
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

	if (subgoals.empty()){
		subgoals.push_front(newGoal);	
		DebugMsg::out("Adding ");
		DebugMsg::out(newGoal->toString());
		DebugMsg::out("\n");
	}else if (subgoals.front()->getType() != newGoal->getType()){
		subgoals.front()->desactivate();
		subgoals.push_front(newGoal);
		DebugMsg::out("Adding ");
		DebugMsg::out(newGoal->toString());
		DebugMsg::out("\n");
	}
	

}
void GBrain::queueGoal(GCompositeGoal* newGoal){//ok
	subgoals.push_back(newGoal);
	DebugMsg::out("Queueing ");
	DebugMsg::out(newGoal->toString());
	DebugMsg::out("\n");
}
bool GBrain::enemyIsInBulletRange(){//ok
	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	Vect botPos = bot->getPos();
	return (getEnemyDistance() <= PISTOLFIRERANGE);
}
bool GBrain::enemyIsInSight(){//ok
	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	Vect botPos = bot->getPos();
	return GameManager::isPathObstructed(bot->getID(), enemyPos, botPos);
}
