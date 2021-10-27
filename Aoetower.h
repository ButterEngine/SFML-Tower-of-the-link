#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class Aoetower
{
public:
	Aoetower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos);
	void Draw(sf::RenderWindow& window);
	int getDamage();
	void Update();

	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(aoe); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getAoe() { return this->aoe; }

private:
	sf::RectangleShape body;
	sf::RectangleShape aoe;
	float cooldown_attack;
	sf::Clock cooldown;
	Animation animation;
	unsigned int row;
	int damage;
	int level;
};

