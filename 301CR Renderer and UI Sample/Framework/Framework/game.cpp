#include "game.h"

int playerId = 0;



//setting up renderer, physics as well as ui's
void game::setUp(std::string windowName, int Width, int Height)
{
	physics = new physicsSync(0.0f, 0.0f);

	audioSystemGame = new audioSystem();



	audioSystemGame->loadSound("meow.wav");

	audioSystemGame->loadSound("ahem_x.wav");

	levelSetup(15, 15, "test.png");


	gui.BattleGUISetup();

	//add gameObjects here!
	//gameObject* object1 = new gameObject();
	//object1->setup(b2Vec2(500, 500), 0, 50, 50, sf::Color::Black, 0.3, 0.3, 0.3, true);
	//gameObjectsVector.push_back(object1);



	//wallObject* object3 = new wallObject(b2Vec2(1000.0f, 1000.0f));
	//gameObjectsVector.push_back(object3);
	//




	//gameObjectsSetup();

	physics->physicsSetup();
	input = new inputHandler();

	input->setUpRenderer(rendererGame);
}

void game::gameObjectsSetup()
{
	// could be an issue here in the future with objects not updating!
	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		//adding all of the gameobject data into the physics susbsystem for it to create physics objects based on it
		//ADDED THIS
		


		physics->positionVectors.push_back(gameObjectsVector[i]->position);
		physics->rotationVectors.push_back(gameObjectsVector[i]->rotation);
		physics->sizeVectors.push_back(b2Vec2(gameObjectsVector[i]->sizeX, gameObjectsVector[i]->sizeY));
		gameObjectsVector[i]->gameObjectId = i;

		physics->addPhysicsObject(gameObjectsVector[i]->position.x, gameObjectsVector[i]->position.y, gameObjectsVector[i]->sizeX, gameObjectsVector[i]->sizeY, gameObjectsVector[i]->density, gameObjectsVector[i]->friction, gameObjectsVector[i]->linearDamping, gameObjectsVector[i]->IsStatic, gameObjectsVector[i]->gameObjectId);
	}
}


// function to deal with the collision of the various gameobjects within the scene
void game::gameObjectsCollide()
{
	if (physics->listener.data1 != NULL)
	{
		std::cout << "it do";
	}

	// if player gameobject collides with a gameobject with the name 'enemy'
	if (physics->listener.data1 == playerId && gameObjectsVector[physics->listener.data2]->gameObjectName == "enemy" || physics->listener.data2 == playerId && gameObjectsVector[physics->listener.data1]->gameObjectName == "enemy")
	{
			std::cout << "egg" << std::endl;
			rendererBattle = new renderer("FIGHT!", 1280, 720);
		
	}




	//reseting the hit data after the player has moved away from it
	if (physics->listener.data1 == physics->listener.data3 && physics->listener.data2 == physics->listener.data4)
	{
		physics->listener.data1 = NULL;
		physics->listener.data2 = NULL;
		physics->listener.data3 = NULL;
		physics->listener.data4 = NULL;
	}

	else
	{
		physics->listener.data1 = NULL;
		physics->listener.data2 = NULL;
		physics->listener.data3 = NULL;
		physics->listener.data4 = NULL;
	}


	
}

