#pragma once

//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"



class bullet
{
public:

	sf::RectangleShape Bullet;
	bool isfiring;
	float x,y, Bspeed;
	float velocity;
	float bulletSpawn;
	float bulletSpawnTime;
	float currentAngle;
	bullet(ship Ship);
	~bullet();



private:

	

};