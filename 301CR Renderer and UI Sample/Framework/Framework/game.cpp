#include "game.h"
#define PI 3.14159265359



void game::setUp(std::string windowName, int Width, int Height)
{
	test = new physicsSync(0.0f, 0.0f);

	gameWindow = new sf::RenderWindow(sf::VideoMode(Width, Height), windowName);

	//physics setup (settingup the box2D world



	//texturedShape.setPosition(600.0f, 2.0f);



	//add gameObjects here!
	gameObject* object1 = new gameObject(b2Vec2(500, 500), 0, 50, 50, sf::Color::Black, 0.3, 0.3, 0.3, test);
	gameObjectsVector.push_back(object1);

	gameObject* object2 = new gameObject(b2Vec2(600, 600), 0, 10, 10, sf::Color::Yellow, 0.3, 0.3, 0.3, test);
	gameObjectsVector.push_back(object2);

	test->physicsSetup();


}

void game::update()
{

	/*
	Now we're going to create a square - with SFML, we do this with a RectangleShape. We setSize to be
	198px by 198px, and give it a thin magenta outline. While our Sun's position is just defaulted, we
	explicitly pick a position for our rectangle's top left corner to be rendered (600 across, 2 down).
	This is our anchor position for our square, and whatever we do to the position of our square acts on
	that anchor point.
	*/


	// add shapes to a vector and then render shapes by that
	//shapesVector.push_back(groundShape);




	/*
	We want to texture our rectangle, so we create a texture called testTexture. After that, we populate
	testTexture from a read-in file - note the relative pathing used in the directory of the file. We can
	replace those relative paths with #DEFINEs if we want to. Remembering last week's lecture, we should
	realise that this texture is an ASSET, and that we should in some fashion manage it. In this case,
	SFML is handling the memory management of the asset for us, so our own asset management would involve
	keeping track of testTexture for reuse, making sure keyboardcat.jpg wasn't read in twice, etc.

	Also note our little error check here. We mentioned error checking and debugging last week - here's
	a practical example. If loadFromFile fails, we get a COUT telling us this has happened.
	*/

	//update physics to 
	test->physicsUpdate(1.0f / 60.0f, 6, 2);

	//test.world->Step(timeStep, velocityIterations, positionIterations);
	//	for()

	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		gameObjectsVector[i]->gameObjectShape.setPosition(sf::Vector2f(test->positionVectors[i].x , test->positionVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setOrigin(sf::Vector2f(test->sizeVectors[i].x, test->sizeVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setRotation(glm::degrees(test->rotationVectors[i]));
		
	}

	
	b2Vec2 position = b2Vec2(test->positionVectors[1].x, test->positionVectors[1].y);
	float32 angle = test->rotationVectors[1];
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	//gameObjectsVector[1]->gameObjectShape.setPosition(sf::Vector2f(position.x - 1.0f, position.y - 1.0f));
	//gameObjectsVector[1]->gameObjectShape.setRotation(angle);
	//shape.setPosition(position.x, position.y);


}

void game::eventHandler()
{
	gameWindow->pollEvent(e);

	if (e.type == sf::Event::Closed) {
		gameWindow->close();

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

			test->physicsBodies[1]->ApplyForce(b2Vec2(-1000, 0), b2Vec2(test->positionVectors[1].x, test->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x - 0.05, position.y), 0);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//texturedShape.move(sf::Vector2f(0.5f, 0.0f));
			test->physicsBodies[1]->ApplyForce(b2Vec2(1000, 0), b2Vec2(test->positionVectors[1].x, test->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x + 0.05, position.y), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//texturedShape.move(sf::Vector2f(0.0f, -0.5f));
			test->physicsBodies[1]->ApplyForce(b2Vec2(0, 1000), b2Vec2(test->positionVectors[1].x, test->positionVectors[1].y), 1);
			//body->SetTransform(b2Vec2(position.x, position.y - 0.05), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
			test->physicsBodies[1]->ApplyForce(b2Vec2(0, -1000), b2Vec2(test->positionVectors[1].x, test->positionVectors[1].y), 1);

			//body->SetTransform(b2Vec2(position.x, position.y + 0.05), 0);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//gameObjectsVector.pop_back();
			//delete gameObjectsVector.front();
			//gameObjectsVector.resize(gameObjectsVector.size() - 1);
			//texturedShape.move(sf::Vector2f(0.0f, 0.5f));
			//test.physicsBodies[1]->ApplyForce(b2Vec2(0, -1), b2Vec2(position.x + 5, position.y + 5), 1);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameWindow->close();
		}
	}

}

void game::render()
{
	gameWindow->clear(sf::Color::Blue);

	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		gameWindow->draw(gameObjectsVector[i]->gameObjectShape);
	}

	gameWindow->display();


}

game::game()
{
}


game::~game()
{
}
