#pragma once
#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "Bot.h"
#include <list>
#include "Timer.h"
#include "GGraph.h"
#include "GameManager.h"
#include "Vect.h"
#include "GBrain.h"
class GBrain;
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
	list<Vect*> *getPath();

private:
	Bot * bot;
	int botID;
	GGraph * graph;
	Vect * goal;
	bool newGoal;
	list<Vect*> *path;
	bool havePath;
	GBrain* brain;
	Timer * timer;
	float regulateCoolDown;
	float regulateTimer;

};


#endif