#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H



// This is the class that you will add too
#include "Bot.h"
#include <list>
#include "Timer.h"

class NavGraphNode;
class myGraph;
class Bot;
class Vect;
class Goal_Think;

static const float ChaseToDistance = 10.0f;
static const float LaserAttackPriority = 1.0f;
static const float PistolAttackPriority = 0.25f;

static const float LaserDesiredAmount = 20.0f;


class BotController
{


public:
	BotController(const int _botID);
	~BotController();


	void UpdateBot(Bot * _bot);
	void RenderGraph(Camera * _pCam);

	int getBotID();

	Bot * getBot();

	void CreatePathToPosition( const Vect &_start, const Vect &_dest);
	Vect GetNextPosInPath();

	void getPath();
	bool havePath();

	Goal_Think * getBrain();

private:
	Bot * bot;
	int botID;
	std::list<Vect> path;
	myGraph * graph;

	Timer * timer;

	float regulateCoolDown;
	float regulateTimer;

	void CreatePOVGraph();
	void AStar(NavGraphNode * _startNode, NavGraphNode * _endNode);

	Goal_Think * Brain;
};


#endif