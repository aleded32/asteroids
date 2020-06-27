#include "bullets.h"


bullet::bullet(ship Ship)
{
	this->Bullet.setFillColor(sf::Color::Blue);
	this->Bullet.setSize(sf::Vector2f(2.0f,2.0f));
	this->Bspeed = 6.0f;
	this->x = Ship.x;
	this->y = Ship.y;
	
}

bullet::~bullet()
{

}


void bullet::draw(sf::RenderWindow& app, std::vector<bullet> bullets)
{
	
	for(int i = 0; i < bullets.size(); i++)
	{
		
		app.draw(bullets[i].Bullet);

		
	}

	
}
void bullet::move(ship Ship)
{
	this->x = Ship.x + Ship.pShip.getGlobalBounds().width/2;
	this->y = Ship.y;
	this->y -= this->Bspeed;
	//this->x -= this->Bspeed;
	
	this->Bullet.setPosition(this->x,this->y);
	
	
}
