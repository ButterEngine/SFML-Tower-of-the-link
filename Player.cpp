#include "Player.h"
#include "Platform.h"
#include <iostream>
#include "MapHandler.h"
#include <math.h>
#include "Global_variable.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	//player

	body.setSize(sf::Vector2f(261.0f, 234.0f));
	body.setPosition(3840, 5000);
	body.setOrigin(body.getSize() / 1.4f);
	
	TowerMenu.setSize(sf::Vector2f(1000.0f, 2400.0f));
	TowerMenu.setPosition(6220,5600);
	TowerMenu.setOrigin(TowerMenu.getSize() / 1.4f);

	AttackUpgradeTowerMenu.setSize(sf::Vector2f(1000.0f, 2400.0f));
	AttackUpgradeTowerMenu.setPosition(6220, 5600);
	AttackUpgradeTowerMenu.setOrigin(TowerMenu.getSize() / 1.4f);

	HealingUpgradeTowerMenu.setSize(sf::Vector2f(1000.0f, 2400.0f));
	HealingUpgradeTowerMenu.setPosition(6220, 5600);
	HealingUpgradeTowerMenu.setOrigin(TowerMenu.getSize() / 1.4f);

	BuffUpgradeTowerMenu.setSize(sf::Vector2f(1000.0f, 2400.0f));
	BuffUpgradeTowerMenu.setPosition(6220, 5600);
	BuffUpgradeTowerMenu.setOrigin(TowerMenu.getSize() / 1.4f);

	Coinframe.setSize(sf::Vector2f(1000.0f, 200.0f));
	Coinframe.setPosition(6220, 5400);
	Coinframe.setOrigin(TowerMenu.getSize() / 1.4f);

	Scoreframe.setSize(sf::Vector2f(1000.0f, 200.0f));
	Scoreframe.setPosition(6220, 5200);
	Scoreframe.setOrigin(TowerMenu.getSize() / 1.4f);

	Healthbar.setSize(sf::Vector2f(playerHP / playerMaxHP * 2000.0f, 100.0f));
	Healthbar.setPosition(2760.0f, 3660.0f);
	Healthbar.setFillColor(sf::Color::Green);
	Healthbar.setOrigin(Healthbar.getSize() / 1.4f);

	Healthbarframe.setSize(sf::Vector2f(playerHP / playerMaxHP * 2040.0f, 140.0f));
	Healthbarframe.setPosition(2740.0f, 3640.0f);
	Healthbarframe.setFillColor(sf::Color::White);
	Healthbarframe.setOrigin(Healthbar.getSize() / 1.4f);
	Healthbarframe.setOutlineColor(sf::Color::Black);
	Healthbarframe.setOutlineThickness(20);

	MaxHealthbar.setSize(sf::Vector2f(playerHP / playerMaxHP * 2000.0f, 100.0f));
	MaxHealthbar.setPosition(2760.0f, 3660.0f);
	MaxHealthbar.setFillColor(sf::Color::Black);
	MaxHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	//statue
	statueHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	statueHealthbar.setPosition(2760.0f, 3860.0f);
	statueHealthbar.setFillColor(sf::Color::Green);
	statueHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	statueHealthbarframe.setSize(sf::Vector2f(statueHP / statueMaxHP * 2040.0f, 140.0f));
	statueHealthbarframe.setPosition(2740.0f, 3840.0f);
	statueHealthbarframe.setFillColor(sf::Color::White);
	statueHealthbarframe.setOrigin(Healthbar.getSize() / 1.4f);
	statueHealthbarframe.setOutlineColor(sf::Color::Black);
	statueHealthbarframe.setOutlineThickness(20);

	statueMaxHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	statueMaxHealthbar.setPosition(2760.0f, 3860.0f);
	statueMaxHealthbar.setFillColor(sf::Color::Black);
	statueMaxHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	body.setTexture(texture);
	HP.setFont(Gamefont);

	CoinBar.loadFromFile("assets/Menu/coinbar.png");
	Coinframe.setTexture(&CoinBar);

	ScoreBar.loadFromFile("assets/Menu/scorebar.png");
	Scoreframe.setTexture(&ScoreBar);

	TowerBuild.loadFromFile("assets/Menu/TowerBuild.png");
	TowerMenu.setTexture(&TowerBuild);

	AttackTowerUpgrade.loadFromFile("assets/Menu/AttackTowerUpgrade.png");
	AttackUpgradeTowerMenu.setTexture(&AttackTowerUpgrade);

	HealingTowerUpgrade.loadFromFile("assets/Menu/HealingTowerUpgrade.png");
	HealingUpgradeTowerMenu.setTexture(&HealingTowerUpgrade);

	BuffTowerUpgrade.loadFromFile("assets/Menu/BuffTowerUpgrade.png");
	BuffUpgradeTowerMenu.setTexture(&BuffTowerUpgrade);
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
	
	if (statueHP >= 0.0f)
	{
		statueHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	}
	if (statueHP > 15.0f)
	{
		statueHealthbar.setFillColor(sf::Color::Green);
	}
	if (statueHP <= 15.0f)
	{
		statueHealthbar.setFillColor(sf::Color::Yellow);
	}
	if (statueHP <= 9.0f)
	{
		statueHealthbar.setFillColor(sf::Color::Red);
	}


	if (playerHP >= 0.0f)
	{
		Healthbar.setSize(sf::Vector2f(playerHP / playerMaxHP * 2000.0f, 100.0f));
	}
	if (playerHP > 70.0f)
	{
		Healthbar.setFillColor(sf::Color::Green);
	}
	if (playerHP <= 70.0f)
	{
		Healthbar.setFillColor(sf::Color::Yellow);
	}
	if (playerHP <= 40.0f)
	{
		Healthbar.setFillColor(sf::Color::Red);
	}
	bool canwalk = true;
	sf::Vector2f movement(0.0f, 0.0f);
	if (canwalk)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (map[Check_Player_Position().y][Check_Player_Position().x - 1] != 1)
			{
				movement.x -= speed * deltatime;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
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
		Healthbar.move(movement);
		Healthbarframe.move(movement);
		MaxHealthbar.move(movement);

		statueHealthbar.move(movement);
		statueHealthbarframe.move(movement);
		statueMaxHealthbar.move(movement);

		TowerMenu.move(movement);
		AttackUpgradeTowerMenu.move(movement);
		HealingUpgradeTowerMenu.move(movement);
		BuffUpgradeTowerMenu.move(movement);

		Coinframe.move(movement);
		Scoreframe.move(movement);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(Healthbarframe);
	window.draw(MaxHealthbar);
	window.draw(Healthbar);

	window.draw(statueHealthbarframe);
	window.draw(statueMaxHealthbar);
	window.draw(statueHealthbar);

	window.draw(Coinframe);
	window.draw(Scoreframe);
}


bool Player::Die()
{
	if (playerHP <= 0.0f)
	{
		return true;
	}
	return false;
}

void Player::Draw_TowerMenu()
{
	window.draw(TowerMenu);
}

void Player::Draw_UpgradeTowerMenu()
{
	if (towerType == 1)
	{
		window.draw(AttackUpgradeTowerMenu);
	}
	if (towerType == 2)
	{
		window.draw(HealingUpgradeTowerMenu);
	}
	if (towerType == 3)
	{
		window.draw(BuffUpgradeTowerMenu);
	}
}

