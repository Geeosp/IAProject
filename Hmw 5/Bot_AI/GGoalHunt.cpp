
#include "GGoalHunt.h"
#include "GGoalCalculatePathTo.h"
#include "GGoalFollowPath.h"
#include "Item.h"
#include "Defs.h"


GGoalHunt::GGoalHunt(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::HUNT, goalStatus){
	activate();





}
GGoalHunt::~GGoalHunt(){

}


void GGoalHunt::activate(){
	DebugMsg::out("Activating: ");
	subGoals.clear();
	goalStatus = ACTIVE;
	Vect enemy = GameManager::getEnemyPos(botControl->getBotID());
	Vect* enemyPos = new Vect(enemy.X(), enemy.Y(),enemy.Z(), enemy.W());
	GGoalCalculatePathTo * calculatePath = new GGoalCalculatePathTo(botControl, GGoalStatus::INACTIVE, enemyPos);
	subGoals.push_back(calculatePath);
	GGoalFollowPath * followPath = new GGoalFollowPath(botControl, GGoalStatus::INACTIVE);
	subGoals.push_back(followPath);
	
		
}

GGoalStatus GGoalHunt::process()
{
	counter++;
	if (counter > 600){
		activate();
	}
	DebugMsg::out(toString());
	DebugMsg::out(": ");
	activateIfInactive();
	while (!subGoals.empty() && (subGoals.front()->isComplete() || subGoals.front()->hasFailed())){
		subGoals.pop_front();
	}
	if (goalStatus == ACTIVE && subGoals.empty()){
		goalStatus = COMPLETED;
	}
	else{
		GGoalStatus lastStatus = subGoals.front()->process();
		if (lastStatus == FAILED)
			goalStatus = FAILED;
	}
	Vect enemyPos = GameManager::getEnemyPos(botControl->getBotID());
	Vect pos = botControl->getBot()->getPos();
	float dist = (enemyPos - pos).mag();
	if (dist <= HUNTDISTANCE){
		goalStatus = COMPLETED;
	}


	return  goalStatus;
}


void GGoalHunt::terminate(){
	DebugMsg::out("terminating: ");
	DebugMsg::out(toString());
	DebugMsg::out("\n");
}
void GGoalHunt::addSubGoal(GCompositeGoal* newGoal){
	newGoal;
	subGoals.push_back(newGoal);
}
char* GGoalHunt::toString(){
	return "Get A Life";
}