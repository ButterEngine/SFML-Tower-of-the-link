#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class Bufftower
{
public:
	Bufftower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos);
	void Draw(sf::RenderWindow& window);
	void Update(float deltatime);
	float Buff();
	void upgrade();
	int getLevel() { return level; }

	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(aoe); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getAoe() { return this->aoe; }

private:
	sf::RectangleShape body;
	sf::RectangleShape aoe;
	Animation animation;
	unsigned int row;
	int level;
};