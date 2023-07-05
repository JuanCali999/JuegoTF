#pragma once
#include "Personajes.h"

class Bullets
{
private:
	char direction;
	int x, y;
	int width, height;
	int dx, dy;
	int idx, idy;
	bool visible;

public:
	Bullets(int x, int y, int width, int height, char d) {
		this->x = x + 15;
		this->y = y + 16;
		this->width = width;
		this->height = height;
		dx = dy = 15;
		idx = idy = 0;
		direction = d;
		visible = true;
	}
	~Bullets() {}

	void move(Graphics^ g) {
		if (direction == 'S' && y + height * 0.2 <= g->VisibleClipBounds.Height) {
			y += dy;
			idy = 0;
			idx = 0;
		}
		if (direction == 'W' && y >= 0) {
			y -= dy;
			idy = 0;
			idx = 0;
		}
		if (direction == 'A' && x >= 0) {
			x -= dx;
			idy = 0;
			idx = 0;
		}
		if (direction == 'D' && x + width * 0.2 <= g->VisibleClipBounds.Width) {
			x += dx;
			idy = 0;
			idx = 0;
		}
	}

	void draw(Graphics^ g, Bitmap^ bmpBullet) {
		Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.2, height * 0.2);
		g->DrawImage(bmpBullet, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.2, height * 0.2);
	}
	int getX() { return x; }
	int getY() { return y; }
	int getxWidth() { return x + width * 0.2; }
	int getyHeight() { return y + height * 0.2; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};