#include "Grass.h"

Grass::Grass(Vector2f pos) {
	posicion = pos;
	tex = new Texture();
	tex->loadFromFile("assets/images/grass.png");
	sp = new Sprite(*tex);
	sp->setPosition(posicion);
}

Grass::~Grass(){
	delete sp;
	delete tex;
}

void Grass::Update(){
	sp->move(-5, 0);
	if (sp->getPosition().x < -400){
		sp->setPosition(0, posicion.y);
	}
}

void Grass::Draw(RenderWindow *w){
	w->draw(*sp);
}

Sprite Grass::GetSprite(){
	return *sp;
}
