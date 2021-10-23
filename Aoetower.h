#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class Aoetower
{
public:
	Aoetower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(aoe); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getAoe() { return this->aoe; }
private:
	sf::RectangleShape body;
	sf::RectangleShape aoe;
	float cooldown_attack;
	Animation animation;
	unsigned int row;
};

