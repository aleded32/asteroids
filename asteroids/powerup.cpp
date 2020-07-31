#include "powerup.h"


powerup::powerup()
{
	this->powerupImg.setFillColor(sf::Color::Red);
	this->radius = 20.0f;
	this->powerupImg.setRadius(radius);
	this->speed = 2.0f;
	this->isPowerupActive = false;
	
}

powerup::~powerup()
{
	this->powerupImg;
}




shield::shield(ship Ship)
{
	this->shieldImg.setFillColor(sf::Color(0,0,255,0));
	this->radius = 30.0f;
	this->shieldImg.setRadius(radius);
	this->shieldTime = 0;
	
}	

shield::~shield()
{
	this->shieldImg;
}


void shield::shieldActive(sf::RenderWindow& app, sf::Clock& shieldClock, ship *Ship)
{
	
		this->isActive = true;
		this->x = Ship->x - 30;
	    this->y = Ship->y - 30;

		this->shieldImg.setPosition(this->x, this->y);
	
	
}


rapidFire::rapidFire()
{
	this->newBulletSpawn = 0.2;
}

rapidFire::~rapidFire()
{

}

void rapidFire::changeSpawn(bullet& Bullet)
{
	Bullet.bulletSpawnTime = this->newBulletSpawn;
}