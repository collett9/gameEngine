#pragma once
#include "gameObject.h"
#include "GUIElement.h"
#include <vector>
#include <SFML\Graphics.hpp>

class GUI
{
public:
	int tempID = 0;

	int currentlySelectedElement;

	std::vector <gameObject*> gameObjectsInGUI;


	void BattleGUISetup();

	void addNewGUIElement(b2Vec2 position, float sizeX, float sizeY, sf::Color colour, bool isSelectable);

	void GUIHandlerFirstElement(std::vector <gameObject*> GUIElements);

	void GUIHandlerNextElement(std::vector <gameObject*> GUIElements);

	void GUIHandlerPreviousElement(std::vector <gameObject*> GUIElements);

	void GUIUpdate(std::vector <gameObject*> GUIElements);

	GUI();
	~GUI();
};

