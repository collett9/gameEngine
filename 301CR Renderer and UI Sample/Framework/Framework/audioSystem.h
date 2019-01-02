#pragma once
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include <string>
#include <vector>

class audioSystem
{
public:

	FMOD::Studio::System* system;
	FMOD::System* lowLevelSystem;
	FMOD::Channel* catChannel = NULL;
	FMOD::Sound* meow = NULL;

	std::vector <FMOD::Sound*> gameSounds;

	audioSystem();
	~audioSystem();
	void loadSound(char fileName[]);
	void playAudio(int soundID);
	//void playAudio(std::string soundFilename);
};

