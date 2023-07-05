#pragma once
#include"Personajes.h"
#include"Hero.h"

class Enemy :public Personajes {
private:
	int type;
public:
	Enemy(int width, int height, int type) : Personajes(width, height) {
		this->type = type;
		x = rand() % 500 + 10;
		y = rand() % 780 + 15;
		dx = dy = rand() % 10 + 3;
	}
	~Enemy() {}

	void move(Graphics^ g, Hero* hero) {
		int i = rand() % 5;
		switch (type)
		{
		case 0:if ((x + width * 0.9) - 2 > g->VisibleClipBounds.Width || x < 2)dx *= -1;
			if (dx > 0) { idy = 2; }
			else { idy = 1; }
			x += dx;
			break;
		case 1:if ((y + height * 0.9) - 2 > g->VisibleClipBounds.Height || y < 2)dy *= -1;
			if (dy > 0) { idy = 0; }
			else { idy = 3; }
			y += dy;
			break;
		case 2:
			switch (i)
			{
			case 0:
				if (x > 0) {
					x -= dx;
					idy = 1;
				}
				break;

			case 1:
				if (x + width * 1.0 < g->VisibleClipBounds.Width) {
					x += dx;
					idy = 2;
				}
				break;

			case 2:
				if (y > 0) {
					y -= dy;
					idy = 3;
				}
				break;

			case 3:
				if (y + height * 1.0 < g->VisibleClipBounds.Height) {
					y += dy;
					idy = 0;
				}
				break;
			}
			break;

		case 3:
			if (x < 1 || x + width * 1.0 > g->VisibleClipBounds.Width) {
				dx *= -1;
				idy = 1;
			}
			if (y<1 || y + height * 1.0>g->VisibleClipBounds.Height) {
				dy *= -1;
				idy = 2;
			}
			x += dx;
			y += dy;
			break;
		case 4:
			if (x == hero->getX()) {
				x += 0;
			}
			else if (x > hero->getX()) {
				x -= dx;
				idy = 1;
			}
			else if (x < hero->getX()) {
				x += dx;
				idy = 2;
			}
			if (y == hero->getY()) {
				x += 0;
			}
			else if (y > hero->getY()) {
				y -= dy;
				idy = 3;
			}
			else if (y < hero->getY()) {
				y += dy;
				idy = 0;
			}
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void draw(Graphics^ g, Bitmap^ bmpEnemy) {
		Rectangle sectionShow(idx * width, idy * height, width, height);
		Rectangle zoom(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmpEnemy, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}
};
