#pragma once

//include directories
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class ship
{
public:

	sf::RectangleShape pShip;
	float x,y, speed;

	ship();
	~ship();

	void drawShip(sf::RenderWindow& app);
	void shipMove(sf::Clock deltaClock);

private:

	float turnSpeed, angle, MaxSpeed, accel, decel;
	float elasped;
	float dt;
	bool isPressed;

};