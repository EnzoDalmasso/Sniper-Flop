#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"
#include "nivel1.h"
#include "nivel2.h"

using namespace sf;

using namespace std;

class administrador
{
public:
	administrador(Vector2i resolucion, string titulo);//El constructor recibe dos variables
	void procesar_eventos();//Esta funcion se utiliza para detectar las teclas
	void gameLoop();//Dibujar en pantalla y el bucle principal
	void dibujar();//Esta funcion se utiliza para dibujar la escena segun el estado del juego
	void cambioEscenas();//Esta funcion se utiliza para realizar los cambios de escenas
	void actualizar_fisica();//Esta funcion se utiliza para actualizar la fisica de los cuerpos
private:
	//Creo una ventana
	RenderWindow* ventana1;

	//Creo un evento
	Event* evento1;

	//variables para el tiempo global del juego
	Time* tiempo1;
	Clock* reloj1;

	float fps, tiempoFrame, tiempo2;

	int estado_juego;//Se crea variable para verificar el estado de las escenas,

	//Clases adicionales
	menu* menu_principal;
	nivel1* lv1;
	nivel2* lv2;
	
	//Creo un mundo
	b2World* mundo1;

};