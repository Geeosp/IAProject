#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H



// This is the class that you will add too
#include "Bot.h"
#include <vector>
#include "Timer.h"
#include "GGraph.h"


 class BotController
{
public:
	BotController(const int _botID);
	~BotController();
	GGraph* getGraph();
	void UpdateBot(Bot * _bot);
	void render(Camera * _pCam);

	int getBotID();

	Bot * getBot();
	//void printId(int x, int y);
	void setGoal(float x, float y);

private:
	Bot * bot;
	int botID;
	GGraph * graph;
	Vect * goal;
	bool newGoal;
	vector<Vect*> *path;
	bool havePath;

};


#endif