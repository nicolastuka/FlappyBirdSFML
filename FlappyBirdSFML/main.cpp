#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GamePlay.h"
#include "Menu.h"
#include "Puntajes.h"

using namespace sf;

int scene = 0;

int Puntajes::puntosActual;
int Puntajes::puntosMejores;

int main(int argc, char *argv[]){
	Puntajes::Inicializar();
	srand(time(NULL));
	RenderWindow *window = new RenderWindow(VideoMode(400, 500), "Flappy SFML Bird", sf::Style::Close | !sf::Style::Resize);
	Image img;
	img.loadFromFile("assets/images/icon.png");
	window->setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
	Menu *m = NULL;
	GamePlay *g = NULL;
	while(scene < 2){
		if (scene == 0){
			if (m == NULL){
				m = new Menu(window);
			}
			scene = m->Run();
			m = NULL;
			delete m;
		}else{
			if (g == NULL){
				g = new GamePlay(window);
			}
			scene = g->Run();
			g = NULL;
			delete g;
		}
	}
	return 0;
}
