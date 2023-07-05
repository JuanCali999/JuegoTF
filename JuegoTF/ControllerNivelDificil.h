#pragma once
#include "Hero.h"
#include "Enemy.h"
#include "World.h"
#include "Currency.h"
#include "Aliado.h"
#include "FrmMain.h"
#include "Bullets.h"
#include <vector>
using namespace std;

class ControllerNivelDificil {
private:
	int amount;
	World* map;
	Hero* hero;
	vector<Aliado*>ally;
	vector<Enemy*>enemy;
	vector<Currency*>money;
	vector<Bullets*>bullet;
public:
	ControllerNivelDificil(Bitmap^ bmpMap, Bitmap^ bmpHero, Bitmap^ bmpEnemy) {
		map = new World(bmpMap->Width, bmpMap->Height);
		hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 0));
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 1));
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 2));
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 3));
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 4));
		enemy.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 4));
		amount = 30;
	}
	~ControllerNivelDificil() {}

	void addBullet(Bullets* b) {
		bullet.push_back(b);
	}
	void addMoney(Bitmap^ bmpMoney) {
		money.push_back(new Currency(bmpMoney->Width / 4, bmpMoney->Height / 4));
	}
	void addAlly(Bitmap^ bmpAlly) {
		ally.push_back(new Aliado(bmpAlly->Width / 3, bmpAlly->Height / 4));
	}
	void draw(Graphics^ g, Bitmap^ bmpMap, Bitmap^ bmpHero, Bitmap^ bmpEnemy, Bitmap^ bmpMoney, Bitmap^ bmpAlly, Bitmap^ bmpBullet) {

		map->draw(g, bmpMap);
		hero->draw(g, bmpHero);
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->draw(g, bmpEnemy);
		}
		for (int i = 0; i < money.size(); i++)
		{
			money[i]->draw(g, bmpMoney);
		}
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->draw(g, bmpAlly);
		}
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i]->draw(g, bmpBullet);
		}
	}

	void moveEnemyMoney(Graphics^ g) {
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->move(g, hero);
		}
		for (int i = 0; i < money.size(); i++)
		{
			money[i]->move(g);
		}
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->move(g);
		}
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i]->move(g);
		}
	}

	void collision(Graphics^ g) {
		//verifica
		for (int i = 0; i < enemy.size(); i++)
		{
			if (hero->getRectangle().IntersectsWith(enemy[i]->getRectangle())) {
				enemy[i]->setVisible(false);
				hero->decreaseHp();
				hero->decreaseCoin();
			}
		}
		//borra
		for (int i = 0; i < enemy.size(); i++)
		{
			if (!enemy[i]->getVisible()) {
				enemy.erase(enemy.begin() + i);
			}
		}
		//verifica
		for (int i = 0; i < money.size(); i++)
		{
			if (hero->getRectangle().IntersectsWith(money[i]->getRectangle())) {
				money[i]->setVisible(false);
			}
		}
		//borra
		for (int i = 0; i < money.size(); i++)
		{
			if (!money[i]->getVisible()) {
				money.erase(money.begin() + i);
				hero->addCoin();
			}
		}
		//verifica
		for (int i = 0; i < enemy.size(); i++)
		{
			for (int j = 0; j < ally.size(); j++)
			{
				if (enemy[i]->getRectangle().IntersectsWith(ally[j]->getRectangle()) || hero->getRectangle().IntersectsWith(ally[j]->getRectangle())) {
					ally[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < ally.size(); i++)//verifica colicion de hero y aliado
		{
			if (hero->getRectangle().IntersectsWith(ally[i]->getRectangle())) {
				ally[i]->setVisible(false);
			}
		}
		//borra
		for (int i = 0; i < ally.size(); i++)
		{
			if (!ally[i]->getVisible()) {
				ally.erase(ally.begin() + i);
				hero->addCoin();
			}
		}
		//verifica colicion de bullet con borde
		for (int i = 0; i < bullet.size(); i++)
		{
			if (bullet[i]->getX() <= 0 || bullet[i]->getxWidth() >= g->VisibleClipBounds.Width ||
				bullet[i]->getY() <= 0 || bullet[i]->getyHeight() >= g->VisibleClipBounds.Height) {
				bullet[i]->setVisible(false);
			}
		}
		//verifica colision bullet vs enemy
		for (int i = 0; i < enemy.size(); i++)
		{
			for (int j = 0; j < bullet.size(); j++)
			{
				if (enemy[i]->getRectangle().IntersectsWith(bullet[j]->getRectangle())) {
					enemy[i]->setVisible(false);
					bullet[j]->setVisible(false);
				}
			}
		}
		//borrar
		for (int i = 0; i < bullet.size(); i++)
		{
			if (!bullet[i]->getVisible()) {
				bullet.erase(bullet.begin() + i);
			}
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			if (!enemy[i]->getVisible()) {
				enemy.erase(enemy.begin() + i);
			}
		}
	}
	void decreasedxEnemy() {
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->decreaseDx();
		}
	}
	void decreasedyEnemy() {
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->decreaseDy();
		}
	}
	void setIncreacedxdyenemy() {
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->setIncreacedxdyenemy();
		}
	}
	void setAmountN2() { amount += 10; }
	void setAmountN2I() { amount = 30; }
	int getAmountN2() {
		return amount;
	}
	//int getamountCoin(){return }
	Hero* getHero() { return hero; }
	World* getMap() { return map; }
	vector<Enemy*> getenemy() { return enemy; }
	int getsizeMoney() { return money.size(); }
	int getContMoney() { return hero->getCoin(); }
	int getsizeAlly() { return ally.size(); }
};