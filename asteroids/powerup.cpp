#include "powerup.h"


powerup::powerup()
{
	this->powerupImg.setFillColor(sf::Color::Red);
	this->radius = 20.0f;
	this->powerupImg.setRadius(radius);
	this->speed = 2.0f;
	
}

powerup::~powerup()
{
	this->powerupImg;
}




shield::shield(ship Ship)
{
	this->shieldImg.setFillColor(sf::Color(0,0,255,0));
	this->radius = 20.0f;
	this->x = Ship.x - Ship.pShip.getGlobalBounds().width/2;
	this->y = Ship.y - Ship.pShip.getGlobalBounds().height/2;

}

shield::~shield()
{
	this->shieldImg;
}


void shield::shieldActive(sf::RenderWindow& app, sf::Clock& shieldClock)
{
	if(this->isActive == true)
	{
		this->shieldTime = shieldClock.getElapsedTime().asSeconds();

		if(shieldTime <= 10)
		{
			this->shieldImg.setFillColor(sf::Color(0,0,255,100));
		}
		else if(shieldTime >10)
		{
			this->shieldImg.setFillColor(sf::Color(0,0,255,0));
			this->isActive = false;
		}
	}
	
	app.draw(this->shieldImg);
}


rapidFire::rapidFire()
{
	this->newBulletSpawn = 0.2;
}

rapidFire::~rapidFire()
{

}

void rapidFire::changeSpawn(bullet Bullet)
{
	Bullet.bulletSpawn = this->newBulletSpawn;
}