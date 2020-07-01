//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "collision.h"
#include "bullets.h"
#include <vector>


int main()
{
	
	sf::RenderWindow app(sf::VideoMode(600,600), "asteroids");
	sf::Event e;
	sf::Clock deltaClock;
	sf::Clock bulletClock;
	sf::Clock thrustClock;
	app.setFramerateLimit(60);

	float bulletSpawn;

	std::vector<bullet> bullets;

	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;
	
	//classes
	ship Ship;
	collision Collision;
	bullet Bullet(Ship);

	//point to class
	ptrShip = &Ship;
	ptrCollision = &Collision;
	

	
	
	while (app.isOpen())
	{
		while (app.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				app.close();
			}
		}
		
		bulletSpawn = bulletClock.getElapsedTime().asSeconds();

		ptrShip->shipMove(deltaClock, thrustClock);

		ptrCollision->ShipCollisionToWorld(ptrShip);

		
		

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
			if(bulletSpawn >= 1)
			{
				Bullet.x = ptrShip->x;
				Bullet.y = ptrShip->y;
				Bullet.currentAngle = ptrShip->angle;
				bullets.push_back(bullet(Bullet));
				bulletClock.restart();
			}

			
		}
		
		for(size_t i = 0; i < bullets.size(); i++)
	{

			bullets[i].x += sin(bullets[i].currentAngle) * 10.0f;
			bullets[i].y -= cos(bullets[i].currentAngle) * 10.0f;

		if(bullets[i].y > 599 || bullets[i].y < 0 || bullets[i].x > 599 || bullets[i].x < 0)
		{
			//bullets.erase(bullets.begin() + i);
		}
		
		
		std::cout << bullets.size() << std::endl;

		//bullets[i].Bullet.setRotation(ptrShip->angle*180/3.14);
		bullets[i].Bullet.setPosition(bullets[i].x,bullets[i].y);
		
		
		
	}

		app.clear();

		ptrShip->drawShip(app);
		
		

	
	
	

	for(size_t i = 0; i < bullets.size(); i++)
	{
		
		app.draw(bullets[i].Bullet);

	}	
		

		app.display();
	}

	//getchar();
	return 0;

}