// creating a level out of game objects using game level data produced in the level class
void game::levelSetup(int SizeX, int SizeY, std::string imageFileName)
{
// wiping previous level's data  such as gameojects and related physics data

	if (gameObjectsVector.size() > 0)
	{	
		for (int i = 0; i < gameObjectsVector.size(); i++)
		{
			delete gameObjectsVector[i];
		}
		gameObjectsVector.clear();
	}

	if (physics->physicsBodies.size() > 0)
	{

		physics->physicsBodies.clear();
	}

	if (physics->positionVectors.size() > 0)
	{
		physics->positionVectors.clear();
	}

	if (physics->rotationVectors.size() > 0)
	{
		physics->rotationVectors.clear();
	}

	if (physics->sizeVectors.size() > 0)
	{
		physics->sizeVectors.clear();
	}


	level newLevel = level(SizeX, SizeY, imageFileName);


	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (newLevel.levelData[i][j].whichChunk == level::playerLocation)
			{
				gameObject* object2 = new gameObject();
				object2->setup(b2Vec2(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY), 0, 10, 10, sf::Color::Yellow, 0.3, 0.3, 0.3, false);
				object2->setNameOfObject("player");
			//	object2->gameObjectShape.setOrigin(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY);
				gameObjectsVector.push_back(object2);
				playerId = gameObjectsVector.size() - 1;
			}

			if (newLevel.levelData[i][j].whichChunk == level::wall)
			{
				gameObject* wallObject1 = (new wallObject(b2Vec2(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY)));
				wallObject1->setNameOfObject("wall");
				gameObjectsVector.push_back(wallObject1);
			}

			if (newLevel.levelData[i][j].whichChunk == level::enemyLocation)
			{
				gameObject* enemyObject = (new Enemy(b2Vec2(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY), 100));
				enemyObject->setNameOfObject("enemy");
				gameObjectsVector.push_back(enemyObject);

			}
		}
	}
	
	if (rendererGame == NULL)
	{
		rendererGame = new renderer(imageFileName, 1920, 1080);

	}

	else {

		rendererGame->gameWindow->setTitle(imageFileName);
	}
	gameObjectsSetup();

	//rendererGame->gameWindow->setView()
	rendererGame->gameWindow->setSize(sf::Vector2u(newLevel.sizeBetweenObjects*newLevel.levelData.size(), newLevel.sizeBetweenObjects*newLevel.levelData.size()));
	//rendererGame->gameWindow.
	
}

void game::update()
{
	physics->physicsUpdate(1.0f / 60.0f, 6, 2);

	gameObjectsCollide();

	rendererGame->updateRenderer(gameObjectsVector, physics->positionVectors, physics->rotationVectors, physics->sizeVectors);

	/*if (rendererBattle != NULL)
	{
		rendererBattle->updateRenderer(gui.gameObjectsInGUI, )
	}*/

	/*
	b2Vec2 position = b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y);
	float32 angle = physics->rotationVectors[1];
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);*/

	if (rendererBattle != NULL)
	{
		battleScreen = true;
		input->setUpRenderer(rendererBattle);
	}

	else
	{
		input->setUpRenderer(rendererGame);
		battleScreen = false;
	}

}

void game::eventHandler()
{
	for (int i = 0; i < gameEventsVector.size(); i++)
	{
		for (int j = 0; j < gameEventsVector[i]->whichSubsystemsInvovlved.size(); j++)
		{
			if (gameEventsVector[i]->whichSubsystemsInvovlved.size() > 0 && gameEventsVector[i]->whichSubsystemsInvovlved[j] == gameEvent::Physics)
			{
				physics->physicsEventSolver(gameEventsVector[i]);
			}

			if (gameEventsVector[i]->whichSubsystemsInvovlved.size() > 0 && gameEventsVector[i]->whichSubsystemsInvovlved[j] == gameEvent::Audio)
			{
				audioSystemGame->audioEventSolver(gameEventsVector[i]);
			}
		}

		if (gameEventsVector[i]->whichSubsystemsInvovlved.size() == 0)
		{
			//clearing the memory that the gameEvents were using and get rid of them
			gameEventsVector.back()->clearMemory();
			delete gameEventsVector.back();
			gameEventsVector.pop_back();
			
		}

	}
}

void game::guiHandler()
{
	

}

