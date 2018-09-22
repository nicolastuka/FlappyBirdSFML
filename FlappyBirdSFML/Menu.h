#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Puntajes.h"

using namespace std;
using namespace sf;

class Menu {
private:
	Texture *texFondo;
	Sprite *spFondo;
	Text *txtPuntajeActual;
	Text *txtMejorPuntaje;
	Text *txtJugar;
	Font *fuente;
	RenderWindow *window;
	int salida;
	void Draw();
	void ProccessEvents();
	string CrearCadena(string cadena, int puntaje);
	int EvaluarPuntaje();
public:
	Menu(RenderWindow *w);
	~Menu();
	int Run();
};

#endif

