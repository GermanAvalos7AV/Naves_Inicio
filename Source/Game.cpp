
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

CGame::CGame(){

	atexit(SDL_Quit);

	estado = ESTADO_INICIANDO;
	if (SDL_Init( SDL_INIT_VIDEO )){
	printf("Error %s ", SDL_GetError());
	exit(EXIT_FAILURE);
}
	screen = SDL_SetVideoMode( 640, 480, 24, SDL_SWSURFACE );

	if (screen == NULL){
	printf("Error %s ", SDL_GetError());
	exit(EXIT_FAILURE);
}
	SDL_WM_SetCaption( "Mi primer Juego", NULL );
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	SDL_Quit();

}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false)
	{
            
		//Maquina de estados
		switch(estado)
		{
			case Estado::ESTADO_INICIANDO: 
				break;
			case Estado::ESTADO_MENU:
				break;
			case Estado::ESTADO_JUGANDO:
				break;
			case Estado::ESTADO_FINALIZANDO:
				break;
			case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
			break;
		};

		//Este codigo estara provicionalmente aqui.
		SDL_Flip(screen);
    }
	return true;
}

