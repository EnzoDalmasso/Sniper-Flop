#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


using namespace std;

class actor
{

public:
	actor(b2Body * cuerpo, RectangleShape *figura);//Recibe un cuerpo y una figura para combinar
	void dibujar(RenderWindow* ventana);//Recibe una ventana para dibujar
	float rad2deg(float radianes);//Recibe un flotante para transformar
	float deg2rad(float grados);//Recibe un flotante para transformar

private:

	b2Body* bdy_actor;//Creo un cuerpo de referencia para el que se va a recibir
	RectangleShape* fig_actor;//Creo una figura de referencia para el que se va a recibir

	b2AABB dimensiones;//Creo dimensiones para escalar la figura
	b2Vec2 posicion;//Creo un vector para utilizar una posicion


};

