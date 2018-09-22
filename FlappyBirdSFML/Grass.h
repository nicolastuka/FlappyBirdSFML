#ifndef GRASS_H
#define GRASS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Grass {
private:
	Texture *tex;
	Sprite *sp;
	Vector2f posicion;
public:
	Grass(Vector2f pos);
	~Grass();
	void Update();
	void Draw(RenderWindow *w);
	Sprite GetSprite();
};

#endif

