#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class player
{

public:

	int lives;
	int score;
	float maxSizeX;
	float maxSizeY;
	sf::RectangleShape thrustBar;
	
	player();
	~player();

	void drawScore(sf::RenderWindow& app);

private:

	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	sf::Text thrustBarText;
	
	



};