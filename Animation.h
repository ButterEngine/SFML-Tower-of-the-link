#pragma once
#include<SFML\Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture*, sf::Vector2u imageCount, float switchTime);

	void Update(int row, float deltatime,bool attack);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
	float TempswitchTime;
};

