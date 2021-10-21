#include "Enemy.h"
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include "Platform.h"
#include <iostream>
#include "MapHandler.h"
#include <math.h>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	body.setSize(sf::Vector2f(120.0f, 120.0f));
	body.setPosition(3840, 6000);
	body.setFillColor(sf::Color::Red);
	body.setOrigin(body.getSize() / 2.0f);
}

void Enemy::Update(float deltatime, int map[64][64])
{
	int check = 0;
	sf::Vector2f movement(0.0f, 0.0f);
	if (map[Check_Enemy_Position().y - 1][Check_Enemy_Position().x] == 3 || map[Check_Enemy_Position().y - 1][Check_Enemy_Position().x] == 1)
	{
		this->isUp = true;
		this->isLeft = true;
		movement.y -= speed * deltatime;
		std::cout << "UP" << std::endl;
	}
	else if (map[Check_Enemy_Position().y][Check_Enemy_Position().x - 1] == 3 && this->isLeft)
	{
		std::cout << "Left" << std::endl;
		if (this->isUp || this->isLeft)
		{
			this->isUp = false;
			this->isLeft = true;
			movement.x -= speed * deltatime;
		}
	}
	else
	{
		std::cout << "Right" << std::endl;
		this->isUp = false;
		this->isLeft = false;
		movement.x += speed * deltatime;
	}
	body.move(movement);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Vector2i Enemy::Check_Enemy_Position()
{
	int map_enemy_x, map_enemy_y;
	map_enemy_x = round(this->getBody().getPosition().x / 120);
	map_enemy_y = round(this->getBody().getPosition().y / 120);
	sf::Vector2i enemy_pos;
	enemy_pos.x = map_enemy_x;
	enemy_pos.y = map_enemy_y;
	return enemy_pos;
}
