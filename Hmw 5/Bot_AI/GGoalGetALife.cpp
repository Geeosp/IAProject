#include "GGoalGetALife.h"


GoalGetALife::GoalGetALife(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::SEARCHFORLIFE, goalStatus){

}
GoalGetALife::~GoalGetALife(){

}


void GoalGetALife::activate(){

}

void GoalGetALife::terminate(){

}

GGoalStatus GoalGetALife::process(){
	return  GGoalStatus::COMPLETED;
}

void GoalGetALife::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* GoalGetALife::toString(){
	return "Get A Life";
}