#include "Map.hh"

//////////////////*Costructeur*//////////////////

Map::Map(){
	/*On stockera toutes les textures dans un vecteur ça évitera le switch case dans Draw*/
	grey = TextureManager::LoadTexture("Images/gris.png");

	src.x = src.y = 0;
	src.w = dest.w = 160;	/*Dimensions de chaque élément du fond */
	src.h = dest.h = 160;
 	dest.x = dest.y = 0;
}

//////////////////*Destructeur*//////////////////

Map::~Map(){

}

//////////////////*Fonctions Membres*//////////////////


void Map::Draw(){

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dest.x = 20+j*20+j*dest.w;
			dest.y = 20+i*20+i*dest.h;
			TextureManager::Draw(grey,src,dest);
		}
	}

}