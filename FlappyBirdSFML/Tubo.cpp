#include "Tubo.h"

Tubo::Tubo(Vector2f pos, bool abajo) {
	posicion = pos;
	tex = new Texture();
	(abajo) ? tex->loadFromFile("assets/images/tuboinferior.png"):tex->loadFromFile("assets/images/tubosuperior.png");
	sp = new Sprite(*tex);
	sp->setPosition(posicion);
}

Tubo::~Tubo(){
	delete sp;
	delete tex;
}

void Tubo::Draw(RenderWindow *w){
	w->draw(*sp);
}

void Tubo::Update(int MasY, int MasX){
	sp->move(-5, 0);
	if (sp->getPosition().x < -50){
		sp->setPosition(MasX, posicion.y + MasY);
	}
}

Sprite Tubo::GetSprite(){
	return *sp;
}

