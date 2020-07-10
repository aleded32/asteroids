#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



class ship
{
public:

	sf::RectangleShape pShip;
	float x,y, speed;
	float turnSpeed, angle, MaxSpeed, accel, decel;

	ship();
	~ship();

	void drawShip(sf::RenderWindow& app);
	void shipMove(sf::Clock deltaClock, sf::Clock& thrustClock);

private:

	float elasped;
	float dt;
	bool isPressed;
	float thrustTime;
	

};