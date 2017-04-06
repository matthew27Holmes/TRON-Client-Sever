#pragma once
#include "GameData.h"

class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u _imageCount,float _switchTime);
	~Animation();
	void Upadate(int row, float dealtaTime);
	sf::IntRect getUVRect() { return UVRect; }
	
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::IntRect UVRect;

	float totalTime;
	float switchTime;
};

