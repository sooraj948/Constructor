#pragma once
#include "SDL_mixer.h"
void mu(int a)
{
	if (a == 0) {
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("images/rotate.ogg");
		Mix_PlayMusic(music, 1);
	}
	else if (a == 1)
	{
		//drop
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("images/drop.ogg");
		Mix_PlayMusic(music, 1);
	
	}
	else if (a == 2)
	{
		//drop perfect
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("images/drop-perfect.ogg");
		Mix_PlayMusic(music, 1);
		
	}
	else if (a == 3)
	{
		//gameover
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("images/game-over.ogg");
		Mix_PlayMusic(music, 1);
		
	}


}
