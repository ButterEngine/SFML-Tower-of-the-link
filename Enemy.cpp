#include "Enemy.h"
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include "Platform.h"
#include <iostream>
#include "MapHandler.h"
#include <math.h>
#include"Global_variable.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float Health, int damage, bool special) :
	animation(texture, imageCount, switchTime)
{
	cooldown_attack = 0.0f;
	if (damage > 30)
	{
		damage = 30;
	}
	this->damage = damage;
	this->speed = speed;
	this->Health = Health;
	this->special = special;
	this->Maxhealth = Health;
	this->temp_wave = wave;
	row = 0;
	body.setSize(sf::Vector2f(120.0f, 120.0f));
	if (!special)
	{
		HealthBar.setSize(sf::Vector2f((this->Health / Maxhealth) * 120.0f, 20.0f));
	}
	else if (special)
	{
		this->Health /= 4;
		Maxhealth /= 4;
		HealthBar.setSize(sf::Vector2f((this->Health / Maxhealth) * 120.0f, 20.0f));
	}
	HealthBar.setFillColor(sf::Color::Green);
	if (wave == 1)
	{
		body.setFillColor(sf::Color::Red);
	}
	if (wave == 2)
	{
		body.setFillColor(sf::Color::Green);
	}
	if (wave == 3)
	{
		body.setFillColor(sf::Color::Magenta);
	}
	body.setPosition(3840, 6000);
	body.setOrigin(body.getSize() / 2.0f);
	HealthBar.setPosition(3840.0f, 5900.0f);
	HealthBar.setOrigin(HealthBar.getSize() / 2.0f);
}

void Enemy::Update(float deltatime, int map[64][64])
{
	if (Health < 0)
	{
		Health = 0;
	}
	cooldown_attack -= cooldown.restart().asSeconds();
	int check = 0;
	sf::Vector2f movement(0.0f, 0.0f);
	if (canMove && !special)
	{
		Maxhealth = 40 * temp_wave;
		if (map[Check_Enemy_Position().y - 1][Check_Enemy_Position().x] == 3 || map[Check_Enemy_Position().y - 1][Check_Enemy_Position().x] == 1)
		{
			this->isUp = true;
			this->isLeft = true;
			movement.y -= speed * deltatime;
		}
		else if (map[Check_Enemy_Position().y][Check_Enemy_Position().x - 1] == 3 && this->isLeft)
		{
			if (this->isUp || this->isLeft)
			{
				this->isUp = false;
				this->isLeft = true;
				movement.x -= speed * deltatime;
			}
		}
		else
		{
			this->isUp = false;
			this->isLeft = false;
			movement.x += speed * deltatime;
		}
		body.move(movement);
		HealthBar.move(movement);
		HealthBar.setSize(sf::Vector2f((Health / Maxhealth) * 120.0f, 20.0f));
	}
	else if (canMove && special)
	{
		Maxhealth = 10 * temp_wave;
		movement.y -= speed * deltatime;
		body.move(movement);
		HealthBar.move(movement);
		HealthBar.setSize(sf::Vector2f((Health / Maxhealth) * 120.0f, 20.0f));
	}
	if (special)
	{
		Maxhealth = 10 * temp_wave;
	}
	HealthBar.setSize(sf::Vector2f((Health / Maxhealth) * 120.0f, 20.0f));
	if ((Health / Maxhealth) * 100.0f > 70)
	{
		HealthBar.setFillColor(sf::Color::Green);
	}
	if ((Health / Maxhealth) * 100.0f <= 70)
	{
		HealthBar.setFillColor(sf::Color::Yellow);
	}
	if ((Health / Maxhealth) * 100.0f <= 40)
	{
		HealthBar.setFillColor(sf::Color::Red);
	}
}

void Enemy::Attack(int damage)
{
	if (cooldown_attack <= 0)
	{
		cooldown_attack = 1;
		playerHP -= damage;
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(HealthBar);
}

void Enemy::Hit(int damage)
{
	Health -= damage;
}

int Enemy::getHealth()
{
	return Health;
}

bool Enemy::Die()
{
	if (Health <= 0)
	{
		return true;
	}
	return false;
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
