#pragma once
#include "Personajes.h"

using namespace System::Drawing;

class World :public Personajes {
private:
public:
	World(int width, int height) : Personajes(width, height) {
		x = -20;
		y = -20;
	}
	~World() {}

	void draw(Graphics^ g, Bitmap^ bmpFondo) {
		Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.2, height * 1.2);
		g->DrawImage(bmpFondo, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void scrollDerecha() { x--; }
	void scrollIzquierda() { x++; }
	void scrollArriba() { y++; }
	void scrollAbajo() { y--; }
};