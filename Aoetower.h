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
	void Update(sf::RenderWindow& window, float deltaTime);
	void Cooldown();
	int getLevel() { return level; }

	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(aoe); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getAoe() { return this->aoe; }
	void upgrade();

private:
	sf::RectangleShape body;
	sf::RectangleShape aoe;
	sf::RectangleShape attackSprite[8];
	float cooldown_attack;
	float cooldown_attack_temp;
	bool firstAttack = false;
	bool attack = false;
	sf::Clock cooldown;
	Animation animation;
	unsigned int row;
	int damage;
	int level;
};

