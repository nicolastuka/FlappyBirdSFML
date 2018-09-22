#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grass.h"
#include "Tubo.h"

using namespace sf;

class Bird {
private:
	Texture *tex;
	Sprite *sp;
	Clock tiempoAnimacion;
	IntRect rectSprite;
	float fuerzaAplicacion;
	bool isApplyForce;
	float angle;
	float timeForce;
	const float gravity = 3.0f;
	const float impulse = 6.0f;
public:
	Bird(Vector2f pos);
	~Bird();
	void ApplyForce();
	void Draw(RenderWindow *w);
	void Update();
	int CollideWithGrass(Grass *g);
	int CollideWithTubo(Tubo *t);
	Vector2f getPosicion();
};

#endif

