#include "BaseGoal.h"

BaseGoal::BaseGoal(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::SEARCHFORLIFE, goalStatus){

}
BaseGoal::~BaseGoal(){

}


void BaseGoal::activate(){

}

void BaseGoal::terminate(){

}

GGoalStatus BaseGoal::process(){
	return  GGoalStatus::COMPLETED;
}

void BaseGoal::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* BaseGoal::toString(){
	return "Base_Goal";
}