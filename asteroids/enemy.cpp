#include "enemy.h"


enemy::enemy()
{
	this->asteroid.setSize(sf::Vector2f(70,70));
	this->asteroid.setFillColor(sf::Color::Green);
	this->Espeed = 3.0f;
	//this->asteroid.setOrigin(this->x, this->y);
}

enemy::~enemy()
{
	this->asteroid;
}


