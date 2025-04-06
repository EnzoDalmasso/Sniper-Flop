#pragma once
#include "actor.h"
#include "radgoll.h"
#include <iostream>
using namespace std;
using namespace sf;

class nivel1
{
public:
	nivel1(b2World* mundo);//El constructor recibe un mundo
	void iniciar_fisica();//Esta funcion se utiliza para iniciar las fisicas de los cuerpos
	void iniciar_imagenes();//Esta funcion se utiliza para dibujar las figuras y a su vez el color
	void dibujar(RenderWindow *ventana);//Recibe una ventana para dibujar
	void set_camara(RenderWindow *ventana);//Esta funcion se utiliza para setear la camara
	void colision(RenderWindow *ventana);//Esta funcion se utiliza cuando el cuerpo radgoll colisiona con el cuerpo de la caja
	void moverCannon(Vector2f mousecord);//Esta funcion se utiliza para mover el cannon 
	void dispararCannon(Vector2f mouscord);//Esta funcion se utiliza para disparar el radgoll desde el cuerpo del cannon
	void resortesPendulo(b2World& mundo);//Funcion para realizar el resorte al pendulo y a su vez sus propedades. A su vez recibe un mundo.
	bool detectarBoton(Vector2f mouscord);//Funcion que recibe un vector que se utiliza para avanzar al siguiente nivel
	int estado_nivel;//Se crea variable para verificar si se dibujan los cuerpos o se avanza al siguiente nivel.
	void eliminarCuerpos(b2World& mundo1);//Funcion que recibe un mundo. Se utiliza para eliminar los cuerpos para evitar que queden en el siguiente nivel


private:
	//Creo una textura  y un Sprite
	Texture* txt_nxtLvl;
	Sprite* spr_nxtLvl;

	//Creo una camara y un evento
	View *camara1;
	Event* evento1;

	//variables para el tiempo global del juego
	Time* tiempo1;
	Clock* reloj1;
	float fps, tiempoFrame, tiempo2;


	b2World* mundo1;//Creo un mundo

	//Creo los textos para el nivel
	Font* fuente1;
	Text* txt_nxtlevel;

	
	//Creo los cuerpo de referencia para el que se va a recibir
	
	//Techo

	b2Body* bdy_techo;
	b2BodyDef bdydef_techo;
	b2Fixture* fix_techo;
	b2FixtureDef fixdef_techo;

	//Piso

	b2Body* bdy_suelo;
	b2BodyDef bdydef_suelo;
	b2Fixture* fix_suelo;
	b2FixtureDef fixdef_suelo;

	//Cañon
	b2Body* bdy_arma;
	b2BodyDef bdydef_arma;
	b2Fixture* fix_arma;
	b2FixtureDef fixdef_arma;

	//Pared
	b2Body* bdy_pared;
	b2BodyDef bdydef_pared;
	b2Fixture* fix_pared;
	b2FixtureDef fixdef_pared;


	//Pared2
	b2Body* bdy_pared2;
	b2BodyDef bdydef_pared2;
	b2Fixture* fix_pared2;
	b2FixtureDef fixdef_pared2;

	//Pared3
	b2Body* bdy_pared3;
	b2BodyDef bdydef_pared3;
	b2Fixture* fix_pared3;
	b2FixtureDef fixdef_pared3;


	//Caja
	b2Body* bdy_caja;
	b2BodyDef bdydef_caja;
	b2Fixture* fix_caja;
	b2FixtureDef fixdef_caja;

	//Pendulo
	b2Body* bdy_pendulo;
	b2BodyDef bdydef_pendulo;
	b2Fixture* fix_pendulo;
	b2FixtureDef fixdef_pendulo;

	////Creo las figura de referencia para el que se va a recibir
	RectangleShape* fig_arma;
	RectangleShape* fig_suelo;
	RectangleShape* fig_pared;
	RectangleShape* fig_pared2;
	RectangleShape* fig_pared3;
	RectangleShape* fig_caja;
	RectangleShape* fig_techo;
	RectangleShape* fig_pendulo;

	//Clases adicionales
	actor* act_suelo;
	actor* act_arma;
	actor* act_pared;
	actor* act_pared2;
	actor* act_pared3;
	actor* act_caja;
	actor* act_techo;
	actor* act_pendulo;

	radgoll* rag_1;

	//Creo los resortes para el pendulo
	b2DistanceJoint* jnt_pendulo;
	b2DistanceJointDef jntdef_pendulo;



};

