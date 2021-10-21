#include "Player.h"
#include "Platform.h"
#include <iostream>
#include "MapHandler.h"
#include <math.h>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	body.setSize(sf::Vector2f(261.0f, 234.0f));
	body.setPosition(3840, 5000);
	body.setOrigin(body.getSize() / 2.0f);

	////// Sprite
	body.setTexture(texture);

}

sf::Vector2i Player::Check_Player_Position()
{
	int map_player_x, map_player_y;
	map_player_x = round(this->getBody().getPosition().x / 120);
	map_player_y = round(this->getBody().getPosition().y / 120);
	sf::Vector2i player_pos;
	player_pos.x = map_player_x;
	player_pos.y = map_player_y;
	return player_pos;
}

void Player::Update(float deltatime, int map[64][64])
{
	bool canwalk = true;
	sf::Vector2f movement(0.0f, 0.0f);
	if (canwalk)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerTexture.loadFromFile("assets/texture/player_left.png");
			if (map[Check_Player_Position().y][Check_Player_Position().x - 1] != 1)
			{
				movement.x -= speed * deltatime;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerTexture.loadFromFile("assets/texture/player_right.png");
			if (map[Check_Player_Position().y][Check_Player_Position().x + 1] != 1)
			{
				movement.x += speed * deltatime;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (map[Check_Player_Position().y - 1][Check_Player_Position().x] != 1)
			{
				movement.y -= speed * deltatime;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (map[Check_Player_Position().y + 1][Check_Player_Position().x] != 1)
			{
				movement.y += speed * deltatime;
			}
		}
	}

	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		row = 2;
		canwalk = false;
	}


	animation.Update(row, deltatime);
	body.setTextureRect(animation.uvRect);
	if (canwalk)
	{
		body.move(movement);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
