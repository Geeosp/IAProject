#include "GBrain.h"
#include "BotController.h"
#include "BaseGoal.h"

GBrain::GBrain(Bot* bot, BotController* controller)
{
	this->bot = bot;
	this->botController = controller;
}


GBrain::~GBrain()
{
}
void GBrain::think(){
	if (getBotLife() < 90){
		//GCompositeGoal* goal = new GCompositeGoal(botController, GGoalType::SEARCHFORLIFE, GGoalStatus::INACTIVE);
	BaseGoal* goal2 = new BaseGoal(botController, GGoalStatus::INACTIVE);
	//goal;
	goal2;
	changeToThisGoal(goal2);
		DebugMsg::out("Need to get a life\n");
	}
}

void GBrain::process(){
	if (!subgoals.empty()){
GCompositeGoal* currentGoal = subgoals.front();
	
currentGoal;
	
	
	}

}

int GBrain::getBotLife(){
	return bot->getHealth();
}
int GBrain::getBotRifleAmno(){
	return bot->getRifleAmmo();
}
int GBrain::getBotLaserAmno(){
	return  bot->getLaserAmmo();
}
int GBrain::getBotRocketAmno(){
	return bot->getRocketAmmo();
}
float GBrain::getEnemyDistance(){
	return (bot->getPos() - GameManager::getEnemyPos(bot->getID())).mag();
}
void GBrain::clearGoals(){
	subgoals.clear();
}
void GBrain::changeToThisGoal(GCompositeGoal* newGoal){
	subgoals.push_front(newGoal);
}
void GBrain::queueGoal(GCompositeGoal* newGoal){
	subgoals.push_back(newGoal);
}