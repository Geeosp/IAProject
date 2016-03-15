#ifndef BOTCONTROLLER_Default_H
#define BOTCONTROLLER_Default_H

#include <list>
#include <map>
#include "Vect.h"
#include "GameManager.h"

#include "NavGraphNode.h"

class Bot;


static float ChaseDistance = 100.0f;

__declspec(align(16)) class BotController_Default
{

public:
	BotController_Default(const int _id);
	~BotController_Default();

	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}
		void operator delete(void* p)
	{
		_mm_free(p);
	}

	void UpdateBot(Bot * _bot);
	int getBotID(){ return botID; }

private:

	std::list<int> path;
	Vect curDes;

	void CreatePathToPosition(const int _botID, const Vect &_start, const Vect &_dest);

	bool havePath;
	bool canSeeEnemy;
	int botID;

	void ChaseEnemy();
	void FireAtEnemy(Bot * _bot);

	NavGraph * graph;

	void AStar(NavGraphNode * _startNode, NavGraphNode * _endNode);

	void CheckItems();

	bool searchForItem;


};


#endif