#include "enemy.h"


enemy::enemy()
{
	this->asteroid.setSize(sf::Vector2f(70,70));
	this->asteroid.setFillColor(sf::Color::Green);
	this->Espeed = 5.0f;

}

enemy::~enemy()
{
	this->asteroid;
}


