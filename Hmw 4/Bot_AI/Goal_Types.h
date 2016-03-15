#ifndef GOAL_TYPES
#define GOAL_TYPES

enum GOAL_TYPE
{
	goal_attack,
	goal_huntEnemy,
	goal_seekToPosition,
	goal_moveToPosition,
	goal_think
};

enum GOAL_STATUS
{
	NULLSTATUS,
	active, 
	inactive, 
	completed, 
	failed

};


#endif