#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave{

int x;
int y;
int w;
int h;
int posicionActual;
int posicionFinal;
int posicionBrinco;
int stepsActual;
int stepsFinal;

Sprite * sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y);
	~Nave();

	void Pintar();
	void MoverDerecha(int posicion);
	void Mover(int brinco, int puntoFinal);
	void SetStep(int stepsFinal);
	void IncrementarStep();
	int ObtenerStepActual();
	void Actualizar();
	bool IsRunningAnimacion();
	void TerminarAnimacion(); // Fuerza para terminar la STEP actual de la nave

	int obtenerX();
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x , int y);
};

#endif