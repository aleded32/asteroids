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
	for(size_t i = 0; i < bullets.size(); i++)
	{
		if(bullets[i].y > 599 || bullets[i].y < 0 || bullets[i].x > 599 || bullets[i].x < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}


void collision::asteroidCollision(std::vector<enemy>& enemies, std::vector<bullet>& bullets, ship *Ship, bool isDestroyed, player *Player)
{
	
	//this->isGameOver = false;
	
	for(size_t i = 0; i < enemies.size(); i++)
	{
		if(Ship->pShip.getGlobalBounds().intersects(enemies[i].asteroid.getGlobalBounds()))
			{
				Player->lives -= 1;
				Ship->x = 300;
				Ship->y = 300;
			}

		for(size_t j = 0; j < bullets.size(); j++)
		{
			collisionDistance = sqrt(powf(enemies[i].x - bullets[j].x, 2.0f) + powf(enemies[i].y - bullets[j].y, 2.0f));

			if(enemies[i].y > 599 || enemies[i].y < 0 || enemies[i].x > 599 || enemies[i].x < 0)
			{
			
			enemies.erase(enemies.begin() + i);
			
			}
			else if(collisionDistance < 60)
			{
				
				enemies.erase(enemies.begin() + i);
				bullets.erase(bullets.begin() + j);
				Player->score += 1;
				

			
			}
				
		}

	
	}

	if(Player->lives <= 0)
	{
		this->isGameOver = true;
		
	}
}