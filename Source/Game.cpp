#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){
	estado = ESTADO_INICIANDO;//ACT2: Mal, aqui debes de poner tu estado inicial, por eso te marcara error.
	atexit(SDL_Quit);

	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE );

	if (screen == NULL){
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen); // este codigo estara provicionalmente aqui.
	SDL_WM_SetCaption( "Mi Primer Juego", NULL);
	nave= new Sprite();
	nave->cargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;

	while (salirJuego == false){

		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			/*	nave = SDL_LoadBMP("../Data/MiNave.bmp");
			SDL_Rect Fuente;
			Fuente.x =90;
			Fuente.y =152;
			Fuente.w =242;
			Fuente.h =76;
			SDL_Rect destino;
			destino.x =100;
			destino.y =100;
			destino.w =100;
			destino.h =100;
			SDL_BlitSurface(nave, &Fuente, screen, &destino);
			SDL_BlitSurface(nave, NULL, screen, NULL);
			SDL_FreeSurface(nave);
			*/

		case Estado::ESTADO_MENU:	//MENU
			Iniciando();
			estado=ESTADO_MENU;
			break;
		case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
		case Estado::ESTADO_TERMINANDO:	//TERMINAR ///ACT2:Mal, Este estado estaba mal escrito
			break;
		case Estado::ESTADO_FINALIZADO: //SALIR
			salirJuego = true;
			break;
		};

		SDL_Flip(screen); //imprime en pantalla variable screen
		return true;
	}



