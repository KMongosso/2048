#include "Game.hh"

/*Déclaration de classes*/
Map* carte;

/*SDL*/
SDL_Renderer* Game::renderer ;	
SDL_Event Game::event;
SDL_Texture* tex;


//////////////////*Constructeur*//////////////////

Game::Game(const char* title, int x, int y, int width, int height){
	_width = width;
	_height = height;

	if(SDL_Init(SDL_INIT_EVERYTHING)==0){	

		window = SDL_CreateWindow(title, x, y, width, height,0);	

		renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_TARGETTEXTURE);
		//SDL_SetRenderDrawColor(renderer,255,255,255,255);			//Permet de définir la couleur par défaut de la fenêtre graphique
			
		isRunning = true;
	}
	else{

		isRunning = false;
	}


	screen = new int*[4];
	for(int i=0;i<4;i++){
		screen[i] = new int[4];
	}
		
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			screen[j][i] = 0;
		}
	}

	screen_bis = new int*[4];
	for(int i=0;i<4;i++){
		screen_bis[i] = new int[4];
	}

	src.x = src.y = src.w = src.h =0;
	dest.w=dest.h=160;
	
	carte = new Map();
	iter=0;
	lose=0;
	win=0;
	initGrid();

}

//////////////////*Destructeur*//////////////////

Game::~Game(){
	for(int i=0;i<4;i++){
		delete[] screen[i];
	}
	
	delete[] screen;

	for(int i=0;i<4;i++){
		delete[] screen_bis[i];
	}
	
	delete[] screen_bis;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

//////////////////*Fonctions Membres*//////////////////

void Game::initGrid(){
	srand(time(NULL));
	int x, y, nb;

	for(int i=0;i<3;i++){
		x=rand()%4;
		y=rand()%4;
		nb=rand()%2;

		if(nb==0)
			screen[y][x]=2;
		else
			screen[y][x]=4;
	}
}

bool Game::occupated(int x, int y){
	if(screen[y][x]!=0)
		return 1;
	
	else
		return 0;
}

void Game::add(){
	int x, y, nb;

	do{
		x=rand()%4;
		y=rand()%4;
		nb=rand()%2;
	}
	while(occupated(x,y));
	
	
	if(nb==0)
		screen[y][x]=2;
	else
		screen[y][x]=4;

	cout << endl;
}

bool Game::full(){
	bool full=1;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(screen[j][i]==0)
				full=0;
		}
	}

	return full;
}

/*Met àjour isRunning si on quitte le jeu*/
void Game::handleEvent(){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break; 
	}
}



/*Met à jour le jeu*/
void Game::update(){
	bool same=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			screen_bis[j][i]=screen[j][i];
		}
	}

	if(iter>5){
		if(Game::event.type == SDL_KEYDOWN){
			switch(Game::event.key.keysym.sym){
				case SDLK_LEFT:		//Flèche Gauche
					left(screen);
					iter=0;
					break;

				case SDLK_DOWN:		//Flèche Bas
					down(screen);
					iter=0;
					break;

				case SDLK_RIGHT:	//Flèche Droite
					right(screen);
					iter=0;
					break;

				case SDLK_UP:		//Flèche Haute
					up(screen);
					iter=0;
					break;

				default:
					break;
			}

			same=1;

			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(screen[j][i]!=screen_bis[j][i])
						same=0;
				}
			}

			if(!same)
				add();
		}
	}
	iter++;

	if(full() && same)
		lose=1;
}

/*Ajoute toutes les textures sur le render*/
void Game::render(){
	SDL_RenderClear(renderer);

	if(!win && !lose){
		carte->Draw();
		draw();
	}
	else if(lose){
		dest.w=dest.h=740;
		dest.x = dest.y=0;
		L = TextureManager::LoadTexture("Images/L.png");
		TextureManager::Draw(L,src,dest);
	}
	else{
		dest.w=dest.h=740;
		dest.x = dest.y=0;
		W = TextureManager::LoadTexture("Images/W.png");
		TextureManager::Draw(W,src,dest);
	}
		
	SDL_RenderPresent(renderer);
}

void Game::draw(){
		for(int j=0;j<4;j++){
			for(int i=0;i<4;i++){
				if(screen[i][j]!=0){
					dest.x = 20+i*dest.w +i*20;
					dest.y = 20+j*dest.h +j*20;
					fichier = "Images/" + to_string(screen[i][j]) + ".png"; 
					fichierc = fichier.c_str();
					nb = TextureManager::LoadTexture(fichierc);
					TextureManager::Draw(nb,src,dest);
				}
			}
		}

}


