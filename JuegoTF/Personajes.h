#pragma once
#include<iostream>
using namespace std;
using namespace System::Drawing;

class Personajes
{
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	bool visible;

public:
	Personajes(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
	}
	~Personajes() {}

	//get
	int getX() { return x; }
	int getY() { return y; }
	int getXWidth() { return x + width * 0.2; }
	int getYHeight() { return y + height * 0.2; }
	int getDxHero() { return dx; }
	int getDyHero() { return dy; }
	int getDxEnemy() { return dx; }
	int getDyEnemy() { return dy; }
	bool getVisible() { return visible; }
	//set
	void setVisible(bool v) { visible = v; }
	void setDxHero() { dx += 2; }
	void setDyHero() { dy += 2; }
	void decreaseDx() { dx = 3; }
	void decreaseDy() { dy = 3; }
	void setIncreacedxdyenemy() { dx = dy = rand() % 10 + 3; }
	void setInitalidxdyhero() { dx = dy = 10; }
	//movimiento
	virtual void move() {}
	//dibujar
	virtual void draw() {}
	//Recuadro para la colicion
	virtual Rectangle getRectangle() {
		return Rectangle();
	}
};