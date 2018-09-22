#ifndef TUBO_H
#define TUBO_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Tubo {
private:
	Texture *tex;
	Sprite *sp;
	Vector2f posicion;
public:
	Tubo(Vector2f pos, bool abajo);
	~Tubo();
	void Update(int MasY = 0, int MasX = 410);
	void Draw(RenderWindow *w);
	Sprite GetSprite();
};

#endif

