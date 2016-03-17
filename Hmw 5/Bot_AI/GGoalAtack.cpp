#include "GGoalAtack.h"
#include "Defs.h"
GGoalAtack::GGoalAtack(BotController * _botControl, GGoalStatus goalStatus)
	:GCompositeGoal(_botControl, GGoalType::ATACK, goalStatus){

}
GGoalAtack::~GGoalAtack(){

}


void GGoalAtack::activate(){

}

void GGoalAtack::terminate(){

}

GGoalStatus GGoalAtack::process(){
	Bot* bot = botControl->getBot();
	Vect pos = bot->getPos();
	Vect enemyPos = GameManager::getEnemyPos(bot->getID());
	Vect v = pos - enemyPos;
	float angle = v.getAngle(Vect(1, 0, 0));
	angle *= 57.2957795131f;
	if (enemyPos.Y() > pos.Y()){

		angle = 180.f - angle;
	}
	else{
		angle = angle - 180.f;
	}
	bot->RotateToAngle(angle);
	int laser = bot->getLaserAmmo();
	int rifle = bot->getRifleAmmo();
	float enemyDist = (enemyPos - pos).mag();
	DebugMsg::out("EnemyDistance: %f", enemyDist);
	if (!GameManager::isPathObstructed(bot->getID(), pos, enemyPos)){
		if (laser > 0){
			bot->Fire(Weapon_Type::LASER);
		}
		else if (rifle>0&& enemyDist <RIFLEFIRERANGE){
			bot->Fire(Weapon_Type::RIFLE);
		}
		else if (enemyDist <= PISTOLFIRERANGE){
			bot->Fire(Weapon_Type::PISTOL);

		}

	}













	return  GGoalStatus::ACTIVE;
}

void GGoalAtack::addSubGoal(GCompositeGoal* newGoal){
	newGoal;

}
char* GGoalAtack::toString(){
	return "Base_Goal";
}