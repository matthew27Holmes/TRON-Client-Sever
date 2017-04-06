#pragma once
#include <Game\GameData.h>
#include<SFML/Window.hpp>
#include  <Game\Player.h>
#include "Client.h"

class InputManger
{
public:
	InputManger();
	~InputManger();
	int getSchema() { return conScheme; }
	void setSchema(int _controls);

	void setKeyboardCommands();
	void JotystickInp();
	void KeyboardInp(sf::Event& event);
private:
	int conScheme;	//control scheme being used 1 keyboard default ,2 gamepad,3 keyboard wasd
	sf::Keyboard::Key keyBoardKeys[4]; // array to hold different types of keyboard input

	int deadzone;

	Player* playerPt;
};

