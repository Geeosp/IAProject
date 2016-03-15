#include "BotController.h"
//#include "myGraph.h"
//#include "myGraphNode.h"
#include "GameManager.h"
//#include "Graph_SearchAStar.h"
//#include "AStarHeuristicPolicies.h"
#include "Vect.h"
//#include "Goal_Think.h"

BotController::BotController(const int _botId) 
{
	(void*)(_botId);
	this->graph = new GGraph();
	botID = _botId;
	bot = GameManager::getBot(botID);
	Vect pos = bot->getPos();
	goal = &pos;

	newGoal = false;
	havePath = false;
	/*

	//graph = new myGraph();
	regulateCoolDown = 2.0f;

	Brain = new Goal_Think(this);

	regulateTimer += regulateCoolDown;

	timer = new Timer();
	timer->tic();
	CreatePOVGraph();
	Brain->Arbitrate();
	*/
}

BotController::~BotController()
{

}

void BotController::UpdateBot(Bot * _bot)
{
	(void)_bot;
	
	if (newGoal){
		Vect  pos = bot->getPos();
		vector<Vect*> newPath = graph->getPath(&pos, goal);
		path = &newPath;
		newGoal = false;
	}



	
	



	/*
	Time_Engine time = timer->toc();
	float curTime = Time_Engine::quotientFloat(time, Time_Engine(TIME_ONE_MILLISECOND)) / 1000;

	if (curTime > regulateTimer)
	{
		Brain->Arbitrate();

		regulateTimer = curTime + regulateCoolDown;
	}

	Brain->Process();
	*/
}

void BotController::render(Camera * _pCam)
{
//	(void*)_pCam;
	graph->render(_pCam);
}

int BotController::getBotID()
{
	return botID;
}
Bot * BotController::getBot()
{
	return bot;
}
/*
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
	(void*)_startNode;
	(void*)_endNode;
	/*
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
	*/

/*Goal_Think * BotController::getBrain()
{
	return Brain;
}
*/
void BotController::printId(int x, int y){
	DebugMsg::out("mouse:(%d,%d)\n", x, y);
}
GGraph* BotController::getGraph() {
	return this->graph;
}

void BotController::setGoal(float x, float y){
	x; y;
	Vect pos(x, y, 0, 1);
	goal=&pos;
	newGoal = true;
}
