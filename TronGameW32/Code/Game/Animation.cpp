#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u _imageCount, float _switchTime)
{
	imageCount = _imageCount;
	switchTime = _switchTime;

	totalTime = 0;
	currentImage.x = 0;

	UVRect.width = texture->getSize().x / float(imageCount.x);
	UVRect.height = texture->getSize().y / float(imageCount.y);
}


Animation::~Animation()
{
}

void Animation::Upadate(int row, float dealtaTime)
{
	currentImage.y = row;
	totalTime += dealtaTime;
	if (totalTime>=switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x>=imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	UVRect.left = currentImage.x * UVRect.width;
	UVRect.top = currentImage.y * UVRect.height;
}