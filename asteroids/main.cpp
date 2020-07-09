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


void enemySpawn(std::vector<enemy>& asteroids, sf::Clock& asteroidSpawn, float& asteroidSpawning, int randSpawnX, int randSpawnY,int enemySpawnX[3], int enemySpawnY[2], enemy asteroid, sf::RenderWindow& app)
{
	
	asteroidSpawning = asteroidSpawn.getElapsedTime().asSeconds();

		
	asteroid.x = (float)enemySpawnX[randSpawnX];
	asteroid.y = (float)enemySpawnY[randSpawnY];

	if(asteroidSpawning >= 1)
	{
		
		asteroids.push_back(enemy(asteroid));	
		
		asteroidSpawn.restart();
	}

	for(int i = 0; i < asteroids.size(); i++)
		{

			app.draw(asteroids[i].asteroid);
		}
}

void sAsteroidSpawn(std::vector<smallAsteroid>& sAsteroids, std::vector<enemy>& asteroids, sf::RenderWindow& app, smallAsteroid sAsteroid, enemy *asteroid)
{

	
		
	
		


	for(size_t i = 0; i < sAsteroids.size(); i++)
	{
		for(size_t j = 0; j < asteroids.size(); j++)
		{
		
			
			sAsteroids[i].x = asteroids[j].x;
			sAsteroids[i].y = asteroids[j].y;

			app.draw(sAsteroids[i].asteroid);
			sAsteroids[i].asteroid.setPosition(sAsteroids[i].x, sAsteroids[i].y);
			
		}
	}


}


void enemyMove(std::vector<enemy>& asteroids, int randSpawnY ,enemy *asteroid, int randSpawnX)
{
 
	int  i = 0;
	

	for(i = 0; i< asteroids.size(); i++)
	{
		if(asteroids[i].randSpawnY == 0)
		{
				asteroid->randAngle = rand()%90 + 50;

			if(asteroids[i].randSpawnX == 0)
			{
			
					asteroids[i].x -= sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y += cos(50) * asteroid->Espeed; 

			
			}
			else if(asteroids[i].randSpawnX == 1)
			{
		
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y += cos(50) * asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 2)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y += cos(50) * asteroid->Espeed; 
			
			}
		}
		else if(asteroids[i].randSpawnY == 1)
		{
			asteroid->randAngle = rand()%90;

			if(asteroids[i].randSpawnX == 0)
			{
			
					asteroids[i].x -= sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -= cos(50) * asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 1)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -= cos(50) * asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 2)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -= cos(50) * asteroid->Espeed; 
			
			}

		}

		asteroids[i].asteroid.setPosition(asteroids[i].x, asteroids[i].y);
	}
}


int main()
{
	srand(time(NULL));
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
	std::vector<smallAsteroid> smallAsteroids;

	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;
	enemy *ptrEnemy;
	smallAsteroid *ptrSAsteroid;
	
	//classes
	ship Ship;
	collision Collision;
	bullet Bullet(Ship);
	enemy asteroid;
	smallAsteroid sAsteroid;
	

	//point to class
	ptrShip = &Ship;
	ptrCollision = &Collision;
	ptrEnemy = &asteroid;
	ptrSAsteroid = &sAsteroid;

	//enemySpawn;
	int enemySpawnX[3] = {10, 300, 599};
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

		ptrEnemy->randSpawnX = rand()% 3;
		ptrEnemy->randSpawnY = rand()% 2;
	
		
	

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
	
		enemySpawn(asteroids, asteroidSpawn, ptrEnemy->EnemySpawn, ptrEnemy->randSpawnX, ptrEnemy->randSpawnY ,enemySpawnX, enemySpawnY, asteroid, app);
		enemyMove(asteroids, ptrEnemy->randSpawnY, ptrEnemy, ptrEnemy->randSpawnX);

		if(ptrEnemy->isDestroyed == true)
		{
			smallAsteroids.push_back(smallAsteroid(sAsteroid));
			ptrEnemy->isDestroyed = false;
		}
		sAsteroidSpawn(smallAsteroids, asteroids, app, sAsteroid, ptrEnemy);


		ptrCollision->asteroidCollision(asteroids, bullets, ptrShip, ptrEnemy->isDestroyed);
		
		std::cout << ptrEnemy->isDestroyed << std::endl;

		app.display();
	}

	
	return 0;

}