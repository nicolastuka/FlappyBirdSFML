#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Fondo.h"
#include "Bird.h"
#include "Ground.h"
#include "Grass.h"
#include "Tubo.h"
#include "Puntajes.h"
#include <iostream>

using namespace std;
using namespace sf;

class GamePlay {
private:
	RenderWindow *window;
	Fondo *background;
	Bird *bird;
	Ground *ground;
	Grass *grass;
	Tubo *tuboInferior;
	Tubo *tuboSuperior;
	Tubo *tuboInferiorSiguiente;
	Tubo *tuboSuperiorSiguiente;
	int collide[5];
	bool salida;
	Text *puntaje;
	Font *fuente;
	void Update();
	void Draw();
	void ProccessEvents();
	string ActualizarPuntaje();
public:
	GamePlay(RenderWindow *w);
	~GamePlay();
	int Run();
};

#endif

