#include "GGoalGetALife.h"
#include "GGoalCalculatePathTo.h"
#include "Item.h"
GoalGetALife::GoalGetALife(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::SEARCHFORLIFE, goalStatus){
	activate();





}
GoalGetALife::~GoalGetALife(){

}


void GoalGetALife::activate(){
	subGoals.clear();
	std::vector<ItemDrop> items = GameManager::getItemDrops();
	for (unsigned int i = 0; i < items.size(); i++){
		ItemDrop item = items[i];
		if (item.type == HEALTH){
			Vect* itemPos = new Vect(item.pos.X(), item.pos.Y(),0.f,1.f);
			GGoalCalculatePathTo * calculatePath = new GGoalCalculatePathTo(botControl, GGoalStatus::INACTIVE, itemPos);
			subGoals.push_back(calculatePath);
		}
	}

}

GGoalStatus GoalGetALife::process()
{
	DebugMsg::out("Processing");
	DebugMsg::out(toString());
	DebugMsg::out("\n");

	activateIfInactive();

	while (!subGoals.empty())
	{
		if (subGoals.front()->isComplete() || subGoals.front()->hasFailed())
		{
			subGoals.front()->terminate();
			delete subGoals.front();
			subGoals.pop_front();
		}
		else
		{
			break;
		}
	}

	if (subGoals.empty()){
		goalStatus = COMPLETED;
	}else{
		goalStatus = subGoals.front()->process();
	}
	DebugMsg::out(toString());
	DebugMsg::out("Processed");
	DebugMsg::out("\n");
	return  goalStatus;
}


void GoalGetALife::terminate(){

}
void GoalGetALife::addSubGoal(GCompositeGoal* newGoal){
	newGoal;
	subGoals.push_back(newGoal);
}
char* GoalGetALife::toString(){
	return "Get A Life";
}