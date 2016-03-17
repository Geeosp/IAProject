#include "GCompositeGoal.h"

void GCompositeGoal::AddSubGoal(GCompositeGoal* newGoal)
{
	subGoals.push_back(newGoal);
	}



GCompositeGoal::~GCompositeGoal()
{
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