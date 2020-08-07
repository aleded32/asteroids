#include "player.h"

player::player()
{
	this->font.loadFromFile("chow.TTF");
	this->scoreText.setFont(font);
	this->scoreText.setCharacterSize(18);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(20,560);
	this->livesText.setFont(font);
	this->livesText.setCharacterSize(18);
	this->livesText.setFillColor(sf::Color::White);
	this->livesText.setPosition(450,560);
	this->thrustBarText.setFont(font);
	this->thrustBarText.setCharacterSize(18);
	this->thrustBarText.setFillColor(sf::Color::White);
	this->thrustBarText.setPosition(300, 40);
	this->lives = 3;
	this->score = 0;
	this->maxSizeX = 100;
	this->maxSizeY = 20;
	this->thrustBar.setFillColor(sf::Color::Yellow);
	this->thrustBar.setSize(sf::Vector2f(this->maxSizeX,this->maxSizeY));
	this->thrustBar.setPosition(490, 40);
}

player::~player()
{

}

void player::drawScore(sf::RenderWindow& app)
{
	
	this->livesText.setString("Lives: " + std::to_string(lives));
	this->scoreText.setString("score: " + std::to_string(score));
	this->thrustBarText.setString("Thrust Remaining: ");

	app.draw(this->scoreText);
	app.draw(this->livesText);
	app.draw(this->thrustBar);
	app.draw(this->thrustBarText);
}
