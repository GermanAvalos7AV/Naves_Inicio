#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen){
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	x=(WIDTH_SCREEN/2)-(sprite->WidthImage()/2);
	x=(HEIGHT_SCREEN-80)-(sprite->WidthImage()/2);

}

Nave::~Nave(){
	delete sprite;
}

void Nave::Pintar(){
	sprite->PintarModulo(0,x,y);
}