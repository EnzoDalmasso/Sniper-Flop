#include "actor.h"


actor::actor(b2Body* cuerpo, RectangleShape* figura) : bdy_actor(cuerpo), fig_actor(figura)
{
	posicion = bdy_actor->GetPosition();//Igualo la posicion a la del cuerpo

	//Escalo las dimensiones de los cuerpos a su figura
	dimensiones.lowerBound = b2Vec2(FLT_MAX, FLT_MAX);
	dimensiones.upperBound = b2Vec2 (-FLT_MAX, -FLT_MAX);

	for (b2Fixture* i = bdy_actor->GetFixtureList(); i; i = i->GetNext())
	{
		dimensiones = i->GetAABB(0);
	}

	//Defino su tanaño, origen y posicion
	fig_actor->setSize({ dimensiones.GetExtents().x * 2,dimensiones.GetExtents().y * 2 });
	
	fig_actor->setOrigin(fig_actor->getSize().x / 2.f, fig_actor->getSize().y / 2.f);

	fig_actor->setPosition(posicion.x, posicion.y);
}
//Esta funcion recibe una ventana para dibujar los cuerpos, darle su rotacion. 
void actor::dibujar(RenderWindow *ventana)
{
	posicion = bdy_actor->GetPosition();

	fig_actor->setPosition(posicion.x, posicion.y);

	fig_actor->setRotation(rad2deg(bdy_actor->GetAngle()));
	ventana->draw(*fig_actor);
}


//De grados a radianes
float actor::deg2rad(float grados)
{
	float pi = 3.14;
	return grados * pi / 180;
}

//De radianes a grados
float actor::rad2deg(float radianes)
{
	float pi = 3.14;
	return radianes / pi * 180;
}
