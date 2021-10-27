#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class HealingTower
{
public:
	HealingTower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos);
	void Draw(sf::RenderWindow& window);
	void Update();
	void Healing();

	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(aoe); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getAoe() { return this->aoe; }

private:
	sf::RectangleShape body;
	sf::RectangleShape aoe;
	float cooldown_healing;
	sf::Clock cooldown;
	Animation animation;
	unsigned int row;
	int heal;
	int level;
};

