#include "playSpaceBoarders.h"



playSpaceBoarders::playSpaceBoarders()
{
}


playSpaceBoarders::~playSpaceBoarders()
{
}

bool playSpaceBoarders::isInPlaySpace(sf::Sprite Object, sf::Vector2f Windsize)
{
	sf::Vector2f ObjectPostion = Object.getPosition();
	sf::Vector2f ObjectSize(Object.getGlobalBounds().width, Object.getGlobalBounds().height);

	sf::Vector2f WindowSize = Windsize;

	float aXWidth = ObjectPostion.x + ObjectSize.x;
	float aYHeight = ObjectPostion.y + ObjectSize.y;

	if (aXWidth >= WindowSize.x || aYHeight >= WindowSize.y)
	{
		return true;
	}
	if (aXWidth <= 0 || aYHeight <=0)
	{
		return true;
	}
	return false;
}
