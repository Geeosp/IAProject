#include "BotController.h"
#include "Defs.h"


BotController::BotController(const int botId) 
{
	this->graph = new GGraph();
	this->botID = botId;
	this->bot = GameManager::getBot(botID);
	Vect pos = bot->getPos();
	this->goal = &pos;
	this->path = new list < Vect* > ;
	this->newGoal = false;
	this->havePath = false;
	this->brain = new GBrain(bot, this);
	this->timer = new Timer();
	this->timer->tic();

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
		brain->think();

		regulateTimer = curTime + regulateCoolDown;
	}
	brain->process();

	/*
	Vect  pos = bot->getPos();
	if (newGoal){
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
		if ((*targ - pos).magSqr()< 2.f){
			path->pop_front();
		}
		bot->MoveToPosition(*targ);
	}
	*/
}

void BotController::render(Camera * _pCam)
{
	(void*)_pCam;
//	graph->render(_pCam);




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

list<Vect*> * BotController::getPath(){
	return this->path;
}