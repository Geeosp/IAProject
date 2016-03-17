#include "GCompositeGoal.h"



GCompositeGoal::GCompositeGoal(BotController * botControl, GGoalType goalType, GGoalStatus goalStatus){
	this->botControl = botControl;
	this-> type= goalType;
	this->goalStatus = goalStatus;
}
GCompositeGoal::	~GCompositeGoal(){

}

bool GCompositeGoal::isComplete(){
	return goalStatus == GGoalStatus::COMPLETED;
}
bool GCompositeGoal::isActive(){
	return goalStatus == GGoalStatus::ACTIVE;
}
bool GCompositeGoal::isInactive(){
	return goalStatus == GGoalStatus::INACTIVE;
}
bool GCompositeGoal::hasFailed(){
	return goalStatus == GGoalStatus::FAILED;
}
void GCompositeGoal::activateIfInactive(){
	if (isInactive()){
		activate(); goalStatus = ACTIVE;
	}
}
GGoalType GCompositeGoal::getType(){
	return this->type;
}
void GCompositeGoal::desactivate(){
	this->goalStatus = INACTIVE;
}