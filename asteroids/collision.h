#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "bullets.h"
#include "enemy.h"
#include "player.h"
#include "powerup.h"
#include <vector>



class collision
{
private:
	
	int collisionDistance;
	int collisionDistanceShield;

public:

	int collidedCount;
	bool isGameOver;
	bool powerupActive;
	bool isEnemyDead;

	collision();
	~collision();

	void ShipCollisionToWorld(ship *Ship, std::vector<enemy>& enemies, player *Player);

	void bulletsCollision(std::vector<bullet>& bullets);

	void shieldCollision(std::vector<enemy>& enemies, shield *ptrShield);

	void asteroidCollision(std::vector<enemy>& enemies, std::vector<bullet>& bullets, ship *Ship, player *Player);

	void powerupCollision(std::vector<powerup>& powerups, ship *Ship);
	

};
