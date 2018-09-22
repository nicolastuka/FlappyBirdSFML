#include "Ground.h"

Ground::Ground(Vector2f pos) {
	posicion = pos;
	tex = new Texture();
	tex->loadFromFile("assets/images/ground.png");
	sp = new Sprite(*tex);
	sp->setPosition(posicion);
}

Ground::~Ground(){
	delete sp;
	delete tex;
}

void Ground::Draw(RenderWindow *w){
	w->draw(*sp);
}

void Ground::Update(){
	sp->move(-5, 0);
	if (sp->getPosition().x < -400){
		sp->setPosition(0, posicion.y);
	}
}
