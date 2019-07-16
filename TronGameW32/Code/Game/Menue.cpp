#include "Menue.h"

Menue::Menue(sf::RenderWindow* _window)
{
	window = _window;
	ButtonPostion = sf::Vector2f((450 / 2), (450 / 2));
	ButtonSize = sf::Vector2f(0.5f, 0.5f);
}


Menue::~Menue()
{
}

void Menue::runMenue()
{
	endGame = false;
	createButtons();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousePos = sf::Mouse::getPosition(*window);
		playGame();
		EndGame();

	}
}

void Menue::EndGameMenue()
{
	endGame = true;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousePos = sf::Mouse::getPosition(*window);
		EndGame();
	}
}

void Menue::createButtons()
{
	startbutton.setPosition(ButtonPostion);
	startbutton.setScale(ButtonSize);
	startbutton.setOrigin(ButtonSize / 2.0f);

	start.loadFromFile("Start.png");
	startbutton.setTexture(start);

	Endbutton.setPosition(ButtonPostion.x, ButtonPostion.y + 200.0f);
	Endbutton.setScale(ButtonSize);
	Endbutton.setOrigin(ButtonSize / 2.0f);

	End.loadFromFile("Quit.png");
	Endbutton.setTexture(End);
	
}

void Menue::drawButtons()
{
	if (!endGame)
	{
		window->draw(startbutton);
	}
	window->draw(Endbutton);
}

void Menue::playGame()
{
	if (startbutton.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		game_state = GameState::PLAY;
	}
}

void Menue::EndGame()
{
	if (Endbutton.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		game_state = GameState::GAMEOVER;
		window->close();
	}

}