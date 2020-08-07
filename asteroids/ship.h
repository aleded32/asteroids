#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.h"



class ship
{
public:

	sf::RectangleShape pShip;
	float x,y, speed;
	float turnSpeed, angle, MaxSpeed, accel, decel;

	ship();
	~ship();

	void drawShip(sf::RenderWindow& app);
	void shipMove(sf::Clock deltaClock, sf::Clock& thrustClock, player *ptrPlayer);

private:

	float elasped;
	float dt;
	bool isPressed;
	float thrustTime;
	

};