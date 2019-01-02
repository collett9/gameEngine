#include "audioSystem.h"
#include <iostream>

audioSystem::audioSystem()
{

	system = NULL;
	lowLevelSystem = NULL;

	
	FMOD::Studio::System::create(&system);

	if (system)
	{
		std::cout << "Audio system created!" << "/n";
	}

	system->getLowLevelSystem(&lowLevelSystem);

	if (lowLevelSystem) {
		std::cout << "Low-level (fmod) audio system created." << "\n";
	}


	lowLevelSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_STEREO, 0);
	system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, NULL);




}


audioSystem::~audioSystem()
{
}

void audioSystem::loadSound(char fileName[])
{
	FMOD::Sound* newSound = NULL;

	lowLevelSystem->createSound(fileName, FMOD_LOOP_OFF, NULL, &newSound);

	//newSound.setdef

	gameSounds.push_back(newSound);


}



void audioSystem::playAudio(int soundId)
{
	

	//lowLevelSystem->createSound(soundName, FMOD_LOOP_OFF, NULL, &meow);
	//"meow.wav" backup

	//meow->setDefaults(16400, 0);


	//if (meow) {
	//	std::cout << "Sound loaded." << "\n";
	//}


	if (soundId < gameSounds.size())
	{
		lowLevelSystem->playSound(gameSounds[soundId], NULL, false, &catChannel);
	}

	else 
	{
		std::cout << "The sound is not loaded!" << "\n";
	}

	meow = NULL;
}
