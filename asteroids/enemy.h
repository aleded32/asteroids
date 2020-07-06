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
	float currentAngle;

	enemy();
	~enemy();


private:	

};