# pragma once


//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class enemy
{
public:

	sf::RectangleShape asteroid;
	float x,y, Espeed;
	float velocity;
	float EnemySpawn;
	float randAngle;
	int randSpawnX;
	int randSpawnY;
	bool isDestroyed;

	enemy();
	~enemy();


private:	

};


class smallAsteroid : public enemy
{
	public:

	/*sf::RectangleShape asteroid;
	float x,y, Espeed;
	float velocity;
	float EnemySpawn;
	float randAngle;
	int randSpawnX;
	int randSpawnY;
	*/
	smallAsteroid();
	~smallAsteroid();

};