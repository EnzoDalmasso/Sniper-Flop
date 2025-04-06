#include "nivel1.h"


nivel1::nivel1(b2World* mundo)
{
	mundo1 = mundo;//Igualo el mundo que cree para enviarselo al mundo que recibe 

	iniciar_fisica();
	iniciar_imagenes();

	
	//Inicializo los cuerpos
	act_suelo = new actor(bdy_suelo, fig_suelo);
	act_arma = new actor(bdy_arma, fig_arma);
	act_pared = new actor(bdy_pared, fig_pared);
	act_pared2 = new actor(bdy_pared2, fig_pared2);
	act_pared3 = new actor(bdy_pared3, fig_pared3);
	act_caja = new actor(bdy_caja, fig_caja);
	act_techo = new actor(bdy_techo, fig_techo);
	act_pendulo = new actor(bdy_pendulo, fig_pendulo);

	//Inicializo el radgoll a NULL
	rag_1 = NULL;
	
	
	resortesPendulo(*mundo);

	//Inicio variables para texto, le seteo un color, origen, posicion, escala y tamanio
	fuente1 = new Font();
	fuente1->loadFromFile("Texto.otf");

	txt_nxtlevel = new Text();
	txt_nxtlevel->setFont(*fuente1);
	txt_nxtlevel->setFillColor(Color::White);
	txt_nxtlevel->setOrigin(txt_nxtlevel->getGlobalBounds().width / 2, txt_nxtlevel->getGlobalBounds().height / 2);
	txt_nxtlevel->setString("¡Bien hecho!");
	txt_nxtlevel->setPosition(50.f, 94.f);
	
	txt_nxtlevel->scale(0.05f, 0.05f);
	txt_nxtlevel->setCharacterSize(18.f);
	
	//Boton Siguiente Nivel
	//Cargo y le asigo las textura a su sprite, le seteo el origen, posicion y escala.
	txt_nxtLvl = new Texture();
	spr_nxtLvl = new Sprite();
	txt_nxtLvl->loadFromFile("nxtLevel.png");
	spr_nxtLvl->setTexture(*txt_nxtLvl);

	spr_nxtLvl->setOrigin(txt_nxtLvl->getSize().x / 2.f, txt_nxtLvl->getSize().y / 2.f);
	spr_nxtLvl->setPosition({ 52.5f, 96.f });
	spr_nxtLvl->setScale(0.01f,0.01f);
	
}

void nivel1::set_camara(RenderWindow* ventana)
{

	camara1 = new View({ 5.f,5.f }, { 10.f,10.f });
	camara1->move(47.f, 90.f);
	ventana->setView(*camara1);
	

}

