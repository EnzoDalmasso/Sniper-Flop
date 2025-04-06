#include "administrador.h"

administrador::administrador(Vector2i resolucion, string titulo)
{
	//Creo una ventana
	ventana1 = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
	
	//Inicializo variables de tiempo y fps
	fps = 60;
	tiempoFrame = 1 / 180.f;
	tiempo2 = 0;
	ventana1->setFramerateLimit(fps);
	

	
	//Inicializo variables tiempo y eventos
	evento1 = new Event;
	reloj1 = new Clock();
	tiempo1 = new Time();
	estado_juego = 0;

	
	//Creo el menu
	menu_principal = new menu();

	//Creo el mundo
	mundo1 = new b2World(b2Vec2(0.f, 80.f));


	gameLoop();
}

//Bucle principal
void administrador::gameLoop()
{
	while (ventana1->isOpen())
	{
		//Tiempo1 recibe el tiempo de la maquina(que se lo da reloj 1 mientras la ventana este abierta)
		*tiempo1 = reloj1->getElapsedTime();
		if (tiempo2 + tiempoFrame < tiempo1->asSeconds())
		{
			tiempo2 = tiempo1->asSeconds();//Actualizamos tiempo2 
			//Procesos para dibujar en la ventana
			ventana1->clear();//Limpio la ventana, para volver a utilizar
			
			
			actualizar_fisica();//Llamo a la funcion de fisicas para actualizar

			procesar_eventos();//Procesa el teclado
			dibujar();//Dibuja los niveles

			

			
			ventana1->display();



		}
	}



}

void administrador::procesar_eventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			exit(1);
			break;

		case Event::MouseButtonPressed:

			if (estado_juego==0)

			{
				
				Vector2i posicion_mouse;
				Vector2f posicion_mouscord;

				posicion_mouse = Mouse::getPosition(*ventana1);
				posicion_mouscord = ventana1->mapPixelToCoords(posicion_mouse);

				//Se crea una variable auxiliar a la que se iguala al procesar eventos 
				int aux= menu_principal->procesar_eventos(posicion_mouscord);

				//Si auxiliar tiende a 1
				if (aux==1)
				{
					//Se cambia de escena
					cambioEscenas();
				}
				//Si auxiliar tiende a 0
				if (aux == 0)
				{

					//Finaliza el programa
					exit(1);
				}
				
			}
			//Si el estado de juego tiende a 1
			if (estado_juego == 1)
			{
				//Este vector se utiliza para posicionar el mouse
				Vector2i posicion_mouse;
				//Este vector se utiliza para posicionar el mouse segun la ventana de juego
				Vector2f posicion_mouscord;

				posicion_mouse = Mouse::getPosition(*ventana1);
				posicion_mouscord = ventana1->mapPixelToCoords(posicion_mouse);


				//Si estado de nivel tiende a 0
				if (lv1->estado_nivel==0 )
				{
					//Llamamos a la funcion de disparar el cannon
					lv1->dispararCannon(posicion_mouscord);
					
				}
				//Si estado de nivel  tiende a 1 y e detecta el boton siguiente nivel, se cambia de escena
				if (lv1->estado_nivel == 1)
				{
					
					if (lv1->detectarBoton(posicion_mouscord))
					{
						cambioEscenas();
					}
					
					
				}
			
			
				
			}

			
			
			if (estado_juego == 2)
			{
				//Este vector se utiliza para posicionar el mouse
				Vector2i posicion_mouse;
				//Este vector se utiliza para posicionar el mouse segun la ventana de juego
				Vector2f posicion_mouscord;

				posicion_mouse = Mouse::getPosition(*ventana1);
				posicion_mouscord = ventana1->mapPixelToCoords(posicion_mouse);


				
				//Si estado de nivel tiende a 0
				if (lv2->estado_nivel == 0)
				{
					//Llamamos a la funcion de disparar el cannon
					lv2->dispararCannon(posicion_mouscord);

				}
				//Si estado de nivel  tiende a 1 y e detecta el boton siguiente nivel, se cambia de escena
				if (lv2->estado_nivel == 1)
				{
					if (lv2->detectarBoton(posicion_mouscord))
					{
						exit(1);
					}


				}
			}
			
			
			case Event::MouseMoved:
				
				if (estado_juego == 1)
				{
					//Este vector se utiliza para posicionar el mouse
					Vector2i posicion_mouse;
					//Este vector se utiliza para posicionar el mouse segun la ventana de juego
					Vector2f posicion_mouscord;

					posicion_mouse = Mouse::getPosition(*ventana1);
					posicion_mouscord = ventana1->mapPixelToCoords(posicion_mouse);

					
					//LLamos a la funcion de mover el cannon
					lv1->moverCannon(posicion_mouscord);
					
				}
				
				
				if (estado_juego == 2)
				{
					//Este vector se utiliza para posicionar el mouse
					Vector2i posicion_mouse;
					//Este vector se utiliza para posicionar el mouse segun la ventana de juego
					Vector2f posicion_mouscord;

					posicion_mouse = Mouse::getPosition(*ventana1);
					posicion_mouscord = ventana1->mapPixelToCoords(posicion_mouse);


					//LLamos a la funcion de mover el cannon
					lv2->moverCannon(posicion_mouscord);
					
				}
			
				
				
				

			
			break;
		}

		break;

	}

}

void administrador::dibujar()
{

	//Si el estado de juego tiende a 0
	if (estado_juego==0)
	{
		//Llamo al menu para dibujar en la ventana
		menu_principal->dibujar(*ventana1);
	}
	//Si el estado de juego tiende a 1
	if (estado_juego==1)
	{
		
		//Llamo al nivel1 para dibujar en la ventana
		lv1->dibujar(ventana1);

	
	}
	//Si el estado de juego tiende a 1
	if (estado_juego == 2)
	{
	
		//Llamo al nivel2 para dibujar en la ventana
		lv2->dibujar(ventana1);
	
	}

}

void administrador::cambioEscenas()
{
	//Si el estado de juego tiende a 0
	if (estado_juego==0)
	{
		//Estado de juego se incrementa y crea el nuevo nivel recibiendo un mundo
		estado_juego++;
		lv1 = new nivel1(mundo1);
		//Le seteo la camara
		lv1->set_camara(ventana1);
		
		//Elimino el menu principal
		delete menu_principal;
		
		return;
	}
	//Si el estaod de juego tiende a 1
	if (estado_juego==1)

	{
		//Se eliminan los cuerpos del mundo e incrementamos el estado de juego
			lv1->eliminarCuerpos(*mundo1);
			estado_juego++;
			//Creo el nivel 2
			lv2 = new nivel2(mundo1);
			//Le seteo la camara
			lv2->set_camara(ventana1);
			//Elimino el nivel 1
			delete lv1;
		return;
	}
	
}


void administrador::actualizar_fisica()
{
	mundo1->Step(tiempoFrame, 8, 8);
	mundo1->ClearForces();

}