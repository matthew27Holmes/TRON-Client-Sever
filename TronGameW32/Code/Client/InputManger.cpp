#include "InputManger.h"



InputManger::InputManger()
{
	deadzone = 1;
	//event = new sf::Event; e
}
InputManger::~InputManger()
{
}

void InputManger::setKeyboardCommands()
{
	if (conScheme == 3)
	{
		keyBoardKeys[0] = { sf::Keyboard::Key::W };
		keyBoardKeys[1] = { sf::Keyboard::Key::A };
		keyBoardKeys[2] = { sf::Keyboard::Key::S };
		keyBoardKeys[3] = { sf::Keyboard::Key::D };
	}
	else
	{
		keyBoardKeys[0] = { sf::Keyboard::Key::Up };
		keyBoardKeys[1] = { sf::Keyboard::Key::Left };
		keyBoardKeys[2] = { sf::Keyboard::Key::Down };
		keyBoardKeys[3] = { sf::Keyboard::Key::Right };

	}
}
void InputManger::setSchema(int _controls)
{
	conScheme =_controls;
	if ((conScheme==2) && (!sf::Joystick::isConnected(0)))//1==ps4 0==xbox;
	{
		conScheme = 3;
	}
}


void InputManger::JotystickInp()
{
	deadzone = 60;
	//if (sf::Joystick::isButtonPressed(1, 1))
	//{
	//	if (playerPt->getHoldingPowerUp())
	//	{
	//		//playerPt->activatePowerUp(window);
	//	}
	//}
	float LSXAxies = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float LSYAxies = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	if (LSXAxies > deadzone)
	{
		if (game_action != Action::RIGHT)
		{
			game_action = Action::RIGHT;
		}
	}
	if (LSXAxies < -deadzone)
	{
		if (game_action != Action::LEFT)
		{
			game_action = Action::LEFT;
		}
	}
	if (LSYAxies > deadzone)
	{
		if (game_action != Action::DOWN)
		{
			game_action = Action::DOWN;
		}
	}
	if (LSYAxies < -deadzone)
	{
		if (game_action != Action::UP)
		{
			game_action = Action::UP;
		}
	}
	sf::Joystick::update();
}


void InputManger::KeyboardInp(sf::Event&event)
{
		if (game_action == Action::UP || game_action == Action::DOWN)
		{

			if (event.key.code==keyBoardKeys[3])
			{
				if (game_action != Action::RIGHT)
				{
					game_action = Action::RIGHT;
				}
			}
			if (event.key.code == keyBoardKeys[1])
			{

				if (game_action != Action::LEFT)
				{
					game_action = Action::LEFT;
				}
			}
		}
		if (game_action == Action::RIGHT || game_action == Action::LEFT)
		{

			if (event.key.code == keyBoardKeys[0])
			{
				if (game_action != Action::UP)
				{
					game_action = Action::UP;
				}
			}
			if (event.key.code == keyBoardKeys[2])
			{
				if (game_action != Action::DOWN)
				{
					game_action = Action::DOWN;
				}
			}
		}
}