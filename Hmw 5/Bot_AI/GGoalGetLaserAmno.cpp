#include "GGoalGetLaserAmno.h"
#include "GGoalCalculatePathTo.h"
#include "GGoalFollowPath.h"
#include "Item.h"
GGoalGetLaserAmno::GGoalGetLaserAmno(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::SEARCHFORLASER, goalStatus){
	activate();





}
GGoalGetLaserAmno::~GGoalGetLaserAmno(){

}


void GGoalGetLaserAmno::activate(){
	DebugMsg::out("Activating: ");
	subGoals.clear();
	goalStatus = ACTIVE;
	std::vector<ItemDrop> items = GameManager::getItemDrops();
	bool found = false;
	for (unsigned int i = 0; i < items.size() && !found; i++){
		ItemDrop item = items[i];
		if (item.type == ITEM_TYPE::LASER_AMMO){
			Vect* itemPos = new Vect(item.pos.X(), item.pos.Y(), 0.f, 1.f);
			GGoalCalculatePathTo * calculatePath = new GGoalCalculatePathTo(botControl, GGoalStatus::INACTIVE, itemPos);
			subGoals.push_back(calculatePath);
			GGoalFollowPath * followPath = new GGoalFollowPath(botControl, GGoalStatus::INACTIVE);
			subGoals.push_back(followPath);
			found = true;
		}
	}
	if (!found){
		goalStatus = INACTIVE;
	}
}

GGoalStatus GGoalGetLaserAmno::process()
{
	DebugMsg::out(toString());
	DebugMsg::out(": ");
	activateIfInactive();
	while (!subGoals.empty() && (subGoals.front()->isComplete() || subGoals.front()->hasFailed())){
		subGoals.pop_front();
	}
	if (subGoals.empty()){
		goalStatus = COMPLETED;
	}
	else{
		GGoalStatus lastStatus = subGoals.front()->process();
		if (lastStatus == FAILED)
			goalStatus = FAILED;
	}

	return  goalStatus;
}


void GGoalGetLaserAmno::terminate(){

}
void GGoalGetLaserAmno::addSubGoal(GCompositeGoal* newGoal){
	newGoal;
	subGoals.push_back(newGoal);
}
char* GGoalGetLaserAmno::toString(){
	return "GetLaser";
}