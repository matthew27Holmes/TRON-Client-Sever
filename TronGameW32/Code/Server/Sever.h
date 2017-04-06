#include <Server/stdafx.h>
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <SFML\Network.hpp>
#include <atomic>
#include"SeverClient.h"



constexpr int SERVER_TCP_PORT(53000);
constexpr int SERVER_UDP_PORT(53001);
using TcpClient = sf::TcpSocket;
using TcpClientPtr = std::unique_ptr<TcpClient>;
using TcpClients = std::vector<SeverClient>;

//bool bindServerPort(sf::TcpListener& listener);
//void listen(sf::TcpListener& tcp_listener, sf::SocketSelector& selector, TcpClients& tcp_clients);
//void connect(sf::TcpListener& tcp_listener, sf::SocketSelector& selector, TcpClients& tcp_clients);
//void receiveMsg(TcpClients& tcp_clients, sf::SocketSelector&selector);
//void runServer();

class Sever
{
public:
	Sever();
	~Sever()=default;

	bool bindServerPort();
	void connect();
	void receiveMsg();
	void clearStaleCli();
	void listen();
	void runServer();

private:
	sf::TcpListener tcp_listener;
	sf::SocketSelector selector;

	TcpClients  tcp_clinet;

	int clientMessage;
	std::string idToWatch;
	int Message;

	int NumClinets;

	int clientControls;

};