//Esta funcion se utiliza para la fisica de los cuerpos que se van a crear en el mundo
void nivel1::iniciar_fisica()
{

	//Techo
	bdydef_techo.type = b2_staticBody;
	bdydef_techo.position = b2Vec2(50.f, 90.f);

	bdy_techo = mundo1->CreateBody(&bdydef_techo);

	b2PolygonShape shp_techo;
	shp_techo.SetAsBox(50.f, 0.2f);

	fixdef_techo.shape = &shp_techo;
	fixdef_techo.restitution = 0.f;
	fixdef_techo.friction = 0.3f;
	fixdef_techo.density = 1.f;

	fix_techo = bdy_techo->CreateFixture(&fixdef_techo);



	//suelo
	bdydef_suelo.type = b2_staticBody;
	bdydef_suelo.position = b2Vec2(50.f, 100.f);

	bdy_suelo = mundo1->CreateBody(&bdydef_suelo);
	 
	b2PolygonShape shp_suelo;
	shp_suelo.SetAsBox(50.f, 0.2f);

	fixdef_suelo.shape = &shp_suelo;
	fixdef_suelo.restitution = 0.f;
	fixdef_suelo.friction = 0.3f;
	fixdef_suelo.density = 1.f;

	fix_suelo = bdy_suelo->CreateFixture(&fixdef_suelo);

	//Cañon
	
	bdydef_arma.type = b2_staticBody;
	bdydef_arma.position = b2Vec2(48.5f, 98.f);

	bdy_arma = mundo1->CreateBody(&bdydef_arma);

	b2PolygonShape shp_arma;
	shp_arma.SetAsBox(0.8f, 0.3f);

	fixdef_arma.shape = &shp_arma;
	fixdef_arma.restitution = 0.1f;
	fixdef_arma.friction = 0.3f;
	fixdef_arma.density = 1.f;

	fix_arma = bdy_arma->CreateFixture(&fixdef_arma);

	//Pared IZQ
	bdydef_pared.type = b2_staticBody;
	bdydef_pared.position = b2Vec2(46.2f, 100.f);

	bdy_pared = mundo1->CreateBody(&bdydef_pared);

	b2PolygonShape shp_pared;
	shp_pared.SetAsBox(1.f, 20.f);

	fixdef_pared.shape = &shp_pared;
	fixdef_pared.restitution = 0.f;
	fixdef_pared.friction = 0.3f;
	fixdef_pared.density = 1.f;

	fix_pared = bdy_pared->CreateFixture(&fixdef_pared);


	//Pared DER
	bdydef_pared2.type = b2_staticBody;
	bdydef_pared2.position = b2Vec2(57.8f, 100.f);

	bdy_pared2 = mundo1->CreateBody(&bdydef_pared2);

	b2PolygonShape shp_pared2;
	shp_pared2.SetAsBox(1.f, 20.f);

	fixdef_pared2.shape = &shp_pared2;
	fixdef_pared2.restitution = 0.f;
	fixdef_pared2.friction = 0.3f;
	fixdef_pared2.density = 1.f;

	fix_pared2 = bdy_pared2->CreateFixture(&fixdef_pared2);

	//Pared sujeta caja
	bdydef_pared3.type = b2_staticBody;
	bdydef_pared3.position = b2Vec2(54.8f, 98.5f);

	bdy_pared3 = mundo1->CreateBody(&bdydef_pared3);

	b2PolygonShape shp_pared3;
	shp_pared3.SetAsBox(0.5f, 1.5f);

	fixdef_pared3.shape = &shp_pared3;
	fixdef_pared3.restitution = 0.f;
	fixdef_pared3.friction = 0.3f;
	fixdef_pared3.density = 1.f;

	fix_pared3 = bdy_pared3->CreateFixture(&fixdef_pared3);

	//Caja
	bdydef_caja.type = b2_dynamicBody;
	bdydef_caja.position = b2Vec2(54.8f, 96.07f);

	bdy_caja = mundo1->CreateBody(&bdydef_caja);

	b2PolygonShape shp_caja;
	shp_caja.SetAsBox(0.5f, 0.5f);

	fixdef_caja.shape = &shp_caja;
	fixdef_caja.restitution = 0.f;
	fixdef_caja.friction = 0.3f;
	fixdef_caja.density = 1.f;

	fix_caja = bdy_caja->CreateFixture(&fixdef_caja);

	//Pendulo
	bdydef_pendulo.type = b2_dynamicBody;
	bdydef_pendulo.position = b2Vec2(53.f, 96.f);

	bdy_pendulo = mundo1->CreateBody(&bdydef_pendulo);

	b2PolygonShape shp_pendulo;
	shp_pendulo.SetAsBox(0.1f, 1.f);

	fixdef_pendulo.shape = &shp_pendulo;
	fixdef_pendulo.restitution = 0.f;
	fixdef_pendulo.friction = 0.3f;
	fixdef_pendulo.density = 1.f;

	fix_pendulo = bdy_pendulo->CreateFixture(&fixdef_pendulo);

}

//Esta funcion crea una figura y le asigna el color.
void nivel1::iniciar_imagenes()
{
	fig_suelo = new RectangleShape;
	fig_arma = new RectangleShape;
	fig_pared = new RectangleShape;
	fig_pared2 = new RectangleShape;
	fig_pared3 = new RectangleShape;
	fig_caja = new RectangleShape;
	fig_pendulo = new RectangleShape;
	fig_techo = new RectangleShape;

	fig_suelo->setFillColor(Color::White);
	fig_arma->setFillColor(Color::Magenta);
	fig_pared->setFillColor(Color::White);
	fig_pared2->setFillColor(Color::White);
	fig_pared3->setFillColor(Color::White);
	fig_caja->setFillColor(Color::Blue);
	fig_techo->setFillColor(Color::White);
	fig_pendulo->setFillColor(Color::Red);
}


