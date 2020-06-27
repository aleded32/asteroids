//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "collision.h"
#include "bullets.h"



int main()
{
	
	sf::RenderWindow app(sf::VideoMode(600,600), "asteroids");
	sf::Event e;
	sf::Clock deltaClock;
	app.setFramerateLimit(60);

	std::vector<bullet> bullets;


	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;
	bullet *ptrBullet;

	//classes
	ship Ship;
	collision Collision;
	bullet Bullet(Ship);

	//point to class
	ptrShip = &Ship;
	ptrCollision = &Collision;
	ptrBullet = &Bullet;

	
	
	while (app.isOpen())
	{
		while (app.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				app.close();
			}
		}
		
		ptrShip->shipMove(deltaClock);

		ptrCollision->ShipCollisionToWorld(ptrShip);

			ptrBullet->move(Ship);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
			bullets.push_back(bullet(Bullet));
			
			std::cout << bullets.size() << std::endl;
		}

		
		

		app.clear();

		ptrShip->drawShip(app);
		ptrBullet->draw(app, bullets);
		

		app.display();
	}

	getchar();
	return 0;

}