#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ground {
private:
	Texture *tex;
	Sprite *sp;
	Vector2f posicion;
public:
	Ground(Vector2f pos);
	~Ground();
	void Draw(RenderWindow *w);
	void Update();
};

#endif

