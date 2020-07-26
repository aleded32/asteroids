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
#include "player.h"
#include "powerup.h"


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

			asteroids[i].asteroid.setPosition(asteroids[i].x, asteroids[i].y);

			app.draw(asteroids[i].asteroid);
		}
}

void powerupSpawn(std::vector<powerup>& powerups, powerup Powerup, int randSpawnX, int randSpawnY,int enemySpawnX[3], int enemySpawnY[2], sf::RenderWindow& app, sf::Clock& powerupClock)
{
	
	Powerup.powerupTime = powerupClock.getElapsedTime().asSeconds();

	Powerup.x = (float)enemySpawnX[randSpawnX];
	Powerup.y = (float)enemySpawnY[randSpawnY];

	if(powerups.size() == 0 && Powerup.powerupTime >= 4 && Powerup.powerupTime <=5)
	{
		powerups.push_back(powerup(Powerup));
	}
	else if(Powerup.powerupTime >= 10)
	{
		for(int i = 0; i < powerups.size(); i++)
		{
			powerups.erase(powerups.begin() + i);
		}
		powerupClock.restart();
	}

	for(int i = 0; i < powerups.size(); i++)
		{
			powerups[i].powerupImg.setPosition(powerups[i].x, powerups[i].y);

			app.draw(powerups[i].powerupImg);
		}

}

/*void sAsteroidSpawn(std::vector<smallAsteroid>& sAsteroids, std::vector<enemy>& asteroids, sf::RenderWindow& app, smallAsteroid sAsteroid, enemy *asteroid)
{

	sAsteroids.push_back(smallAsteroid(sAsteroid));

	for(size_t j = 0; j < asteroids.size(); j++)
	{
		for(size_t i = 0; i < sAsteroids.size(); i++)
		{
			sAsteroids[i].x = asteroid[j].x;
			sAsteroids[i].y = asteroid[j].y;

			app.draw(sAsteroids[i].asteroid);


			sAsteroids[i].asteroid.setPosition(sAsteroids[i].x, sAsteroids[i].y);
		}	
		
	}


}*/

void powerupActive(sf::Clock& rapidFireClock, collision *ptrCollision, rapidFire *ptrRapidFire, powerup& Powerup, bullet& Bullet)
{
	Powerup.powerupTime = rapidFireClock.getElapsedTime().asSeconds();
	Powerup.randPowerup = 0;

	if(Powerup.powerupTime <= 6 && Powerup.randPowerup == 0)
	{
		ptrRapidFire->changeSpawn(Bullet);
		std::cout << 1;
	}
	else if(Powerup.powerupTime > 6)
	{
		rapidFireClock.restart();
		ptrCollision->powerupActive = false;
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
					asteroids[i].y += asteroid->Espeed; 

			
			}
			else if(asteroids[i].randSpawnX == 1)
			{
		
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y += asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 2)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y +=  asteroid->Espeed; 
			
			}
		}
		else if(asteroids[i].randSpawnY == 1)
		{
			asteroid->randAngle = rand()%90;

			if(asteroids[i].randSpawnX == 0)
			{
			
					asteroids[i].x -= sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -=  asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 1)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -=  asteroid->Espeed; 
			
			}
			else if(asteroids[i].randSpawnX == 2)
			{
			
					asteroids[i].x += sin(asteroids[i].randAngle) * asteroid->Espeed;
					asteroids[i].y -=  asteroid->Espeed; 
			
			}

		}

		
	}
}

