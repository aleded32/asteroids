#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class player
{

public:

	int lives;
	int score;
	player();
	~player();

	void drawScore(sf::RenderWindow& app);

private:

	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	
	



};