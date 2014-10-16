#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class CGame
{
public:


	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZADO,
	};

private:
	void Iniciando();

	Uint8 *keys;//esta variable nos servira paea ver si determinada tecla
	SDL_Event event;//La Variaevent de tipo evento de SDL Nos Sirve para

	SDL_Surface *screen;
	Sprite * nave;
	Estado estado;


};

