#include "renderer.h"



renderer::renderer()
{
}

void renderer::attachWindow(sf::RenderWindow * GameWindow)
{
	gameWindow = GameWindow;

}

void renderer::updateRenderer(std::vector<gameObject*> gameObjectsVector, std::vector<b2Vec2> positionVectors, std::vector<float> rotationVectors, std::vector <b2Vec2> sizeVectors)
{

	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		gameObjectsVector[i]->gameObjectShape.setPosition(sf::Vector2f(positionVectors[i].x, positionVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setOrigin(sf::Vector2f(sizeVectors[i].x, sizeVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setRotation(glm::degrees(rotationVectors[i]));

	}

}

void renderer::renderToScreen(std::vector<gameObject*> gameObjectVector)
{
	gameWindow->clear(sf::Color::Blue);

	for (int i = 0; i < gameObjectVector.size(); i++)
	{
		gameWindow->draw(gameObjectVector[i]->gameObjectShape);
	}

	gameWindow->display();
}
	


renderer::~renderer()
{
}
