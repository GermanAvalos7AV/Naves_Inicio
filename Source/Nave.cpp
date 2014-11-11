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
	stepsActual=0;
	posicionBrinco=0;
	posicionActual=0;
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

void Nave::Mover(int brinco, int puntoFinal){
	if (posicionBrinco<=0){
	posicionBrinco=brinco;
	posicionFinal=puntoFinal;
	}
}

void Nave::Actualizar(){
	if(posicionBrinco!=0){
		if(posicionActual <=posicionFinal){
		MoverDerecha(posicionBrinco);
		posicionActual++;
	}else{
			TerminarAnimacion();
	}
	}

}

void Nave::SetStep(int stepsFinal){
	this->stepsFinal = stepsFinal;
}

void Nave::IncrementarStep(){
	stepsActual++;
	if(stepsActual >= stepsFinal)
		stepsActual=0;
}

int Nave:: ObtenerStepActual(){
	return stepsActual;
}
	bool Nave::IsRunningAnimacion(){
		if(posicionBrinco==0)
			return false;
		else
			return true;
	}

	void Nave:: TerminarAnimacion(){
		posicionBrinco = 0;
		posicionActual = 0;
		posicionFinal = 0;
		IncrementarStep();
	}