#pragma once
#include"Personajes.h"

class Currency :public Personajes {
private:
public:
	Currency(int width, int height) : Personajes(width, height) {
		x = rand() % 500 + 10;
		y = rand() % 780 + 15;
		dx = dy = 0;
	}
	~Currency() {}
	void move(Graphics^ g) {
		int i = rand() % 2;
		switch (i)
		{
		case 0: idy++;
			if (idy > 3)idy = 0;
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void draw(Graphics^ g, Bitmap^ bmpCurrency) {
		Rectangle sectionShow(idx * width, idy * height, width, height);
		Rectangle zoom(x, y, width * 0.5, height * 0.5);
		g->DrawImage(bmpCurrency, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.5, height * 0.5);
	}
};