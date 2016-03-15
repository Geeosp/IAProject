#include "AzulCore.h"
#include "Game.h"
#include "InputTest.h"
#include "SpriteFont.h"
#include "Graphics_Man.h"
#include "World.h"
#include "GameManager.h"
#include "ContactManager.h"
#include "Timer.h"

#include "Bot.h"

//#include "BotController_Default.h"
#include "BotController.h"

struct PhysicBody_Data;
struct MovingEntity_Data;

// Global varables just for the demo:
	Camera *pCam2D;


	float moveX;
	float angle;
	float scale;
	float scaleFactor;

	SpriteFont * mouseDisplay;

	ContactManager * contactManager;

	Timer * timer;

	bool search;


	BotController * defaultBot;
	BotController * playerBot;
	

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	// Game Window Device setup
	this->setWindowName("Battle Bots!");
	this->setWidthHeight(1040, 800);
	this->SetClearColor( 0.4f, 0.4f, 0.8f, 1.0f );

	// Use this area, for one time non-graphic creation

}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{	
	//---------------------------------------------------------------------------------------------------------
	// Setup the current 2D orthographic Camera
	//---------------------------------------------------------------------------------------------------------

		pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D, this->getWidth(), this->getHeight());
		assert(pCam2D);


		mouseDisplay = new SpriteFont("", 0, 0, 1, 1);

		moveX = 200;
		scale = 1.0f;
		angle = 0.0f;
		scaleFactor = 0.1f;

		// Setting up the world's contact manager
		// This will notify me whenever a collision has occured
		contactManager = new ContactManager();
		World::SetContactListener(contactManager);

		playerBot = new BotController(GameManager::ClaimBot());
		defaultBot = new BotController(GameManager::ClaimBot());
		// Timer
		timer = new Timer;
		timer->tic();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update()
{
	// Grabs the current time
	Time_Engine time = timer->toc();
	float curTime = Time_Engine::quotientFloat(time, Time_Engine(TIME_ONE_MILLISECOND)) /1000;

	// Update cameras - make sure everything is consistent
	pCam2D->updateCamera();

	// Add your update below this line: ----------------------------

	//KeyboardTest();
	//MouseTest();

	// Updates the Physics system
	World::Update();

	
	GameManager::Update(curTime);

	
	Mouse * mouse = Mouse::GetInstance();
	Keyboard *key = Keyboard::GetInstance();

	if (key->GetKeyState(AZUL_KEY::KEY_W))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		Vect dir = bot->getPos() + Vect(0.0f, 1.0f, 0.0f);

		bot->MoveToPosition(dir);

	}

	if (key->GetKeyState(AZUL_KEY::KEY_D))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		Vect dir = bot->getPos() + Vect(1.0f, 0.0f, 0.0f);

		bot->MoveToPosition(dir);

	}

	if (key->GetKeyState(AZUL_KEY::KEY_A))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		Vect dir = bot->getPos() + Vect(-1.0f, 0.0f, 0.0f);

		bot->MoveToPosition(dir);

	}
	if (key->GetKeyState(AZUL_KEY::KEY_S))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		Vect dir = bot->getPos() + Vect(0.0f, -1.0f, 0.0f);

		bot->MoveToPosition(dir);

	}

	if (key->GetKeyState(AZUL_KEY::KEY_J))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		angle += 2.0f;

		bot->RotateToAngle(angle);
	}
	if (key->GetKeyState(AZUL_KEY::KEY_K))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

		angle += -2.0f;

		bot->RotateToAngle(angle);
	}

	if (key->GetKeyState(AZUL_KEY::KEY_R))
	{
	//	search2 = true;
	}

	if (key->GetKeyState(AZUL_KEY::KEY_SPACE))
	{
		Bot * bot = GameManager::getBot(playerBot->getBotID());

 		if (bot->getRifleAmmo() > 0)
		{
 			bot->Fire(LASER);
		}
		else
		{
			bot->Fire(PISTOL);
		}
	}


	playerBot->UpdateBot(GameManager::getBot(playerBot->getBotID()));
	defaultBot->UpdateBot(GameManager::getBot(defaultBot->getBotID()));
	

	float posX = 0.0f;
	float posY = 0.0f;

	mouse->GetCursor(posX, posY);

	posY = 800 - posY;
	int dani = playerBot->getGraph()->getNodeId(posX,posY);
	


	mouseDisplay->Update(
	//	"x:"+std::to_string((int)posX)
 //+		" y:" + std::to_string((int)posY) 
		//+ " ax:" + std::to_string((int)ax)
		//+
	//	" ay:" + std::to_string((int)ay)
	//	+
		"id:" + std::to_string(dani)
		,posX, posY, 1.0f, 1.0f);

	if (mouse->GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		playerBot->setGoal(posX,posY);
	}


}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	

	GameManager::Render(pCam2D);

	playerBot->render(pCam2D);

	mouseDisplay->Render(pCam2D);
}



//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	// todo fix this.
	GameManager::Clear();

	delete pCam2D;

}



