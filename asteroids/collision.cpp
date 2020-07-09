#include "collision.h"


void collision::ShipCollisionToWorld(ship *Ship)
{
	if(Ship->x + Ship->pShip.getGlobalBounds().width/2 <= 0)
	{
		Ship->x = 599 - Ship->pShip.getGlobalBounds().width/2;
		Ship->speed = Ship->speed;
	}
	else if(Ship->x - Ship->pShip.getGlobalBounds().width/2 >= 600)
	{
		Ship->x = 0 + Ship->pShip.getGlobalBounds().width/2;
		Ship->speed = Ship->speed;
	}
	else if(Ship->y + Ship->pShip.getGlobalBounds().height/2 <= 0)
	{
		Ship->y = 599 - Ship->pShip.getGlobalBounds().height/2;
		Ship->speed = Ship->speed;
	}
	else if(Ship->y - Ship->pShip.getGlobalBounds().height/2 >= 600)
	{
		Ship->y = 0 + Ship->pShip.getGlobalBounds().height/2;
		Ship->speed = Ship->speed;
	}
}

void collision::bulletsCollision(std::vector<bullet>& bullets)
{
	for(int i = 0; i < bullets.size(); i++)
	{
		if(bullets[i].y > 599 || bullets[i].y < 0 || bullets[i].x > 599 || bullets[i].x < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}


void collision::asteroidCollision(std::vector<enemy>& enemies, std::vector<bullet>& bullets, ship *Ship, bool isDestroyed, bool isGameOver)
{

	int collisionDistance;
	int collisionDistanceShip;

	
	for(int i = 0; i < enemies.size(); i++)
	{
		collisionDistanceShip = sqrt(abs(powf(enemies[i].x - Ship->x, 2.0f)) + abs(powf(enemies[i].y - Ship->y, 2.0f)));
		if(collisionDistanceShip < 60)
		{
				isGameOver = true;
				//std::cout << 1 << std::endl;
		}
		//std::cout << collisionDistanceShip << std::endl;

		for(int j = 0; j < bullets.size(); j++)
		{
			collisionDistance = sqrt(abs(powf(enemies[i].x - bullets[j].x, 2.0f)) + abs(powf(enemies[i].y - bullets[j].y, 2.0f)));
			


			if(enemies[i].y > 599 || enemies[i].y < 0 || enemies[i].x > 599 || enemies[i].x < 0)
			{
				enemies.erase(enemies.begin() + i);
			}
			else if(collisionDistance < 60)
			{
				//isDestroyed = true;
				enemies.erase(enemies.begin() + i);
				bullets.erase(bullets.begin() + j);
			}
			
				
		}
	}
}