void game::inputHandlerGame()
{



	inputHandler::buttons whichButtonHasBeenPressed = input->whichKey();


	if (whichButtonHasBeenPressed == inputHandler::closed) {
		rendererGame->gameWindow->close();

	}

	/*
	If the event isn't an Event::Closed, we check to see if it's an Event::KeyPressed. If so,
	we run through a check to see if an arrow key is being pressed. Dependent on the key(s) being
	pressed, our textured square moves in different directions. This approach has several issues
	as discussed in the lecture, so you'll want to abstract and refine this. Can you think of any
	problems which might occur when two keys are pressed simultaneously?

	Next, if the Escape key is pressed, we consider that to be a close instruction from the user
	and the window exits.
	*/


	if (whichButtonHasBeenPressed == inputHandler::leftArrow && battleScreen == false)
	{

		gameEventsVector.push_back(new gameEvent(eventMove(-50.0f, 0.0f, gameObjectsVector[playerId])));
	}

	if (whichButtonHasBeenPressed == inputHandler::rightArrow && battleScreen == false)
	{
		gameEventsVector.push_back(new gameEvent(eventMove(50.0f, 0.0f, gameObjectsVector[playerId])));
	}
	if (whichButtonHasBeenPressed == inputHandler::upArrow && battleScreen == false)
	{

		gameEventsVector.push_back(new gameEvent(eventMove(0.0f, 50.0f, gameObjectsVector[playerId])));
	}

	if (whichButtonHasBeenPressed == inputHandler::upArrow && battleScreen == true)
	{

		gui.GUIHandlerNextElement(gui.gameObjectsInGUI);
	}
	if (whichButtonHasBeenPressed == inputHandler::downArrow && battleScreen == false)
	{
		gameEventsVector.push_back(new gameEvent(eventMove(0.0f, -50.0f, gameObjectsVector[playerId])));
	}
	if (whichButtonHasBeenPressed == inputHandler::downArrow && battleScreen == true)
	{

		gui.GUIHandlerPreviousElement(gui.gameObjectsInGUI);
		
	}

	if (whichButtonHasBeenPressed == inputHandler::space)
	{
		//gameObjectsVector.pop_back();
		//delete gameObjectsVector.front();
		//gameObjectsVector.resize(gameObjectsVector.size() - 1);
		//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
		//physics.physicsBodies[1]->ApplyForce(b2Vec2(0, -1), b2Vec2(position.x + 5, position.y + 5), 1);

		//audioSystemGame->playAudio("meow.wav");
		gameEventsVector.push_back(new gameEvent(audioEvent(0)));
		gui.GUIHandlerFirstElement(gui.gameObjectsInGUI);

	}

	if (whichButtonHasBeenPressed == inputHandler::W)
	{
		char test = sf::Keyboard::Key();
		//audioSystemGame->playAudio("ahem_x.wav");
		//gameObjectsVector.pop_back();
		//delete gameObjectsVector.front();
		//gameObjectsVector.resize(gameObjectsVector.size() - 1);
		//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
		//physics.physicsBodies[1]->ApplyForce(b2Vec2(0, -1), b2Vec2(position.x + 5, position.y + 5), 1);
		gameEventsVector.push_back(new gameEvent(audioEvent(1)));
		levelSetup(15, 15, "test1.png");
	}

	if (whichButtonHasBeenPressed == inputHandler::escape && battleScreen == true)
	{
		input->rendererEvent->gameWindow->close();
		input->rendererEvent = NULL;
		rendererBattle = NULL;
	
	}

	if (whichButtonHasBeenPressed == inputHandler::resized)
	{
		// update the view to the new size of the window

	}
	gui.GUIUpdate(gui.gameObjectsInGUI);
}

void game::render()
{
	// use the renderer to render the gameObjects to the screen

	

	if(battleScreen == true)
	{ 
		rendererBattle->renderToScreen(gui.gameObjectsInGUI);
		//gui.gameObjectsInGUI[0].
	
	}
	
	else
	{
		rendererGame->renderToScreen(gameObjectsVector);
	}


}

game::game()
{
}


game::~game()
{
}
