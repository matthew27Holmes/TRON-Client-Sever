#pragma once
#include "GameData.h"

class Menue
{
public:
	Menue(sf::RenderWindow* _window);
	~Menue();
	void runMenue();
	void EndGameMenue();

	void createButtons();
	void drawButtons();

	void playGame();
	void EndGame();
	//void onePlayer();

private:
	sf::Vector2f ButtonPostion;
	sf::Vector2f ButtonSize;

	sf::Sprite startbutton;
	sf::Texture start;

	sf::Sprite Endbutton;
	sf::Texture End;

	sf::Vector2i mousePos;
	sf::RenderWindow* window;

	bool endGame;
};

