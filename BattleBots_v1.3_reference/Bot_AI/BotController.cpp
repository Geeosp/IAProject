#include "BotController.h"
#include "myGraph.h"
#include "myGraphNode.h"
#include "GameManager.h"
#include "Graph_SearchAStar.h"
#include "AStarHeuristicPolicies.h"
#include "Vect.h"
#include "Goal_Think.h"

BotController::BotController(const int _botId) 
{
	botID = _botId;
	bot = GameManager::getBot(botID);

	graph = new myGraph();
	regulateCoolDown = 2.0f;

	Brain = new Goal_Think(this);

	regulateTimer += regulateCoolDown;

	timer = new Timer();
	timer->tic();

	Brain->Arbitrate();
}

BotController::~BotController()
{

}

void BotController::UpdateBot(Bot * _bot)
{
	(void)_bot;
	Time_Engine time = timer->toc();
	float curTime = Time_Engine::quotientFloat(time, Time_Engine(TIME_ONE_MILLISECOND)) / 1000;

	if (curTime > regulateTimer)
	{
		Brain->Arbitrate();

		regulateTimer = curTime + regulateCoolDown;
	}

	Brain->Process();
}

void BotController::RenderGraph(Camera * _pCam)
{
	graph->Render(_pCam);
}

int BotController::getBotID()
{
	return botID;
}

void BotController::CreatePOVGraph()
{
	myGraphNode * p1 = new myGraphNode(new Vect(165, 600, 0));
	myGraphNode * p2 = new myGraphNode(new Vect(150, 400, 0));
	myGraphNode * p3 = new myGraphNode(new Vect(75, 280, 0));
	myGraphNode * p4 = new myGraphNode(new Vect(80, 90, 0));

	graph->addNode(p1);
	graph->addNode(p2);
	graph->addNode(p3);
	graph->addNode(p4);

	graph->addEdge(p1, p2);
	graph->addEdge(p2, p3);
	graph->addEdge(p3, p4);


}

Bot * BotController::getBot()
{
	return bot;
}

bool BotController::havePath()
{
	return !path.empty();
}

Vect BotController::GetNextPosInPath()
{
	Vect outVect = Vect(0.0f, 0.0f, 0.0f);

	if (havePath())
	{
		outVect = path.front();
		path.pop_front();
	}

	return outVect;
}


void BotController::CreatePathToPosition(const Vect &_start, const Vect &_dest)
{
	path.clear();

	if (GameManager::isPathObstructed(botID, _start, _dest))
	{
		NavGraphNode * closestNodeToMe = GameManager::FindClosestNode(_start);
		NavGraphNode * closestNodeToEnemy = GameManager::FindClosestNode(GameManager::getEnemyPos(botID));

		AStar(closestNodeToMe, closestNodeToEnemy);

	}
	else
	{
		path.push_back(_dest);

	}
}

void BotController::AStar(NavGraphNode * _startNode, NavGraphNode * _endNode)
{
	NavGraph * graph = GameManager::getNavGraph();

	//create a couple of typedefs so the code will sit comfortably on the page   
	typedef Graph_SearchAStar<NavGraph, Heuristic_Euclid> AStarSearch;

	AStarSearch AStar(*graph, _startNode->Index(), _endNode->Index());

	std::list<int> nodes = AStar.GetPathToTarget();

	for each (int var in nodes)
	{
		path.push_back(*graph->GetNode(var)->getPos());
	}
}

Goal_Think * BotController::getBrain()
{
	return Brain;
}