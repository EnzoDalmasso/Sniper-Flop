#include "menu.h"

menu::menu()
{
	//Iniciializo los eventos, reloj y el tiempo
	evento1 = new Event;
	reloj1 = new Clock();
	tiempo1 = new Time();

	//Inicializo las texturas y los sprites
	txt_play = new Texture();
	txt_quit = new Texture();
	txt_fondo = new Texture();

	spr_play = new Sprite();
	spr_quit = new Sprite();
	spr_fondo = new Sprite();

	//Cargo y le asigo las texturas al sus respectivos sprites
	txt_play->loadFromFile("botonplay.png");
	txt_quit->loadFromFile("botonquit.png");
	txt_fondo->loadFromFile("fondomenu.png");

	spr_play->setTexture(*txt_play);
	spr_quit->setTexture(*txt_quit);
	spr_fondo->setTexture(*txt_fondo);

	//Seteo origenes de los sprites
	spr_play->setOrigin(txt_play->getSize().x / 2.f, txt_play->getSize().y / 2.f);
	spr_quit->setOrigin(txt_quit->getSize().x / 2.f, txt_quit->getSize().y / 2.f);
	spr_fondo->setOrigin(txt_fondo->getSize().x / 2.f, txt_fondo->getSize().y / 2.f);

	//Seteo la posicion de los sprites
	spr_fondo->setPosition({ 250.f, 250.f });
	spr_play->setPosition({ 450.f, 400.f });
	spr_quit->setPosition({ 450.f, 500.f });
	


}

//Esta funcion recibe una ventana para dibujar los sprites
void menu::dibujar(RenderWindow& ventana)
{
	ventana.draw(*spr_fondo);
	ventana.draw(*spr_play);
	ventana.draw(*spr_quit);


}
//Esta funcion recibe una posicion
int menu::procesar_eventos(Vector2f posicion_mouscord)
{
	//Si el mouse presion el sprite Play se inicia el juego
	if (spr_play->getGlobalBounds().contains(posicion_mouscord.x, posicion_mouscord.y))
	{
		
		return 1;
	}
	//Si el mouse presion el sprite Quit se sale el juego
	if (spr_quit->getGlobalBounds().contains(posicion_mouscord.x, posicion_mouscord.y))
	{
		
		return 0;
	}
	return -1;
}
