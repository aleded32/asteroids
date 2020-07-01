#include "bullets.h"


bullet::bullet(ship Ship)
{
	this->Bullet.setFillColor(sf::Color::Blue);
	this->Bullet.setSize(sf::Vector2f(20.0f,20.0f));
	this->Bspeed = 5.0f;
	this->x = Ship.x - Ship.pShip.getGlobalBounds().width/2;
	this->y = Ship.y;
	
}

bullet::~bullet()
{

}



	
	
	

