#ifndef _SPRITE_H_
#define _SPRITE_M_

#include <SDL.h>

class Sprite{
	SDL_Surface *image;
	SDL_Surface *screen;
public:
	void CargarImagen(char* ruta);
	void PintarModulo(int id, int x, int y, int h);
	Sprite(SDL_Surface* screen);
	~Sprite();
}
#endif