void powerupMove(std::vector<powerup>& powerups, powerup Powerup, int randSpawnY, int randSpawnX)
{
	int  i = 0;

	for(i = 0; i< powerups.size(); i++)
	{
		if(powerups[i].randSpawnY == 0)
		{
				Powerup.randAngle = rand()%90 + 50;

			if(powerups[i].randSpawnX == 0)
			{
			
					powerups[i].x -= sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y += Powerup.speed; 

			
			}
			else if(powerups[i].randSpawnX == 1)
			{
		
					powerups[i].x += sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y += Powerup.speed; 
			
			}
			else if(powerups[i].randSpawnX == 2)
			{
			
					powerups[i].x += sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y += Powerup.speed; 
			
			}
		}
		else if(powerups[i].randSpawnY == 1)
		{
			Powerup.randAngle = rand()%90;

			if(powerups[i].randSpawnX == 0)
			{
			
					powerups[i].x -= sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y -=  Powerup.speed; 
			
			}
			else if(powerups[i].randSpawnX == 1)
			{
			
					powerups[i].x += sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y -=  Powerup.speed; 
			
			}
			else if(powerups[i].randSpawnX == 2)
			{
			
					powerups[i].x += sin(powerups[i].randAngle) * Powerup.speed;
					powerups[i].y -= Powerup.speed; 
			
			}

		}

		
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
	sf::Clock shieldClock;
	sf::Clock powerupClock;
	sf::Clock rapidFireClock;
	app.setFramerateLimit(60);

	float bulletSpawn;
	

	std::vector<bullet> bullets;
	std::vector<enemy> asteroids;
	//std::vector<smallAsteroid> smallAsteroids;
	std::vector<powerup> powerups;

	//pointers to class
	ship *ptrShip;
	collision *ptrCollision;
	enemy *ptrEnemy;
	smallAsteroid *ptrSAsteroid;
	player *ptrPlayer;
	shield *ptrShield;
	rapidFire *ptrRapidFire;
	
	//classes
	ship Ship;
	collision Collision;
	bullet Bullet(Ship);
	enemy asteroid;
	smallAsteroid sAsteroid;
	player Player;
	powerup Powerup;
	shield Shield(Ship);
	rapidFire RapidFire;

	

	//point to class
	ptrShip = &Ship;
	ptrCollision = &Collision;
	ptrEnemy = &asteroid;
	ptrSAsteroid = &sAsteroid;
	ptrPlayer = &Player;
	ptrRapidFire = &RapidFire;
	ptrShield = &Shield;

	

	//enemySpawn;
	int enemySpawnX[3] = {10, 300, 599};
	int enemySpawnY[2] = {20, 580};

	


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
		Powerup.randSpawnX = rand()% 3;
		Powerup.randSpawnY = rand()% 2;
		
	if(ptrCollision->isGameOver != true)
	{

		bulletSpawn = bulletClock.getElapsedTime().asSeconds();

		ptrShip->shipMove(deltaClock, thrustClock);

		ptrCollision->ShipCollisionToWorld(ptrShip);

		ptrCollision->bulletsCollision(bullets);

		ptrCollision->asteroidCollision(asteroids, bullets, ptrShip, ptrEnemy->isDestroyed, ptrPlayer);
		
		ptrCollision->powerupCollision(powerups, ptrShip);
		
		//powerups
		
			
	
		//bullet
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

			Bullet.x = ptrShip->x;
			Bullet.y = ptrShip->y;
			Bullet.currentAngle = ptrShip->angle;

			if(bulletSpawn >= Bullet.bulletSpawnTime)
			{
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

		if(ptrCollision->powerupActive == true)
		{
			powerupActive(rapidFireClock, ptrCollision, ptrRapidFire, Powerup, Bullet);
		}
		
		
	}
		

		
		app.clear();


		
		ptrShip->drawShip(app);
		
		ptrPlayer->drawScore(app);
		
		for(size_t i = 0; i < bullets.size(); i++)
		{
		
			app.draw(bullets[i].Bullet);
		}	

		if(ptrCollision->isGameOver != true)
		{
			enemyMove(asteroids, ptrEnemy->randSpawnY, ptrEnemy, ptrEnemy->randSpawnX);
			enemySpawn(asteroids, asteroidSpawn, ptrEnemy->EnemySpawn, ptrEnemy->randSpawnX, ptrEnemy->randSpawnY ,enemySpawnX, enemySpawnY, asteroid, app);
			powerupMove(powerups, Powerup, ptrEnemy->randSpawnX, ptrEnemy->randSpawnY);
			powerupSpawn(powerups, Powerup,  ptrEnemy->randSpawnX, ptrEnemy->randSpawnY, enemySpawnX, enemySpawnY, app, powerupClock);
			
		}
			std::cout << ptrCollision->powerupActive << std::endl;	
			app.display();
	}
	
	
	return 0;

}