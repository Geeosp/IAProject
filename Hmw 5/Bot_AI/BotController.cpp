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
	path = new list < Vect* > ;
	newGoal = false;
	havePath = false;
	
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
		list<Vect*> newPath = graph->getPath(&pos, goal);
		path->clear();
		DebugMsg::out("newPath size: %d ", newPath.size());
		unsigned int newSize = newPath.size();
		for (unsigned int i = 0; i < newSize; i++){
			path->push_back(newPath.front());
			newPath.pop_front();
		}
		DebugMsg::out("Path size: %d ", path->size());

		newGoal = false;
	}

	if (!path->empty()){
		Vect* targ = path->front();
		DebugMsg::out("Path size: %d ", path->size());
		DebugMsg::out("distToTarget: %f\n", (*targ - pos).magSqr());
		if ((*targ - pos).magSqr()< 1){
			path->pop_front();
		}
		bot->MoveToPosition(*targ);
	//	DebugMsg::out("going to position %f %f\n", targ->X(), targ->Y());
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
