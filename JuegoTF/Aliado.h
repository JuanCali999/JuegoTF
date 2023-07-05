#pragma once
#include"Personajes.h"

class Aliado :public Personajes {
private:
public:
	Aliado(int width, int height) : Personajes(width, height) {
		x = rand() % 510 + 10;
		y = rand() % 800 + 15;
		dx = dy = rand() % 10 + 3;
	}
	~Aliado() {}

	void move(Graphics^ g) {
		if (x + width * 0.9 > g->VisibleClipBounds.Width || x < 0) {
			dx *= -1;
		}

		if (dx > 0) {
			idy = 2;
		}

		else idy = 1;
		x += dx;
		idx++;
		if (idx > 3)idx = 0;
	}
	void draw(Graphics^ g, Bitmap^ bmpAliado) {
		Rectangle sectionShow(idx * width, idy * height, width, height);
		Rectangle zoom(x, y, width * 0.9, height * 0.9);
		g->DrawImage(bmpAliado, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.9, height * 0.9);
	}
};