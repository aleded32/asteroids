#include "ship.h"
#include "player.h"

ship::ship()
{
	this->pShip.setSize(sf::Vector2f(10,20));
	this->pShip.setFillColor(sf::Color::White);
	this->x = 300;
	this->y = 300;
	this->angle =0;
	this->turnSpeed = 0.1;
	this->MaxSpeed = 2.5;
	this->speed =0;
	this->accel = 0.25;
	this ->decel = 4000;
	this->isPressed = false;
	this->pShip.setOrigin(this->pShip.getGlobalBounds().width/2, this->pShip.getGlobalBounds().height/2);
	
	
	this->pShip.setPosition(x,y);
	
}

ship::~ship()
{
	this->pShip;
}


void ship::drawShip(sf::RenderWindow& app)
{
	app.draw(this->pShip);
}

void ship::shipMove(sf::Clock deltaClock,sf::Clock& thrustClock, player *ptrPlayer)
{
	this->dt = deltaClock.restart().asSeconds();
	this->elasped = deltaClock.getElapsedTime().asSeconds();
	this->thrustTime = thrustClock.getElapsedTime().asSeconds();
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(this->isPressed == true)
		{
			this->turnSpeed = 0.1;

			this->speed = this->MaxSpeed;
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
	

	if(speed <=0)
	{
		this->speed = 0;
		this->turnSpeed = 0.1;
		thrustClock.restart();
	
	}
	else if(this->speed >0 && this->isPressed == false )
	{
		this->speed -= (this->decel * this->elasped);
		this->turnSpeed = 0.1;
	}
		
	if(this->thrustTime >=6)
	{
		this->isPressed = false;
	}
	else if(this->thrustTime < 5)
	{
		this->isPressed = true;
	}

	this->x += sin(this->angle) * this->speed;
	this->y -= cos(this->angle) * this->speed;
	
	this->pShip.setRotation(this->angle*180/3.14);
	this->pShip.setPosition(this->x,this->y);

	
		if(this->thrustTime <= 0.18f)
		{
			ptrPlayer->maxSizeX = 100.0f;
			ptrPlayer->thrustBar.setSize(sf::Vector2f(ptrPlayer->maxSizeX, ptrPlayer->maxSizeY));
		}
		else if(this->thrustTime > 0.17 && this->thrustTime < 6) 
		{
			
			ptrPlayer->thrustBar.setSize(sf::Vector2f(ptrPlayer->maxSizeX -= 0.28, ptrPlayer->maxSizeY));
		}
		else if(this->thrustTime >= 6)
		{
			ptrPlayer->thrustBar.setSize(sf::Vector2f(0, ptrPlayer->maxSizeY));
		}
	

	
}

