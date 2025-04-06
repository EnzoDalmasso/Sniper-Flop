#include "radgoll.h"


radgoll::radgoll(Vector2f posicion,b2World &mundo1)
{



	//Cuerpo Ragdoll


	//Posicionamos el cuerpo

	bdydef_rag[0].position = b2Vec2(posicion.x, posicion.y+0.1);//Pos cabeza 
	bdydef_rag[1].position = b2Vec2(posicion.x, posicion.y + 0.65);//Pos Torso 
	bdydef_rag[2].position = b2Vec2(posicion.x+0.32, posicion.y + 0.5);//Pos Brazo Der 
	bdydef_rag[3].position = b2Vec2(posicion.x-0.32, posicion.y + 0.5);//Pos Brazo Izq 
	bdydef_rag[4].position = b2Vec2(posicion.x+0.15, posicion.y + 1.5);//Pos Pierna Der 
	bdydef_rag[5].position = b2Vec2(posicion.x - 0.15, posicion.y + 1.5);//Pos Pierna Izq 

	//Defino el tipo de los cuerpos y se crean en el mundo
	for (int i = 0; i < 6; i++)
	{
		bdydef_rag[i].type = b2_dynamicBody;
		bdy_rag[i] = mundo1.CreateBody(&bdydef_rag[i]);
	}

	//Creo los poligono y sus tamaños
	b2PolygonShape shp_rag[6];

	//Dimensiones del cuerpo
	shp_rag[0].SetAsBox(0.1, 0.1);//Cabeza
	shp_rag[1].SetAsBox(0.2, 0.4);//Torso
	shp_rag[2].SetAsBox(0.07, 0.3);//Brazo Der
	shp_rag[3].SetAsBox(0.07, 0.3);//Brazi Izq
	shp_rag[4].SetAsBox(0.07, 0.4);//Pierna
	shp_rag[5].SetAsBox(0.07, 0.4);//Pierna  

	//Defino su densidad, friccion y resitutcion
	for (int i = 0; i < 6; i++)
	{
		fixdef_rag[i].shape = &shp_rag[i];
		fixdef_rag[i].density = 1.f;
		fixdef_rag[i].friction = 0.3f;
		fixdef_rag[i].restitution = 0.7f;
		fix_rag[i] = bdy_rag[i]->CreateFixture(&fixdef_rag[i]);


	}

	//Inicializo los Resortes
	jntdef_rag[0].Initialize(bdy_rag[0], bdy_rag[1], b2Vec2(bdy_rag[0]->GetPosition().x, bdy_rag[0]->GetPosition().y + 0.08), b2Vec2(bdy_rag[1]->GetPosition().x, bdy_rag[1]->GetPosition().y - 0.38));
	jntdef_rag[1].Initialize(bdy_rag[1], bdy_rag[2], b2Vec2(bdy_rag[1]->GetPosition().x + 0.18, bdy_rag[1]->GetPosition().y - 0.38), b2Vec2(bdy_rag[2]->GetPosition().x - 0.05, bdy_rag[2]->GetPosition().y - 0.28));
	jntdef_rag[2].Initialize(bdy_rag[1], bdy_rag[3], b2Vec2(bdy_rag[1]->GetPosition().x - 0.18, bdy_rag[1]->GetPosition().y - 0.38), b2Vec2(bdy_rag[3]->GetPosition().x + 0.05, bdy_rag[3]->GetPosition().y - 0.28));
	jntdef_rag[3].Initialize(bdy_rag[1], bdy_rag[4], b2Vec2(bdy_rag[1]->GetPosition().x + 0.09, bdy_rag[1]->GetPosition().y + 0.38), b2Vec2(bdy_rag[4]->GetPosition().x, bdy_rag[4]->GetPosition().y - 0.38));
	jntdef_rag[4].Initialize(bdy_rag[1], bdy_rag[5], b2Vec2(bdy_rag[1]->GetPosition().x + 0.09, bdy_rag[1]->GetPosition().y + 0.38), b2Vec2(bdy_rag[5]->GetPosition().x, bdy_rag[5]->GetPosition().y - 0.38));

	
	for (int i = 0; i < 5; i++)
	{
		jntdef_rag[i].damping = 0.3f;
		jntdef_rag[i].stiffness = 4.0f;
		jntdef_rag[i].collideConnected = true;
		jntdef_rag[i].length = 0.025f;

		jnt_rag[i] = (b2DistanceJoint*)mundo1.CreateJoint(&jntdef_rag[i]);
	}

	//Iniciando imagen

	for (int i = 0; i < 6; i++)
	{
		fig_rag[i] = new RectangleShape;
		
	}

	//Defino el color de las partes del cuerpo
	fig_rag[0]->setFillColor(Color::Green);
	fig_rag[1]->setFillColor(Color::Yellow);
	fig_rag[2]->setFillColor(Color::Red);
	fig_rag[3]->setFillColor(Color::Red);
	fig_rag[4]->setFillColor(Color::Blue);
	fig_rag[5]->setFillColor(Color::Blue);

	
	for (int i = 0; i < 6; i++)
	{
		act_rag[i] = new actor(bdy_rag[i], fig_rag[i]);
	}



}
//Esta funcion recibe una ventana para dibujar los cuerpos
void radgoll::dibujar(RenderWindow *ventana1)
{
	for (int i = 0; i < 6; i++)
	{
	act_rag[i]->dibujar(ventana1);
	}
}
//Esta funcion recibe una posicion para disparar el radgoll
void radgoll::aplicar_fuerza(Vector2f posicion_m)
{
	for (int i = 0; i < 6; i++)
	{
		bdy_rag[i]->ApplyForceToCenter(b2Vec2(posicion_m.x*140,posicion_m.y*140),false);
	}


}
//Esta funcion se utiliza para eliminar los cuerpos del ragdoll para que no queden dibujados en el mundo
void radgoll::eliminarRadgoll(b2World& mundo1)
{
	for (int i = 0; i < 6; i++)
	{
		mundo1.DestroyBody(bdy_rag[i]);

	}
	
	
}