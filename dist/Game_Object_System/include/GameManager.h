#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#pragma warning (disable:4786)
#include "Camera.h"
#include "Wall.h"
#include "GraphNode.h"

#include <vector>
#include <map>
#include "Bot.h"
#include "SparseGraph.h"
#include "NavGraphNode.h"
#include "NavGraphEdge.h"
#include "Bullet.h"


typedef SparseGraph<NavGraphNode, NavGraphEdge> NavGraph;

struct ItemDrop
{
	Vect pos;
	ITEM_TYPE type;

	ItemDrop(const Vect& _pos, ITEM_TYPE _type)
	{
		pos = _pos;
		type = _type;
	}

};



class GameManager
{
private:
	
	GameManager();
	~GameManager();

	static GameManager * Instance();

	void createWalls();
	void createNavMesh();
	void createNodeEdges();
	void createBots();
	std::vector<Wall *> walls;

	Bot * blueBot;
	Bot * redBot;

	
	NavGraph* graph;

	std::vector<NavGraphEdge *> edges;
	std::map<int, Bullet *> bullets;
	std::vector<GameObject *> ObjectsToDestroy;
	std::vector<Vect> respawnPoints;

	std::map<int, Item *> items;
	std::vector<Vect> itemSpawnLocations;

	std::vector<ItemDrop> itemDrop;

	float itemTimer;
	float itemSpawnTime;

	int itemCount;

	SpriteFont * ScoreDisplay;
	int blueScore;
	int redScore;

public:

	static void Death(const int _botID);

	static void Update(const float _curTime);
	static void Render(Camera * pCam);

	static void Destroy(GameObject * obj);

	static void Clear();

	static int ClaimBot();
	static Bot * getBot(const int _id);

	static Vect getEnemyPos(const int _id);
	static int getEnemyHealth(const int _id);
	static int getMyKills(const int _id);
	static int getEnemyKills(const int _id);

	static bool GameManager::isPathObstructed(const int _botID, const Vect &_pos1, const Vect &_pos2);

	static NavGraphNode * FindClosestNode(const Vect &_pos);
	static void RemoveBullet(Bullet * _b);
	static void RemoveItem(Item * _item);

	static NavGraph * getNavGraph();
	static void addBullet(Bullet * b);


	static std::vector<ItemDrop> getItemDrops();

};




#endif