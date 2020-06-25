//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "collision.h"


int main()
{
	sf::RenderWindow app(sf::VideoMode(600,600), "asteroids");
	sf::Event e;
	sf::Clock deltaClock;
	sf::Clock ThrustClock;


	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;

	//classes
	ship Ship;
	collision Collision;


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
		
		ptrShip->shipMove(deltaClock);

		ptrCollision->ShipCollisionToWorld(ptrShip);

		app.clear();

		ptrShip->drawShip(app);

		app.display();
	}

	getchar();
	return 0;

}