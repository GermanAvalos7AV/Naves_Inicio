#include "Nave.h"
#include "Config.h"
#include "Sprite.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y){
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w=sprite->WidthModule(0);
	h=sprite->HeightModule(0);

	this->x=x; 
	this->y=y; 
}
Nave::~Nave(){
	delete sprite;
}
void Nave::Pintar(){
	sprite->PintarModulo(0,x,y);
}
void Nave::MoverDerecha(int posicion){
	x += posicion;
}
int Nave::obtenerX(){
	return x;
}
int Nave::obtenerY(){
	return y;
}
int Nave::obtenerW(){
	return w;
}
int Nave::obtenerH(){
	return h;
}

void Nave::ponerEn(int x, int y){
	this->x=x;
	this->y=y;

}