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
	path = new vector < Vect* > ;
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
	
	Vect  pos = bot->getPos();
	if (newGoal){
		DebugMsg::out("Path from (%f %f)", pos.X(), pos.Y());
		DebugMsg::out("Path to (%f %f)\n", goal->X(), goal->Y());
		vector<Vect*> newPath = graph->getPath(&pos, goal);
		path = &newPath;
		newGoal = false;
	}

	DebugMsg::out("Path size: %d\n", path->size());
	if (!path->empty()){
		DebugMsg::out("pathNotEmpty\n");
		Vect* targ = path->at(5);
		bot->MoveToPosition(*targ);
		DebugMsg::out("going to position %f %f\n", targ->X(), targ->Y());
	}

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
void BotController::printId(int x, int y){
	DebugMsg::out("mouse:(%d,%d)\n", x, y);
}
*/

GGraph* BotController::getGraph() {
	return this->graph;
}

void BotController::setGoal(float x, float y){
	x; y;
	if (x > 40 && x < 1000 && y>40 && y < 760){

	Vect pos1(x, y, 0, 1);
	goal = new Vect(x, y, 0, 1);
	newGoal = true;
	DebugMsg::out("setGoal :%f %f\n",x,y );
	}
}
