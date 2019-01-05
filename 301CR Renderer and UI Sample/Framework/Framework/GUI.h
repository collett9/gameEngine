#pragma once
#include "gameObject.h"
#include "GUIElement.h"
#include <vector>
#include <SFML\Graphics.hpp>

class GUI
{
public:

	std::vector <gameObject*> gameObjectsInGUI;


	void BattleGUISetup();

	void addNewGUIElement(b2Vec2 position, float sizeX, float sizeY, sf::Color colour);

	GUI();
	~GUI();
};

