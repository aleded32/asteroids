//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"


int main()
{
	sf::RenderWindow app(sf::VideoMode(600,600), "asteroids");
	sf::Event e;
	sf::Clock deltaClock;

	//pointers to class
	ship *ptrShip;

	//classes
	ship Ship;

	//point to class
	ptrShip = &Ship;
	
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

		app.clear();

		ptrShip->drawShip(app);

		app.display();
	}

	getchar();
	return 0;

}