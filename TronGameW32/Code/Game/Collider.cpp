#include "Collider.h"



Collider::Collider(sf::RectangleShape& body):
	body(body)
{

}


Collider::~Collider()
{
}
bool Collider::checkCollision(sf::Sprite ObjectA, sf::Sprite ObjectB)
{
	sf::Vector2f ObjectBPostion = ObjectB.getPosition();
	sf::Vector2f ObjectBSize(ObjectB.getGlobalBounds().width, ObjectB.getGlobalBounds().height);
	sf::Vector2f ObjectAPostion = ObjectA.getPosition();
	sf::Vector2f ObjectASize(ObjectA.getGlobalBounds().width, ObjectA.getGlobalBounds().height);

	float aXWidth = ObjectAPostion.x + ObjectASize.x;
	float aYHeight = ObjectAPostion.y + ObjectASize.y;

	float bXWidth = ObjectBPostion.x + ObjectBSize.x;
	float bYHeight = ObjectBPostion.y + ObjectBSize.y;

	if ((aXWidth >= ObjectBPostion.x) && (ObjectAPostion.x <= bXWidth) && (aYHeight >= ObjectBPostion.y) && (ObjectAPostion.y <= bYHeight))
	{
		return true;
	}
	return false;
}

bool Collider::CheckGridCollisions(sf::RectangleShape _GridTile, sf::Sprite _Bike)
{
	///*sf::Vector2f TilePostion = _GridTile.getPosition();
	//sf::Vector2f TileSize(_GridTile.getSize());*/
	//sf::Vector2f BikePostion = _Bike.getPosition();
	//sf::Vector2f BikeSize(_Bike.getGlobalBounds().width, _Bike.getGlobalBounds().height);

	//float aXWidth = BikePostion.x + BikeSize.x;
	//float aYHeight = BikePostion.y + BikeSize.y;

	///*float bXWidth = TilePostion.x + TileSize.x;
	//float bYHeight = TilePostion.y + TileSize.y;*/
	//sf::Vector2f boundingBox(aXWidth, aYHeight);


	////if (_GridTile.getGlobalBounds.contains(_Bike.getGlobalBounds())/*(aXWidth >= TilePostion.x) && (BikePostion.x <= bXWidth) && (aYHeight >= TilePostion.y) && (BikePostion.y <= bYHeight)*/)
	////{
	////	return true;
	////}
	//return false;
	sf::Vector2f TilePostion = _GridTile.getPosition();
	sf::Vector2f TileSize(_GridTile.getSize());
	sf::Vector2f BikePostion = _Bike.getPosition();
	sf::Vector2f BikeSize(_Bike.getGlobalBounds().width, _Bike.getGlobalBounds().height);

	float aXWidth = BikePostion.x + BikeSize.x;
	float aYHeight = BikePostion.y + BikeSize.y;

	float bXWidth = TilePostion.x + TileSize.x;
	float bYHeight = TilePostion.y + TileSize.y;


	if ((aXWidth >= TilePostion.x) && (BikePostion.x <= bXWidth) && (aYHeight >= TilePostion.y) && (BikePostion.y <= bYHeight))
	{
		return true;
	}
	return false;
}

