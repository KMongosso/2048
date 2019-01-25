#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.hh"
#include "Map.hh"
#include "direction.hh"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <SDL2_Mixer/SDL_Mixer.h>
#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>

/*https://freesound.org/people/joshuaempyre/sounds/251461/*/

using namespace std;

class Game{
	public:
		//Constructeur
		Game(const char* title, int x, int y, int width, int height);

		//Destructeur
		~Game();

		//Fonctions Membres
		void handleEvent();

		void update();
		void render();

		void initGrid();
		void draw();
		bool full();
		void add();
		bool occupated(int x, int y);
		bool getRunning(){return isRunning;}

		static SDL_Renderer* renderer;
		static SDL_Event event;


	private:
		int _width,_height;		//Dimensions de l'écran
		SDL_Rect src, dest;
		SDL_Texture* nb;
		SDL_Texture* L;
		SDL_Texture* W;

		string fichier;
		const char * fichierc;
		int iter;

		SDL_Window *window;
		int **screen;		//Informations relatives à l'écran
		int **screen_bis;	

		bool isRunning, win, lose;		//Indique si le jeu est toujours en cours	  
};



