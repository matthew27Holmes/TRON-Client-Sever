#include "Sever.h"

Sever::Sever()
{
	clientControls = 8;
}

bool Sever::bindServerPort()
{
	if (tcp_listener.listen(SERVER_TCP_PORT) != sf::Socket::Done)
	{
		std::cout << "Could not bind server port, is another app using it?" << std::endl;
		std::cout << "Port: ";
		std::cout << SERVER_TCP_PORT;
		std::cout << std::endl;
		return false;
	}

	std::cout << "Server launched on port: " << SERVER_TCP_PORT << std::endl;;
	std::cout << "Searching for extraterrestrial life..." << std::endl;
	return true;
}

void Sever::connect()
{
	/*auto client_ptr = std::make_unique<sf::TcpSocket>();*/
		auto  client_ptr = new sf::TcpSocket;
		auto& client_ref = *client_ptr;

		if (tcp_listener.accept(client_ref) == sf::Socket::Done)
		{
			selector.add(client_ref);

			auto client = SeverClient(client_ptr);
			tcp_clinet.push_back(std::move(client));
			std::cout << "client connected" << std::to_string(client.getID()) << std::endl;

			sf::Packet Controlspacket;
			Controlspacket << clientControls;
			client_ref.send(Controlspacket);
			clientControls++;
			if (clientControls > 10)
			{
				clientControls = 8;
			}

		}
		if (tcp_clinet.size() >= 2)
		{
			sf::Packet Startpacket;
			Startpacket << 7;
			//client_ref.send(Startpacket);
			for (auto& client : tcp_clinet)// comapre to pointer to sender if!= then send message
			{
				client.getSocket().send(Startpacket);
			}
		}
	NumClinets = tcp_clinet.size();
	std::cout << "there are" << std::to_string(NumClinets) << " connected" << std::endl;
}

void  Sever::receiveMsg()
{	// loop through all tcp clients to find sender

	for (auto& sender : tcp_clinet)
	{
		sf::Packet RecivedPacket;
		
		auto& sender_ref = sender.getSocket();
		if (selector.isReady(sender_ref))
		{
			if (sender_ref.receive(RecivedPacket) == sf::Socket::Disconnected)
			{
				selector.remove(sender_ref);
				sender_ref.disconnect();
				std::cout << "Client (" << sender.getID()
					<< ") Disconnected" << std::endl;
			}
			else
			{
				RecivedPacket >> clientMessage;
				if (clientMessage != 5)
				{
					std::cout << sender.getID() << clientMessage << std::endl;
				}
				sf::Packet packet;

				Message = clientMessage;
				packet << Message;

				for (auto& client : tcp_clinet)// comapre to pointer to sender if!= then send message
				{
					if (sender == client)
						continue;
					client.getSocket().send(packet);
				}
			}
		}
		
	}
}
void Sever::clearStaleCli()
{
	tcp_clinet.erase(
		std::remove_if(tcp_clinet.begin(), tcp_clinet.end(), [](const SeverClient& client)
	{
		return(!client.isConnected());
	}), tcp_clinet.end());
}

void Sever::listen()
{
	while (true)
	{
		if (selector.wait())
		{
			// this is a new connection request
			if (selector.isReady(tcp_listener))
			{
				connect();
			}
			// this is a message being received
			else
			{
				receiveMsg();
				//clearStaleCli();
			}
		}
	}
}

void Sever:: runServer()
{
	std::cout << "Searching for life signs...";
	if (!bindServerPort())
	{
		return;
	}

	
	selector.add(tcp_listener);


	return listen();
}
