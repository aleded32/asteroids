#include "collision.h"


collision::collision()
{
	this->isGameOver = false;
	this->powerupActive = false;
	this->isEnemyDead = false;
	this->collidedCount = 0;

}

collision::~collision()
{

}

void collision::ShipCollisionToWorld(ship *Ship, std::vector<enemy>& enemies, player *Player)
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

	for(size_t i = 0; i < enemies.size(); i++)
		{
			if(Ship->pShip.getGlobalBounds().intersects(enemies[i].asteroid.getGlobalBounds()))
			{
				Player->lives -= 1;
				Ship->x = 300;
				Ship->y = 300;
			}
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


void collision::asteroidCollision(std::vector<enemy>& enemies, std::vector<bullet>& bullets, ship *Ship, player *Player)
{
	
	
	
	for(size_t j = 0; j < bullets.size(); j++)
	{

		for(size_t i = 0; i < enemies.size();i++)
		{
			if(bullets[j].Bullet.getGlobalBounds().intersects(enemies[i].asteroid.getGlobalBounds()))
			{		
				
				std::cout << 1 << std::endl;
				isEnemyDead = true;
				
				enemies.erase(enemies.begin() + i);
				

				Player->score += 1;
			}
			else if(enemies[i].y > 599 || enemies[i].y < 0 || enemies[i].x > 599 || enemies[i].x < 0)
			{
				enemies.erase(enemies.begin() + i);
			}
			
				
			
			
			//std::cout << enemies[i] << std::endl;
		}
		
		if(isEnemyDead == true)
				{
					bullets.erase(bullets.begin() + j);
				}
		

	}

	isEnemyDead = false;

	if(Player->lives <= 0)
	{
		this->isGameOver = true;
		
	}
}

void collision::powerupCollision(std::vector<powerup>& powerups, ship *Ship)
{
	
	for(size_t i = 0; i < powerups.size(); i++)
	{
		
		if(powerups[i].x < 0 || powerups[i].y  < 0 || powerups[i].x > 599 || powerups[i].y > 599)
		{
			powerups.erase(powerups.begin() + i);
		}
		else if(Ship->pShip.getGlobalBounds().intersects(powerups[i].powerupImg.getGlobalBounds()))
		{
			
			powerups.erase(powerups.begin() + i);
			this->collidedCount = 1;
		}
		

		
	}

	if(this->collidedCount >= 1)
	{
		this->powerupActive = true;
	}
	else if(this->collidedCount <= 0)
	{
		this->powerupActive = false;
	}

	
}

void collision::shieldCollision(std::vector<enemy>& enemies, shield *ptrShield)
{
	if(ptrShield->isActive == true)
	{
		for(size_t i = 0; i < enemies.size(); i++)
		{
			//this->collisionDistanceShield = sqrt(powf(enemies[i].x - ptrShield->x, 2.0f) + powf(enemies[i].y - ptrShield->y, 2.0f));

			if(ptrShield->shieldImg.getGlobalBounds().intersects(enemies[i].asteroid.getGlobalBounds()))
			{
				enemies.erase(enemies.begin() + i);
			}
		}
	}
	
}

