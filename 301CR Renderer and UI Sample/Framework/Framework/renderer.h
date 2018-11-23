#pragma once
#include "gameObject.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include <string>
#include <glm\glm.hpp>



class renderer
{
public:

	sf::RenderWindow* gameWindow;

	renderer();

	void attachWindow(sf::RenderWindow* GameWindow);

	void updateRenderer(std::vector<gameObject*> gameObjectVector, std::vector<b2Vec2> positionVectors, std::vector<float> rotationVectors, std::vector<b2Vec2> sizeVectors);

	void renderToScreen(std::vector <gameObject*> gameObjectVector);


	~renderer();
};

