#pragma once
#include <SFML\Network.hpp>
#include <memory>
#include <chrono>
class SeverClient
{
public:

	SeverClient() = default;

	SeverClient(sf::TcpSocket*);
	SeverClient(SeverClient&&);

	sf::TcpSocket& getSocket();
	bool isConnected() const;

	SeverClient& operator=(SeverClient&&);
	bool operator==(const SeverClient& rhs) { return id == rhs.id; }

	int getID()  const { return id; }
private:

	
	static unsigned int next_id;
	int id = next_id++;
	std::unique_ptr<sf::TcpSocket> socketPt = nullptr;

};