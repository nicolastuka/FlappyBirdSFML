#include "Bird.h"

Bird::Bird(Vector2f pos) {
	angle = -20;
	timeForce = 1.f;
	tex = new Texture();
	tex->loadFromFile("assets/images/bird.png");
	rectSprite = IntRect(0, 0, 35, 22);
	sp = new Sprite(*tex, rectSprite);
	sp->setPosition(pos);
	sp->setRotation(angle);
	isApplyForce = false;
}

Bird::~Bird(){
	delete tex;
	delete sp;
}

void Bird::Update(){
	if(isApplyForce){
		sp->move(0, gravity - impulse);
		if (timeForce > 0){
			isApplyForce = true;
			timeForce -= 0.05f;
		}else{
			isApplyForce = false;
		}
		angle = -20;
	}else{
		sp->move(0, gravity);
		angle++;
	}
	sp->setRotation(angle);
	if (tiempoAnimacion.getElapsedTime().asSeconds() > 0.25f){
		if(rectSprite.left == 35){
			rectSprite.left = 0;
		}else{
			rectSprite.left += 35;
		}
		sp->setTextureRect(rectSprite);
		tiempoAnimacion.restart();
	}
}

void Bird::Draw(RenderWindow *w){
	w->draw(*sp);
}

void Bird::ApplyForce(){
	isApplyForce = true;
	timeForce = 1.f;
}

int Bird::CollideWithGrass(Grass *g){
	FloatRect birdRect = sp->getGlobalBounds();
	FloatRect grassRect = g->GetSprite().getGlobalBounds();
	if(birdRect.intersects(grassRect)){
		return 1;
	}
	return 0;
}

int Bird::CollideWithTubo(Tubo *t){
	FloatRect birdRect = sp->getGlobalBounds();
	FloatRect tuboRect = t->GetSprite().getGlobalBounds();
	if(birdRect.intersects(tuboRect)){
		return 1;
	}
	return 0;
}

Vector2f Bird::getPosicion(){
	return sp->getPosition();
}
