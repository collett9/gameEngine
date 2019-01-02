#include "game.h"

int playerId = 0;




void game::setUp(std::string windowName, int Width, int Height)
{
	physics = new physicsSync(0.0f, 0.0f);

	audioSystemGame = new audioSystem();

	audioSystemGame->loadSound("meow.wav");

	levelSetup(15, 15);


	//add gameObjects here!
	//gameObject* object1 = new gameObject();
	//object1->setup(b2Vec2(500, 500), 0, 50, 50, sf::Color::Black, 0.3, 0.3, 0.3, true);
	//gameObjectsVector.push_back(object1);



	//wallObject* object3 = new wallObject(b2Vec2(1000.0f, 1000.0f));
	//gameObjectsVector.push_back(object3);
	//



	// could be an issue here in the future with objects not updating!
	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		//adding all of the gameobject data into the physics susbsystem for it to create physics objects based on it
		//ADDED THIS
		physics->addPhysicsObject(gameObjectsVector[i]->position.x, gameObjectsVector[i]->position.y, gameObjectsVector[i]->sizeX, gameObjectsVector[i]->sizeY, gameObjectsVector[i]->density, gameObjectsVector[i]->friction, gameObjectsVector[i]->linearDamping, gameObjectsVector[i]->IsStatic);
		
		
		physics->positionVectors.push_back(gameObjectsVector[i]->position);
		physics->rotationVectors.push_back(gameObjectsVector[i]->rotation);
		physics->sizeVectors.push_back(b2Vec2(gameObjectsVector[i]->sizeX, gameObjectsVector[i]->sizeY));
		gameObjectsVector[i]->gameObjectId = i;
	}



	physics->physicsSetup();


}

// creating a level out of game objects using game level data produced in the level class
void game::levelSetup(int SizeX, int SizeY)
{


	level newLevel = level(SizeX, SizeY);


	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (newLevel.levelData[i][j].whichChunk == level::playerLocation)
			{
				gameObject* object2 = new gameObject();
				object2->setup(b2Vec2(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY), 0, 10, 10, sf::Color::Yellow, 0.3, 0.3, 0.3, false);
			//	object2->gameObjectShape.setOrigin(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY);
				gameObjectsVector.push_back(object2);
				playerId = gameObjectsVector.size() - 1;
			}

			if (newLevel.levelData[i][j].whichChunk == level::wall)
			{
				gameObjectsVector.push_back(new wallObject(b2Vec2(newLevel.levelData[i][j].actualPositionX, newLevel.levelData[i][j].actualPositionY)));
			}
		}
	}
	
	rendererGame = new renderer("Level1", 1920, 1080);
	//rendererGame->gameWindow->setView()
	rendererGame->gameWindow->setSize(sf::Vector2u(newLevel.sizeBetweenObjects*newLevel.levelData.size(), newLevel.sizeBetweenObjects*newLevel.levelData.size()));
	//rendererGame->gameWindow.
	
}

void game::update()
{
	physics->physicsUpdate(1.0f / 60.0f, 6, 2);

	rendererGame->updateRenderer(gameObjectsVector, physics->positionVectors, physics->rotationVectors, physics->sizeVectors);

	
	b2Vec2 position = b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y);
	float32 angle = physics->rotationVectors[1];
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

}

void game::eventHandler()
{
	for (int i = 0; i < gameEventsVector.size(); i++)
	{
		for (int j = 0; j < gameEventsVector[i]->whichSubsystemsInvovlved.size(); j++)
		{
			if (gameEventsVector[i]->whichSubsystemsInvovlved[j] == gameEvent::Physics)
			{
				physics->physicsEventSolver(gameEventsVector[i]);
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

void game::inputHandler()
{

	rendererGame->gameWindow->pollEvent(e);

	if (e.type == sf::Event::Closed) {
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

	if (e.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			gameEventsVector.push_back(new gameEvent(eventMove(-50.0f, 0.0f, gameObjectsVector[playerId])));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			gameEventsVector.push_back(new gameEvent(eventMove(50.0f, 0.0f, gameObjectsVector[playerId])));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

			gameEventsVector.push_back(new gameEvent(eventMove(0.0f, 50.0f, gameObjectsVector[playerId])));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			gameEventsVector.push_back(new gameEvent(eventMove(0.0f, -50.0f, gameObjectsVector[playerId])));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//gameObjectsVector.pop_back();
			//delete gameObjectsVector.front();
			//gameObjectsVector.resize(gameObjectsVector.size() - 1);
			//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
			//physics.physicsBodies[1]->ApplyForce(b2Vec2(0, -1), b2Vec2(position.x + 5, position.y + 5), 1);

			audioSystemGame->playAudio(1);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			char test = sf::Keyboard::Key();
			//audioSystemGame->playAudio("ahem_x.wav");
			//gameObjectsVector.pop_back();
			//delete gameObjectsVector.front();
			//gameObjectsVector.resize(gameObjectsVector.size() - 1);
			//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
			//physics.physicsBodies[1]->ApplyForce(b2Vec2(0, -1), b2Vec2(position.x + 5, position.y + 5), 1);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			rendererGame->gameWindow->close();
		}
	}
	if (e.type == sf::Event::Resized)
	{
		// update the view to the new size of the window
		sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
		rendererGame->gameWindow->setView(sf::View(visibleArea));
	}

}

void game::render()
{
	// use the renderer to render the gameObjects to the screen
	rendererGame->renderToScreen(gameObjectsVector);


}

game::game()
{
}


game::~game()
{
}
