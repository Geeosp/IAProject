#include "GGoalFollowPath.h"


GGoalFollowPath::GGoalFollowPath(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::FOLOWPATH, goalStatus){

}
GGoalFollowPath::~GGoalFollowPath(){

}


void GGoalFollowPath::activate(){

}

void GGoalFollowPath::terminate(){

}
GGoalStatus GGoalFollowPath::process(){
	activateIfInactive();
	Bot* bot = botControl->getBot();
	list<Vect*>* path = botControl->getPath();
	Vect pos = botControl->getBot()->getPos();
	if (!path->empty()){
		Vect* targ = path->front();
		if ((*targ - pos).magSqr()< 2.f){
			path->pop_front();
		}
		bot->MoveToPosition(*targ);
	}
	
	if (path->empty()){

		goalStatus = GGoalStatus::COMPLETED;

	}
	else{
		goalStatus =   GGoalStatus::ACTIVE;

	}
	return goalStatus;
	
	
}

void GGoalFollowPath::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* GGoalFollowPath::toString(){
	return "FollowPath_Goal";
}