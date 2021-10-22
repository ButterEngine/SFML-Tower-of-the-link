#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Platform.h"

class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float Health);

	void Update(float deltatime, int map[64][64]);
	void Draw(sf::RenderWindow& window);
	void Hit();
	bool Die();
	sf::Vector2i Check_Enemy_Position();
	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape getBody() { return this->body; }
	sf::RectangleShape getHealthbar() { return this->HealthBar; }

private:
	sf::RectangleShape body;
	sf::RectangleShape HealthBar;
	Animation animation;
	unsigned int row;
	float speed;
	float Health;
	bool isLeft = false;
	bool isUp = false;
};
