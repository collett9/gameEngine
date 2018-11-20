#include "game.h"


void game::setUp(std::string windowName, int Width, int Height)
{
	physics = new physicsSync(0.0f, 0.0f);

	rendererGame = new renderer();

	//add gameObjects here!
	gameObject* object1 = new gameObject(b2Vec2(500, 500), 0, 50, 50, sf::Color::Black, 0.3, 0.3, 0.3, physics, true);
	gameObjectsVector.push_back(object1);

	gameObject* object2 = new gameObject(b2Vec2(600, 600), 0, 10, 10, sf::Color::Yellow, 0.3, 0.3, 0.3, physics, false);
	gameObjectsVector.push_back(object2);

	physics->physicsSetup();


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
			//texturedShape.move(sf::Vector2f(-0.5f, 0.0f));

			physics->physicsBodies[1]->ApplyForce(b2Vec2(-1000, 0), b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x - 0.05, position.y), 0);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//texturedShape.move(sf::Vector2f(0.5f, 0.0f));
			physics->physicsBodies[1]->ApplyForce(b2Vec2(1000, 0), b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x + 0.05, position.y), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//texturedShape.move(sf::Vector2f(0.0f, -0.5f));
			physics->physicsBodies[1]->ApplyForce(b2Vec2(0, 1000), b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x, position.y - 0.05), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
			physics->physicsBodies[1]->ApplyForce(b2Vec2(0, -1000), b2Vec2(physics->positionVectors[1].x, physics->positionVectors[1].y), 1);

			//body->SetTransform(b2Vec2(position.x, position.y + 0.05), 0);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
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

}

void game::render()
{

	rendererGame->renderToScreen(gameObjectsVector);


}

game::game()
{
}


game::~game()
{
}
