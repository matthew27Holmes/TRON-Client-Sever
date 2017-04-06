#include "SeverClient.h"

SeverClient::SeverClient(sf::TcpSocket* sock)
	: socketPt(sock)
{

}

SeverClient::SeverClient(SeverClient&& rhs)
{
	this->id = rhs.id;
	this->socketPt = std::move(rhs.socketPt);
}

SeverClient& SeverClient::operator=(SeverClient&& rhs)
{
	this->id = rhs.id;
	this->socketPt = std::move(rhs.socketPt);
	return *this;
}
sf::TcpSocket& SeverClient::getSocket()
{
	return *socketPt;
}

bool SeverClient::isConnected() const
{
	return socketPt->getLocalPort() != 0;
}

unsigned int SeverClient::next_id = 0;

