#include "Client.h"
#include <Game/Action.h>
#include <iostream>
#include <thread>

Client::Client() 
{
	StartGame = false;
	OtherPlayerCrashed = false;
	prevMessage = 0;
	
	//ClientMSG.join();

}

Client::~Client()
{
}


void Client::reciveMSG()
{
	while (true)
	{
		if (!connect())
		{
			return;
		}

		
			sf::Socket::Status status; // keep track of the socket status
			sf::Packet packet;
			int PacketInt;
			status = socket.receive(packet);
			packet >> PacketInt;
			EnemyDirection = PacketInt;
			if (status != sf::Socket::Disconnected)
			{

				if (status == sf::Socket::Done)
				{
					// Recvie message from sever
					//packet >> EnemyDirection;

					switch (EnemyDirection)
					{
					case 6:
						OtherPlayerCrashed = true;
					case 7:
						StartGame = true;//7 is sighn to start game
						break;
					case 8:
						controler = 1;//1 =keyboard arrows ,2= joystick ,3=wasd
						break;
					case 9:
						controler = 2;
						break;
					case 10:
						controler = 3;
						break;
					}
				}
			} 
	}

		//input();
	return;
}


bool Client::connect()
{

	auto status = socket.connect(SERVER_IP, SERVER_TCP_PORT);
	if (status != sf::Socket::Done)
	{
		return false;
	}
	socket.setBlocking(false);
	return true;

}

void Client::input()
{
	while (true)
	{
		
		auto& sender_ref = socket;

		//send message to sever
		sf::Packet packet;
		int message;


		switch (game_action)
		{
		case Action::UP:
			message = 1;
			break;
		case Action::RIGHT:
			message = 3;
			break;
		case Action::LEFT:
			message = 2;
			break;
		case Action::DOWN:
			message = 4;
			break;
		case Action::CRASHED:
			message = 6;
			break;
		default:
			message = 5;
			break;
		}
		if (prevMessage!=message)
		{
			prevMessage = message;
			packet << message;

			sender_ref.send(packet);
		}
	}
	

}

void Client::LaunchThreads()
{

	//ClientMSG.detach();
}



