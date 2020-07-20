#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "bullets.h"
#include "enemy.h"
#include "player.h"
#include <vector>



class collision
{
private:
	int collisionDistance;
	

public:

	bool isGameOver;

	void ShipCollisionToWorld(ship *Ship);

	void bulletsCollision(std::vector<bullet>& bullets);

	void asteroidCollision(std::vector<enemy>& enemies, std::vector<bullet>& bullets, ship *Ship, bool isDestroyed, player *Player);

};
