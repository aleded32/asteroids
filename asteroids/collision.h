#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ship.h"
#include "bullets.h"
#include <vector>



class collision
{
private:
	

public:

	void ShipCollisionToWorld(ship *Ship);

	void bulletsCollision(std::vector<bullet>& bullets);

};
