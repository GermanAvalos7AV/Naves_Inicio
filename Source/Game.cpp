#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado == 0;//ACT2: Esto esta mal, estas haciendo una comparacion, lo que debes de hacer es inicializar tu estado.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){////ACT 2: No suficiente, te falto agregar 2 estados mas de los 5 que les inique.
			case Estado::ESTADO_INICIANDO:
				break;
				case Estado::ESTADO_JUGANDO:
			break;
				case Estado::ESTADO_TERMINANDO:
					salirJuego = true;
			break;
		};
	return true;
}
