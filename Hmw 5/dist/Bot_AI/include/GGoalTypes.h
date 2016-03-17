#pragma once
#ifndef GEEO_GOAL_TYPES
#define GEEO_GOAL_TYPES





enum GGoalType
{
	SEARCHFORLIFE,
	CALCULEPATH, 
	FOLOWPATH	
};

enum GGoalStatus
{
	INACTIVE,
	ACTIVE,
	COMPLETED,
	FAILED

};


#endif