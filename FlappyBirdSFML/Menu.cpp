#include "Menu.h"

Menu::Menu(RenderWindow *w) {
	salida = 0;
	window = w;
	texFondo = new Texture();
	texFondo->loadFromFile("assets/images/background.png");
	spFondo = new Sprite(*texFondo);
	fuente = new Font();
	fuente->loadFromFile("assets/fonts/comicbd.ttf");
	//Boton para jugar
	txtJugar = new Text();
	txtJugar->setFont(*fuente);
	txtJugar->setColor(Color::Black);
	txtJugar->setString("Toca la pantalla\n\tpara Jugar");
	txtJugar->setPosition(80, 50);
	//Puntaje Ultima Jugada
	txtPuntajeActual = new Text();
	txtPuntajeActual->setFont(*fuente);
	txtPuntajeActual->setColor(Color::Green);
	txtPuntajeActual->setString(CrearCadena("Score: ", Puntajes::puntosActual));
	txtPuntajeActual->setPosition(120, 250);
	//Mejor Puntaje
	txtMejorPuntaje = new Text();
	txtMejorPuntaje->setFont(*fuente);
	txtMejorPuntaje->setColor(Color::Red);
	txtMejorPuntaje->setString(CrearCadena("Best Score: ", EvaluarPuntaje()));
	txtMejorPuntaje->setPosition(100, 350);
}

Menu::~Menu(){
	delete spFondo;
	delete texFondo;
	delete txtJugar;
	delete txtMejorPuntaje;
	delete txtPuntajeActual;
	delete fuente;
	delete window;
}

void Menu::Draw(){
	window->draw(*spFondo);
	window->draw(*txtJugar);
	if (Puntajes::puntosMejores > 0)
		window->draw(*txtMejorPuntaje);
	if (Puntajes::puntosActual > 0)
		window->draw(*txtPuntajeActual);
}

void Menu::ProccessEvents(){
	Event e;
	while(window->pollEvent(e)){
		if(e.type == Event::Closed){
			window->close();
			salida = 2;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			salida = 1;
		}
	}
}

int Menu::Run(){
	while(window->isOpen()){
		ProccessEvents();
		window->clear(Color::White);
		Draw();
		window->display();
		if (salida > 0)
		{
			return salida;
		}
	}
	return 0;
}

string Menu::CrearCadena(string cadena, int puntaje){
	stringstream ss;
	ss<<cadena<<puntaje;
	return ss.str();
}

int Menu::EvaluarPuntaje(){
	if (Puntajes::puntosActual > Puntajes::puntosMejores)
	{
		Puntajes::puntosMejores = Puntajes::puntosActual;
	}
	return Puntajes::puntosMejores;
}
