#include "enemy.h"


enemy::enemy()
{
	this->asteroid.setSize(sf::Vector2f(70,70));
	this->asteroid.setFillColor(sf::Color::Green);
	this->Espeed = 1.0f;

}

enemy::~enemy()
{
	this->asteroid;
}





smallAsteroid::smallAsteroid()
{
	this->asteroid.setSize(sf::Vector2f(35,35));
	this->asteroid.setFillColor(sf::Color::Red);
	this->Espeed = 1.5f;

}

smallAsteroid::~smallAsteroid()
{
	this->asteroid;
}

