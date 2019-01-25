#include <SDL2/SDL.h> 
#include "Game.hh"

Game *game;

int main(int argc,const char * argv[]){
    /*Vitesse du jeu*/
    const int FPS = 60, FrameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

    /*Mis en place de la musique*/
    Mix_Music *musique;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4); 
    musique = Mix_LoadMUS("Sons/theme.wav"); 
    Mix_PlayMusic(musique, -1); 
    
    /*Initialisation du jeu*/
    game = new Game("Projet",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,740,740);

    /*Boucle de jeu*/
    while(game->getRunning()){
            game->handleEvent();
            game->update();
            game->render();
    	frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks()-frameStart;

        if(FrameDelay>frameTime){ 
        	SDL_Delay(FrameDelay-frameTime);
        }
    }
    
    Mix_CloseAudio();
    return 0; 
}