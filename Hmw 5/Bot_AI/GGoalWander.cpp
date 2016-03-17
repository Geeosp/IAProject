#include "GGoalWander.h"
#include <math.h>
#include "Defs.h"
GGoalWander::GGoalWander(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::WONDER, goalStatus){

}
GGoalWander::~GGoalWander(){

}


void GGoalWander::activate(){
	myangle = 10.0f;
}

void GGoalWander::terminate(){

}

GGoalStatus GGoalWander::process(){
	//myangle = (float)rand()/(float)RAND_MAX*3.14f*2.f;
	myangle += WANDERDELTAANGLE;
	DebugMsg::out("angle: %f", myangle);
	float mycos = cos(myangle);
	mycos *= WANDERRADIUS;
	float mysin = sin(myangle);
	mysin *= WANDERRADIUS;
	Vect rot(WANDERRADIUS*cos(myangle), WANDERRADIUS*sin(myangle), 0, 1);
	DebugMsg::out("rot %f, %f\n ", rot.X(), rot.Y());
	Vect enemyPos = GameManager::getEnemyPos(botControl->getBotID());
	enemyPos += rot;
	botControl->getBot()->MoveToPosition(enemyPos);
	return  GGoalStatus::ACTIVE;
}

void GGoalWander::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* GGoalWander::toString(){
	return "Wonder_Goal";
}