#include "GamePlay.h"

GamePlay::GamePlay(RenderWindow *w) {
	Puntajes::puntosActual = 0;
	salida = false;
	collide[0] = 0;
	collide[1] = 0;
	collide[2] = 0;
	window = w;
	window->setFramerateLimit(60);
	Vector2f posicion;
	posicion.x = 0;
	posicion.y = 0;
	background = new Fondo(posicion);
	posicion.x = 50;
	bird = new Bird(posicion);
	posicion.x = 0;
	posicion.y = 500 - 28;
	ground = new Ground(posicion);
	posicion.y = 455;
	grass = new Grass(posicion);
	posicion.x = 410;
	posicion.y = 300;
	tuboInferior = new Tubo(posicion, true);
	posicion.y = -500;
	tuboSuperior = new Tubo(posicion, false);
	posicion.x = 660;
	posicion.y = 300;
	tuboInferiorSiguiente = new Tubo(posicion, true);
	posicion.y = -500;
	tuboSuperiorSiguiente = new Tubo(posicion, false);
	fuente = new Font();
	fuente->loadFromFile("assets/fonts/comicbd.ttf");
	puntaje = new Text();
	puntaje->setFont(*fuente);
	puntaje->setColor(Color(255,255,255));
	puntaje->setPosition(10, 10);
	puntaje->setString(ActualizarPuntaje());
}

GamePlay::~GamePlay(){
	delete background;
	delete bird;
	delete ground;
	delete grass;
	delete tuboInferior;
	delete tuboSuperior;
	delete puntaje;
	delete fuente;
	delete window;
}

int GamePlay::Run(){
	while(window->isOpen()){
		ProccessEvents();
		if (salida) return 2;
		Update();
		Draw();
		for(int i = 0; i < 5; i++){
			if (collide[i] == 1){
				return 0;
			}
		}
	}
	return 0;
}

void GamePlay::Update(){
	puntaje->setString(ActualizarPuntaje());
	bird->Update();
	ground->Update();
	grass->Update();
	int nuevaYtubo = rand()%200 - 100;
	tuboInferior->Update(nuevaYtubo);
	tuboSuperior->Update(nuevaYtubo);
	tuboInferiorSiguiente->Update(nuevaYtubo);
	tuboSuperiorSiguiente->Update(nuevaYtubo);
	collide[0] = bird->CollideWithGrass(grass);
	collide[1] = bird->CollideWithTubo(tuboInferior);
	collide[2] = bird->CollideWithTubo(tuboSuperior);
	collide[3] = bird->CollideWithTubo(tuboInferiorSiguiente);
	collide[4] = bird->CollideWithTubo(tuboSuperiorSiguiente);
}

void GamePlay::Draw(){
	window->clear(Color::Black);
	background->Draw(window);
	tuboSuperior->Draw(window);
	tuboInferior->Draw(window);
	tuboSuperiorSiguiente->Draw(window);
	tuboInferiorSiguiente->Draw(window);
	ground->Draw(window);
	grass->Draw(window);
	bird->Draw(window);
	window->draw(*puntaje);
	window->display();
}

void GamePlay::ProccessEvents(){
	Event e;
	while(window->pollEvent(e)){
		if(e.type == Event::Closed){
			window->close();
			salida = true;
		}
		if(Mouse::isButtonPressed(Mouse::Left))
		{
			bird->ApplyForce();
		}
	}
}

string GamePlay::ActualizarPuntaje(){
	if (tuboInferior->GetSprite().getPosition().x < -45 || tuboInferiorSiguiente->GetSprite().getPosition().x < -45){
		Puntajes::puntosActual++;
	}
	stringstream ss;
	ss<<Puntajes::puntosActual;
	return ss.str();
}
