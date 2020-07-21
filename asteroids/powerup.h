#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "bullets.h"

class powerup 
{
private:
	

public:

	float x,y;
	float randSpawnX, randSpawnY;
	sf::CircleShape powerupImg;
	float radius;
	float speed;
	float randAngle, powerupTime;

	powerup();
	~powerup();


};


class shield : public powerup
{
public:
	
	sf::CircleShape shieldImg;
	float shieldTime;
	bool isActive;

	shield(ship Ship);
	~shield();

	void shieldActive(sf::RenderWindow& app, sf::Clock& shieldClock);

private:

};


class rapidFire : public powerup
{
public:

	float newBulletSpawn;

	rapidFire();
	~rapidFire();

	void changeSpawn(bullet Bullet);

private:

	
	
};