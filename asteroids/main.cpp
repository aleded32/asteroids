//include directories
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "collision.h"
#include "bullets.h"
#include "enemy.h"
#include "stdlib.h"
#include <vector>


void enemySpawn(std::vector<enemy>& asteroids, sf::Clock& asteroidSpawn, float& x, float& y, float& asteroidSpawning, int enemySpawnX[3], int enemySpawnY[2], enemy asteroid, sf::RenderWindow& app)
{
	srand(time(NULL));
	asteroidSpawning = asteroidSpawn.getElapsedTime().asSeconds();

	int randSpawnX = rand()% 6;
	int randSpawnY = rand()% 2;
	asteroid.x = (float)enemySpawnX[randSpawnX];
	asteroid.y = (float)enemySpawnY[randSpawnY]; 


	if(asteroidSpawning >= 2)
	{
		
		asteroids.push_back(enemy(asteroid));	
		
		asteroidSpawn.restart();
	}

	for(int i = 0; i < asteroids.size(); i++)
		{
			asteroids[i].asteroid.setPosition(asteroids[i].x, asteroids[i].y);

			app.draw(asteroids[i].asteroid);
		}
}



int main()
{
	
	sf::RenderWindow app(sf::VideoMode(600,600), "asteroids");
	sf::Event e;
	sf::Clock deltaClock;
	sf::Clock bulletClock;
	sf::Clock thrustClock;
	sf::Clock asteroidSpawn;
	app.setFramerateLimit(60);

	float bulletSpawn;

	std::vector<bullet> bullets;
	std::vector<enemy> asteroids;

	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;
	enemy *ptrEnemy;
	
	//classes
	ship Ship;
	collision Collision;
	bullet Bullet(Ship);
	enemy asteroid;
	

	//point to class
	ptrShip = &Ship;
	ptrCollision = &Collision;
	ptrEnemy = &asteroid;

	//enemySpawn;
	int enemySpawnX[6] = {10, 300, 599};
	int enemySpawnY[2] = {10, 590};
	
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
		
		//bullet
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(bulletSpawn >= 0.5)
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
			bullets[i].Bullet.setPosition(bullets[i].x,bullets[i].y);
		}

		ptrCollision->bulletsCollision(bullets);

		app.clear();

		ptrShip->drawShip(app);
		

		for(size_t i = 0; i < bullets.size(); i++)
		{
		
			app.draw(bullets[i].Bullet);

		}	
	
		enemySpawn(asteroids, asteroidSpawn, ptrEnemy->x, ptrEnemy->y, ptrEnemy->EnemySpawn, enemySpawnX, enemySpawnY, asteroid, app);

		

		std::cout << asteroids.size() << std::endl;

		app.display();
	}

	
	return 0;

}