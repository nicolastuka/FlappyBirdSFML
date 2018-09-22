#include "Fondo.h"

Fondo::Fondo(Vector2f pos) {
	tex = new Texture();
	tex->loadFromFile("assets/images/background.png");
	sp = new Sprite(*tex);
	sp->setPosition(pos);
}

Fondo::~Fondo(){
	delete sp;
	delete tex;
}

void Fondo::Draw(RenderWindow *w){
	w->draw(*sp);
}

