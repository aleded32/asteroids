#pragma once

//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class ship
{
public:

	sf::RectangleShape pShip;
	float x,y;

	ship();
	~ship();

	void drawShip(sf::RenderWindow& app);
	void shipMove(sf::Clock deltaClock);

private:

	float turnSpeed, angle, speed, MaxSpeed, accel, decel;
	float elasped;
	float dt;

};