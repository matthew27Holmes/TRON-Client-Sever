#pragma once
#include <future>
#include <string>
#include <vector>
#include <SFML\Network.hpp>
#include <Server/stdafx.h>
#include <memory>
#include <Game\GameData.h>
#include <Game/Action.h>


using TcpClient = sf::TcpSocket;
using TcpClientPtr = std::unique_ptr<TcpClient>;
using TcpClients = std::vector<TcpClientPtr>;
const sf::IpAddress SERVER_IP("127.0.0.1");
constexpr int SERVER_TCP_PORT(53000);

using namespace std;

class Client
{
public:
	Client();
	~Client();
	

	void reciveMSG();
	bool connect();
	void input();
	void LaunchThreads();
	
	
	int getEnemyDirection() {return EnemyDirection;}
	int getControler() { return controler; }
	bool getStartGame() { return StartGame; }
	bool getOtherPlayerCrashed() { return OtherPlayerCrashed;}

private:
	
	
	TcpClient socket;
	//int Id;
	int prevMessage;
	
	std::atomic<int> controler;
	std::atomic<bool> OtherPlayerCrashed;
	
	std::atomic<bool> StartGame;
	std::atomic<int> EnemyDirection;
};