//Esta funcion recibe una ventana para dibujar los cuerpos. 
void nivel1::dibujar(RenderWindow* ventana)
{
	//Si el estado de nivel es 0 se dubujan los cuerpos
	if (estado_nivel ==0)
	{
		act_suelo->dibujar(ventana);
		act_arma->dibujar(ventana);
		act_pared->dibujar(ventana);
		act_pared2->dibujar(ventana);
		act_pared3->dibujar(ventana);
		act_caja->dibujar(ventana);
		act_techo->dibujar(ventana);
		act_pendulo->dibujar(ventana);


		rag_1->dibujar(ventana);


	}
	colision(ventana);

	//Si hubo colision del radgoll con la caja cambia el estado de nivel en 1 y dibuja un texto con un sprite
	if (estado_nivel == 1)
	{
		ventana->draw(*txt_nxtlevel);
		ventana->draw(*spr_nxtLvl);
	}
	
	
	
}

//Esta funcion recibe una ventana y verifica si hubo colision entre el radgoll y la caja
void nivel1::colision(RenderWindow* ventana)
{
	for (int i = 0; i < 6; i++)
	{
		rag_1->fig_rag[i];

		if (rag_1->fig_rag[i]->getGlobalBounds().intersects(fig_caja->getGlobalBounds())&& estado_nivel ==0)
		{
			estado_nivel = 1;
		}
		
		

	}


}
//Esta funcion recibe una posicion y se utiliza para disparar el radgoll
void nivel1::dispararCannon(Vector2f mousecord)
{
	
	//Si no existe ningun radgoll
	if (rag_1 == NULL)
	{
		//Crea un radgoll
		rag_1 = new radgoll({ bdy_arma->GetPosition().x + 1.5f,bdy_arma->GetPosition().y }, *mundo1);
	}
	else //En caso contrario
	{
		//Elimina el radgloll y crea otro nuevamente
		rag_1->eliminarRadgoll(*mundo1);
		rag_1 = new radgoll({ bdy_arma->GetPosition().x + 1.5f,bdy_arma->GetPosition().y }, *mundo1);
	}
	//Se aplica la fuerza de la clases ragdoll
	rag_1->aplicar_fuerza({ mousecord.x - bdy_arma->GetPosition().x,mousecord.y - bdy_arma->GetPosition().y });
}

//Esta funcion recibe una posicion y se utiliza para mover el cannon
void nivel1::moverCannon(Vector2f mousecord)
{

	bdy_arma->SetTransform(bdy_arma->GetPosition(), atan2f(mousecord.y - bdy_arma->GetPosition().y, mousecord.x - bdy_arma->GetPosition().x));

}
//Esta funcion recibe un mundo en la cual intancia un resorte entre dos cuerpos y los envia al mundo, a su vez se le aplica sus propiedades
void nivel1::resortesPendulo(b2World& mundo)
{

	//Resortes Pendulo
	jntdef_pendulo.Initialize(bdy_pendulo, bdy_techo, b2Vec2(bdy_pendulo->GetPosition().x, bdy_pendulo->GetPosition().y - 0.06), b2Vec2(bdy_techo->GetPosition().x + 3, bdy_techo->GetPosition().y));

	jntdef_pendulo.damping = 0.3f;
	jntdef_pendulo.stiffness = 4.0f;
	jntdef_pendulo.collideConnected = true;
	jntdef_pendulo.length = 0.025f;
	jnt_pendulo = (b2DistanceJoint*)mundo.CreateJoint(&jntdef_pendulo);

	

}

//Esta funcion recibe una posicion el cual detecta si el mouse colisiona con el sprite
bool nivel1::detectarBoton(Vector2f mouscord)
{
	//Si colisiona el mouse con el sprite 
	if (spr_nxtLvl->getGlobalBounds().contains(mouscord.x, mouscord.y))
	{
		
		return true;
	}

	return false;

}

//Esta funcion recibe un mundo en el cual se eliminan los cuerpos una vez que pasa al siguiente nivel
void nivel1::eliminarCuerpos(b2World& mundo1)
{
	mundo1.DestroyBody(bdy_caja);
	mundo1.DestroyBody(bdy_arma);
	mundo1.DestroyBody(bdy_pared);
	mundo1.DestroyBody(bdy_pared2);
	mundo1.DestroyBody(bdy_pared3);
	mundo1.DestroyBody(bdy_techo);
	mundo1.DestroyBody(bdy_pendulo);
	mundo1.DestroyBody(bdy_suelo);


}