#ifndef FONDO_H
#define FONDO_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Fondo {
private:
	Texture *tex;
	Sprite *sp;
public:
	Fondo(Vector2f pos);
	~Fondo();
	void Draw(RenderWindow *w);
};

#endif

