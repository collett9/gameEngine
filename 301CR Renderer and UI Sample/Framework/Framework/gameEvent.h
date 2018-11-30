#pragma once
#include "gameObject.h"
// could be the issue???? circular
#include <vector>
#include <string>

// this class is for all events that will be dealt with by the event handler

class gameEvent
{
public:

	std::string nameOfEvent;

	enum eventTypes
	{
		movement,
		another


	};

	eventTypes eventType;

	std::vector <gameObject*> gameObjectsInvolved;

	struct bin {
		std::vector<void*> eventVoidPointerVector;
	};

	bin* testBin = new bin;

	//std::vector <void*> dateToStore;

	void *voidPointerData;
	void *voidPointerData2;

	enum whichSubsystem
	{
		Physics,
		Renderer,
		Audio

	};

	std::vector <whichSubsystem> whichSubsystemsInvovlved;


	gameEvent();
	~gameEvent();
};

