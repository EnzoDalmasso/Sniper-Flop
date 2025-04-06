#include "SFML/Graphics.hpp"
#include <iostream>
#include "nivel1.h"
#include "nivel2.h"

using namespace sf;

using namespace std;

class menu
{
public:
	menu();
	int procesar_eventos(Vector2f posicion_mouscord);//Recibe un vector para poder procesar los eventos
	void dibujar(RenderWindow& ventana);//Recibe una ventana para dibujar
	
private:
	//Creo una camara y un evento
	View* camara1;
	Event* evento1;

	//variables para el tiempo global del juego
	Time* tiempo1;
	Clock* reloj1;
	float fps, tiempoFrame, tiempo2;

	//Creo las texturas y los sprites para la opcion menu
	Texture* txt_play;
	Texture* txt_quit;
	Texture* txt_fondo;

	Sprite* spr_play;
	Sprite* spr_quit;
	Sprite* spr_fondo;
};