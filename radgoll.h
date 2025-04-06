#pragma once
#include "actor.h"

class radgoll
{
public:
	radgoll(Vector2f posicion, b2World& mundo1);//Recibe una posicion y un mundo
	void dibujar(RenderWindow* ventana1);//Funcion para recibir una pantalla
	void aplicar_fuerza(Vector2f posicion_m);//Funcion para aplicar fuerzas al radgoll
	RectangleShape* fig_rag[6];//Rectangulos para crear cuerpos de rag
	b2Body* bdy_rag[6];//Cuerpos del radgoll
	void eliminarRadgoll(b2World& mundo1);//Recibe un mundo para dibujar el ragdoll
private:

	//Clse adicional
	actor* act_rag[6];

	//Creando los Resortes del ragdoll
	b2DistanceJoint* jnt_rag[5];
	b2DistanceJointDef jntdef_rag[5];

	//Ragdoll
	b2BodyDef bdydef_rag[6];
	b2Fixture* fix_rag[6];
	b2FixtureDef fixdef_rag[6];

};

