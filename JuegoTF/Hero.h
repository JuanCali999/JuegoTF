#pragma once
#include"Personajes.h"
#include"World.h"

class Hero :public Personajes {
private://atributos
	int hp;
	float coin;
	char direction;
public:
	Hero(int width, int height) :Personajes(width, height) {
		x = 30;
		y = 200;
		dx = dy = 10;
		hp = 4;
		coin = 0.0;
		direction = 'S';
	}
	~Hero() {}
	//GET
	int getVida() { return hp; }
	int getCoin() { return coin; }
	//Disminuir vida y monedas
	void decreaseHp() { hp--; }
	void decreaseCoin() { coin--; }
	void decreaceCoinN2() { coin -= 5; }
	void decreaseCoinAN2() { coin -= 0.5; }
	void addCoin() { coin++; }
	char getDirection() { return direction; }

	//funcion para el movimiento
	void move(Graphics^ g, char key, World* map) {
		switch (key)
		{
		case 'A':if (x > 0) {
			x -= dx;
			idy = 1;
			map->scrollIzquierda();
			direction = 'A';
		}break;
		case 'D':if (x + width * 1.0 < g->VisibleClipBounds.Width) {
			x += dx;
			idy = 2;
			map->scrollDerecha();
			direction = 'D';
		}break;
		case 'W':if (y > 0) {
			y -= dy;
			idy = 3;
			map->scrollArriba();
			direction = 'W';
		}break;
		case 'S':if (y + height * 1.0 < g->VisibleClipBounds.Height) {
			y += dy;
			idy = 0;
			map->scrollAbajo();
			direction = 'S';
		}break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}

	//fincion dibujar detective
	void draw(Graphics^ g, Bitmap^ bmpHero) {
		Rectangle sectionShow(idx * width, idy * height, width, height);
		Rectangle zoom(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmpHero, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

};