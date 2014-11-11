#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Nave.h"

CGame::CGame(){
	frames = 0;
	tiempoFrameInicio = 0;
	estado = Estado::ESTADO_INICIANDO;//ACT2: Mal, aqui debes de poner tu estado inicial, por eso te marcara error.
	atexit(SDL_Quit);
}
void CGame::Iniciando(){

	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE );

	if (screen == NULL){
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen); // este codigo estara provicionalmente aqui.
	SDL_WM_SetCaption( "Naves al ATAQUE", NULL);

	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/);
	

	enemigoArreglo = new Nave*[10];
	for (int i =0; i < 10; i++)
	enemigoArreglo[i]= new Nave(screen, "../Data/enemigo.bmp",i*65,0);

	//enemigoParabola=-10.0f;
	
	for(int i = 0; i<10; i++)
		enemigoArreglo[i] -> SetStep(4);
	///
	//nave->CargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
////void CGame::Finalize(){
////	SDL_Quit();
////}
void CGame::Finalize()
{
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
				//switch(estado){
				Iniciando();
				estado=ESTADO_MENU;
				break;
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
				
			case Estado::ESTADO_MENU:
				//MENU
				////nave->PintarModulo (0,0,0,64,64);
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);
			
			for (int i =0; i < 10; i++)
			enemigoArreglo[i] -> Actualizar();
			MoverEnemigo();
			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave,BORDE_DERECHO)){
				
				

			//nave->PintarModulo(0,100,100);
			nave->MoverDerecha(1);
			///Iniciando();
				///estado=ESTADO_MENU;
			}
			nave->Pintar();
			
			for (int i =0; i < 10; i++)
			enemigoArreglo[i] -> Pintar();
			break;
			case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};
				while (SDL_PollEvent(&event))//aqui SDL creara una lista de eventos ocurr
				{
					if (event.type == SDL_QUIT){salirJuego =true;}//si se detecta una
						if (event.type == SDL_KEYDOWN){}
				}
		SDL_Flip(screen); //imprime en pantalla variable screen

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal < (tiempoFrameInicio + FPS_DELAY))
			tiempoFrameFinal = SDL_GetTicks();

		printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n", frames,tiempoFrameInicio,tiempoFrameFinal-tiempoFrameInicio,1000.0f / (float)(tiempoFrameFinal-tiempoFrameInicio));
		tiempoFrameInicio = tiempoFrameFinal;
    }
	return true;
}
bool CGame::esLimitePantalla(Nave *objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO)
		if (objeto->obtenerX() <=0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if (objeto->obtenerY() <=0)
			return true;
	if(bandera & BORDE_DERECHO)
		if (objeto->obtenerX() >=(WIDTH_SCREEN-objeto->obtenerW()))
			return true;
	if(bandera & BORDE_INFERIOR)
		if (objeto->obtenerY() >=(HEIGHT_SCREEN-objeto->obtenerH()))
			return true;
	return false;
}


void CGame::MoverEnemigo(){
	//if(!esLimitePantalla(enemigo, BORDE_DERECHO))
	//enemigo->MoverDerecha(1);
	
					
				
	//enemigo->ponerEn(enemigoParabola*enemigoParabola,enemigoParabola);
	//enemigoParabola+=0.1f;
	for (int i= 0; i<10; i++)
	switch(enemigoArreglo[i]->ObtenerStepActual()){
				case 0:
					
					if(!enemigoArreglo[i]->IsRunningAnimacion())
						enemigoArreglo[i]->Mover(1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
						//enemigo->IncrementarStep();
					//enemigo->Mover(1,50);

					break;
				case 1:
					enemigoArreglo[i]->IncrementarStep();
					break;
				case 2:
					if(!enemigoArreglo[i]->IsRunningAnimacion())
						enemigoArreglo[i]->Mover(-1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
					
					break;
				case 3:
					enemigoArreglo[i]->IncrementarStep();
					break;
				}
}