#pragma once

//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "collision.h"



class bullet
{
public:

	sf::RectangleShape Bullet;
	bool isfiring;
	

	bullet(ship Ship);
	~bullet();

	void draw(sf::RenderWindow& app,  std::vector<bullet> bullets);
	void move(ship Ship);


private:

	float x,y, Bspeed;

};