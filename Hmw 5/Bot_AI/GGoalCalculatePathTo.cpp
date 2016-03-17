#include "GGoalCalculatePathTo.h"

GGoalCalculatePathTo::GGoalCalculatePathTo(BotController * _botControl, GGoalStatus goalStatus, Vect* target)
	:GCompositeGoal(_botControl, GGoalType::CALCULEPATH, goalStatus){
	this->target = target;
	
	
}
GGoalCalculatePathTo::~GGoalCalculatePathTo(){

}


void GGoalCalculatePathTo::activate(){

}

void GGoalCalculatePathTo::terminate(){

}

GGoalStatus GGoalCalculatePathTo::process(){
	activateIfInactive();
	DebugMsg::out("Calculating Path ");
	Vect pos = botControl->getBot()->getPos();
	//DebugMsg::out("Target: %f, %f\n", target->X(), target->Y());

	list<Vect*> newPath = botControl->getGraph()->getPath(&pos, target);
	list<Vect*>* path = botControl->getPath();
	path->clear();
//	DebugMsg::out("newPath size: %d ", newPath.size());
	unsigned int newSize = newPath.size();
	for (unsigned int i = 0; i < newSize; i++){
		path->push_back(newPath.front());
		newPath.pop_front();
	};
	DebugMsg::out("Path size: %d\n ", path->size());
	goalStatus = GGoalStatus::COMPLETED;
	return  GGoalStatus::COMPLETED;
}

void GGoalCalculatePathTo::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* GGoalCalculatePathTo::toString(){
	return "Base_Goal";
}