//====================================================================================================================================================
//	   Once Upon a Time in	   _____  .___  _______________________ ___    _________   _______________ _______										||
//	    					  /     \ |   |/   _____/\__    ___/   |   \  /  _  \   \ /   /\_   _____/ \      \										||
//	    					 /  \ /  \|   |\_____  \   |    | /    ~    \/  /_\  \   Y   /  |    __)_  /   |   \									||
//	    					/    Y    \   |/        \  |    | \    Y    /    |    \     /   |        \/    |    \									||
//	    					\____|__  /___/_______  /  |____|  \___|_  /\____|__  /\___/   /_______  /\____|__  /									||
//	    						    \/            \/                 \/         \/                 \/         \/                                    ||
//====================================================================================================================================================

			#include "Header.h"

//====================================================================================================================================================
//		SOUND FUNCTIONS                                                                       (00) - Used for sound in game.
//====================================================================================================================================================

	int playSound()
	{

			bool soundDone=false;
			//declare variable for FMOD system object
			FMOD::System* system;
			//allocate memory for the FMOD system object
			FMOD_RESULT result = FMOD::System_Create(&system);
			//initialize the FMOD system object
			system->init(32, FMOD_INIT_NORMAL, NULL);
			//declare variable for the sound object
			FMOD::Sound* sound;
			//created sound object and specify the sound 
			
			result = system->createSound("Climbing_a_Square_Tree (TeknoAXE).mp3",FMOD_LOOP_NORMAL,NULL, &sound);
			// play sound - 1st parameter can be combined flags (| separator)
			FMOD::Channel* channel = 0;
			bool pauseSound = false;

			//start sound

			channel->isPlaying(&pauseSound);

			result = system->playSound(FMOD_CHANNEL_FREE, sound,false, &channel);
			soundDone=true;


			while (soundDone!=true)
			{
			channel->setPaused(false);
			system->update();

			//}
			// release resources
			result = sound->release();
			result = system->close();
			result = system->release();
			}
			return 0;

	}

	
	int playBeepSound()
	{

			bool soundDone=false;
			//declare variable for FMOD system object
			FMOD::System* system;
			//allocate memory for the FMOD system object
			FMOD_RESULT result = FMOD::System_Create(&system);
			//initialize the FMOD system object
			system->init(32, FMOD_INIT_NORMAL, NULL);
			//declare variable for the sound object
			FMOD::Sound* sound;
			//created sound object and specify the sound

			result = system->createSound("Futuristic Fly.mp3",FMOD_DEFAULT,NULL, &sound);
			// play sound - 1st parameter can be combined flags (| separator)
			FMOD::Channel* channel = 0;
			bool pauseSound = false;

			//start sound

			channel->isPlaying(&pauseSound);

			result = system->playSound(FMOD_CHANNEL_FREE, sound,false, &channel);
			soundDone=true;


			while (soundDone!=true)
			{
			channel->setPaused(false);
			system->update();

			//}
			// release resources
			result = sound->release();
			result = system->close();
			result = system->release();
			}
			return 0;

	}


//====================================================================================================================================================
//		END OF CODE                                                                       (All work programmed by Aaron Alphonso, 2013)
//====================================================================================================================================================