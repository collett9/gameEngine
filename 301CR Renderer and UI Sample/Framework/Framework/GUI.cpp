#include "GUI.h"


//creating the generic GUI from gameobjects
void GUI::BattleGUISetup()
{
	//gameObject* newElement = new gameObject;
	//newElement->setupForGui(b2Vec2(100.0f, 40.0f), 100.0f, 50.0f, sf::Color::Red);
	//gameObjectsInGUI.push_back(newElement);

	//gameObject* newElement1 = new gameObject;
	//newElement1->setupForGui(b2Vec2(100.0f, 500.0f), 100.0f, 50.0f, sf::Color::Red);
	//gameObjectsInGUI.push_back(newElement1);

	addNewGUIElement(b2Vec2(100.0, 450.0f), 100.0f, 50.0f, sf::Color::Red);
	addNewGUIElement(b2Vec2(100.0, 600.0f), 100.0f, 50.0f, sf::Color::Red);

	addNewGUIElement(b2Vec2(1000.0, 600.0f), 100.0f, 50.0f, sf::Color::Red);

}

void GUI::addNewGUIElement(b2Vec2 position, float sizeX, float sizeY, sf::Color colour)
{
	GUIElement* newElement = new GUIElement;
	newElement->setupGUIText("egg");
	newElement->gameObjectName = "wegg"; //CHEAP!
	newElement->setupForGui(position, sizeX, sizeY, colour);
	gameObjectsInGUI.push_back(newElement);

	
}



GUI::GUI()
{
}


GUI::~GUI()
{
}
