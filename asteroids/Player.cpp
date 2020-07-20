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
	this->lives = 3;
	this->score = 0;
}

player::~player()
{

}

void player::drawScore(sf::RenderWindow& app)
{
	
	this->livesText.setString("Lives: " + std::to_string(lives));
	this->scoreText.setString("score: " + std::to_string(score));

	app.draw(this->scoreText);
	app.draw(this->livesText);
}
