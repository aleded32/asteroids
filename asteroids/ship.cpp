#include "ship.h"

ship::ship()
{
	this->pShip.setSize(sf::Vector2f(10,20));
	this->pShip.setFillColor(sf::Color::White);
	this->x = 300;
	this->y = 300;
	this->angle =0;
	this->turnSpeed = 0.002;
	this->MaxSpeed = 0.15;
	this->speed =0;
	this->accel = 0.025;
	this ->decel = 6;
	this->pShip.setOrigin(this->pShip.getGlobalBounds().width/2, this->pShip.getGlobalBounds().height/2);

	
	this->pShip.setPosition(x,y);
	std::cout << dt << std::endl;
}

ship::~ship()
{
	this->pShip;
}


void ship::drawShip(sf::RenderWindow& app)
{
	app.draw(this->pShip);
}

void ship::shipMove(sf::Clock deltaClock)
{
	this->dt = deltaClock.restart().asSeconds();
	this->elasped = deltaClock.getElapsedTime().asSeconds();
	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		

		if(this->speed < this->MaxSpeed)
		{
			this->speed += this->accel;
		}
		else if(this->speed >= this->MaxSpeed)
		{
			this->speed = this->MaxSpeed;
		}
		
		
	}
	
	else
	{
		if(speed >0)
		{
		this->speed -= (this->decel * elasped);
		}
		else if(speed <=0)
		{
			this->speed = 0;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->angle += this->turnSpeed;
		
		
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->angle -= this->turnSpeed;
		
		
	}

	

	this->x += sin(angle) * speed;
	this->y -= cos(angle) * speed;

	this->pShip.setRotation(this->angle*180/3.14);
	this->pShip.setPosition(this->x,this->y);

}