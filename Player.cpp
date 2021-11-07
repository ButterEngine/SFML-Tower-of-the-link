#include "Player.h"
#include "Platform.h"
#include <iostream>
#include "MapHandler.h"
#include <math.h>
#include "Global_variable.h"
#include <string>

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
	Healthbar.setPosition(2660.0f, 3760.0f);
	Healthbar.setFillColor(sf::Color::Green);
	Healthbar.setOrigin(Healthbar.getSize() / 1.4f);

	Healthbarframe.setSize(sf::Vector2f(playerHP / playerMaxHP * 2040.0f, 140.0f));
	Healthbarframe.setPosition(2640.0f, 3740.0f);
	Healthbarframe.setFillColor(sf::Color::White);
	Healthbarframe.setOrigin(Healthbar.getSize() / 1.4f);
	Healthbarframe.setOutlineColor(sf::Color::Black);
	Healthbarframe.setOutlineThickness(20);

	MaxHealthbar.setSize(sf::Vector2f(playerHP / playerMaxHP * 2000.0f, 100.0f));
	MaxHealthbar.setPosition(2660.0f, 3760.0f);
	MaxHealthbar.setFillColor(sf::Color::Black);
	MaxHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	//statue
	statueHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	statueHealthbar.setPosition(2660.0f, 4060.0f);
	statueHealthbar.setFillColor(sf::Color::Blue);
	statueHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	statueHealthbarframe.setSize(sf::Vector2f(statueHP / statueMaxHP * 2040.0f, 140.0f));
	statueHealthbarframe.setPosition(2640.0f, 4040.0f);
	statueHealthbarframe.setFillColor(sf::Color::White);
	statueHealthbarframe.setOrigin(Healthbar.getSize() / 1.4f);
	statueHealthbarframe.setOutlineColor(sf::Color::Black);
	statueHealthbarframe.setOutlineThickness(20);

	statueMaxHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	statueMaxHealthbar.setPosition(2660.0f, 4060.0f);
	statueMaxHealthbar.setFillColor(sf::Color::Black);
	statueMaxHealthbar.setOrigin(Healthbar.getSize() / 1.4f);

	body.setTexture(texture);

	CoinBar.loadFromFile("assets/Menu/coinbar.png");
	Coinframe.setTexture(&CoinBar);

	ScoreBar.loadFromFile("assets/Menu/scorebar.png");
	Scoreframe.setTexture(&ScoreBar);

	TowerBuild.loadFromFile("assets/Menu/TowerBuild.png");
	TowerMenu.setTexture(&TowerBuild);

	AttackTowerUpgrade.loadFromFile("assets/Menu/AttackTowerUpgrade_Edited.png");
	AttackUpgradeTowerMenu.setTexture(&AttackTowerUpgrade);

	HealingTowerUpgrade.loadFromFile("assets/Menu/HealingTowerUpgrade_Edited.png");
	HealingUpgradeTowerMenu.setTexture(&HealingTowerUpgrade);

	BuffTowerUpgrade.loadFromFile("assets/Menu/BuffTowerUpgrade_Edited.png");
	BuffUpgradeTowerMenu.setTexture(&BuffTowerUpgrade);

	CoinText.setFont(Gamefont);
	ScoreText.setFont(Gamefont);
	AttackTowerBuildCostText.setFont(Gamefont);
	HealingTowerBuildCostText.setFont(Gamefont);
	BuffTowerBuildCostText.setFont(Gamefont);
	TowerLevelText.setFont(Gamefont);
	UpgradeCostText.setFont(Gamefont);
	CanUpgradeText.setFont(Gamefont);
	PlayerHPText.setFont(Gamefont);
	StatueHpText.setFont(Gamefont);
	WaveText.setFont(Gamefont);

	PlayerHPText.setString("PLAYER HP");
	PlayerHPText.setCharacterSize(160);
	PlayerHPText.setPosition(1200, 3460);
	PlayerHPText.setFillColor(sf::Color::White);
	PlayerHPText.setOutlineColor(sf::Color::Black);
	PlayerHPText.setOutlineThickness(10);

	StatueHpText.setString("STATUE HP");
	StatueHpText.setCharacterSize(160);
	StatueHpText.setPosition(1200, 3760);
	StatueHpText.setFillColor(sf::Color::White);
	StatueHpText.setOutlineColor(sf::Color::Black);
	StatueHpText.setOutlineThickness(10);

	string Scorestring = to_string(Score);
	ScoreText.setString(Scorestring);
	ScoreText.setCharacterSize(160);
	ScoreText.setPosition(5950.0f, 3460.0f);
	ScoreText.setFillColor(sf::Color::Cyan);

	string Coinstring = to_string(Coin);
	CoinText.setString(Coinstring);
	CoinText.setCharacterSize(160);
	CoinText.setPosition(5950.0f, 3660.0f);
	CoinText.setFillColor(sf::Color::Yellow);

	string AttackBuildString = to_string(AttackBuildCost);
	AttackTowerBuildCostText.setString(AttackBuildString);
	AttackTowerBuildCostText.setCharacterSize(120);
	AttackTowerBuildCostText.setPosition(6220.0f, 4665.0f);

	string HealingBuildString = to_string(HealingBuildCost);
	HealingTowerBuildCostText.setString(HealingBuildString);
	HealingTowerBuildCostText.setCharacterSize(120);
	HealingTowerBuildCostText.setPosition(6220.0f, 5115.0f);

	string BuffBuildString = to_string(BuffBuildCost);
	BuffTowerBuildCostText.setString(BuffBuildString);
	BuffTowerBuildCostText.setCharacterSize(120);
	BuffTowerBuildCostText.setPosition(6220.0f, 5605.0f);

	string TowerLevelstring = to_string(CurrentTowerLevel);
	TowerLevelText.setString(TowerLevelstring);
	TowerLevelText.setCharacterSize(160);
	TowerLevelText.setPosition(5900.0f, 5400.0f);
	TowerLevelText.setFillColor(sf::Color::Green);

	string UpgradeCostString = to_string(CurrentUpgradeCost);
	UpgradeCostText.setString(UpgradeCostString);
	UpgradeCostText.setCharacterSize(160);
	UpgradeCostText.setPosition(5900.0f, 5630.0f);

	CanUpgradeText.setCharacterSize(256);
	CanUpgradeText.setPosition(5560.0f, 5860.0f);
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
	AttackBuildCost = 100 * (arrayofAoetower.size() + 1);
	HealingBuildCost = 75 * (arrayofHealingtower.size() + 1);
	BuffBuildCost = 200 * (arrayofBufftower.size() + 1);

	if (AttackBuildCost > Coin)
	{
		AttackTowerBuildCostText.setFillColor(sf::Color::Red);
	}
	else
	{
		AttackTowerBuildCostText.setFillColor(sf::Color::Green);
	}

	string AttackBuildString = to_string(AttackBuildCost);
	AttackTowerBuildCostText.setString(AttackBuildString);

	if (HealingBuildCost > Coin)
	{
		HealingTowerBuildCostText.setFillColor(sf::Color::Red);
	}
	else
	{
		HealingTowerBuildCostText.setFillColor(sf::Color::Green);
	}

	string HealingBuildString = to_string(HealingBuildCost);
	HealingTowerBuildCostText.setString(HealingBuildString);

	if (BuffBuildCost > Coin)
	{
		BuffTowerBuildCostText.setFillColor(sf::Color::Red);
	}
	else
	{
		BuffTowerBuildCostText.setFillColor(sf::Color::Green);
	}

	string BuffBuildString = to_string(BuffBuildCost);
	BuffTowerBuildCostText.setString(BuffBuildString);

	string TowerLevelstring = to_string(CurrentTowerLevel);
	TowerLevelText.setString(TowerLevelstring);

	if (CurrentUpgradeCost > Coin)
	{
		UpgradeCostText.setFillColor(sf::Color::Red);
	}
	else
	{
		UpgradeCostText.setFillColor(sf::Color::Green);
	}

	string UpgradeCostString = to_string(CurrentUpgradeCost);
	UpgradeCostText.setString(UpgradeCostString);

	if (CurrentUpgradeCost > Coin)
	{
		CanUpgradeText.setString("NOT ENOUGH");
		CanUpgradeText.setFillColor(sf::Color::Red);
	}
	else
	{
		CanUpgradeText.setString("   UPGRADE");
		CanUpgradeText.setFillColor(sf::Color::Green);
	}
	if (CurrentTowerLevel == 5)
	{
		CanUpgradeText.setString("     MAX");
		CanUpgradeText.setFillColor(sf::Color::Magenta);
		UpgradeCostText.setString("MAX");
		UpgradeCostText.setFillColor(sf::Color::Magenta);
		TowerLevelText.setFillColor(sf::Color::Magenta);
	}
	else
	{
		TowerLevelText.setFillColor(sf::Color::Green);
	}

	string Scorestring = to_string(Score);
	ScoreText.setString(Scorestring);
	string Coinstring = to_string(Coin);
	CoinText.setString(Coinstring);

	if (statueHP >= 0.0f)
	{
		statueHealthbar.setSize(sf::Vector2f(statueHP / statueMaxHP * 2000.0f, 100.0f));
	}
	if (statueHP > 15.0f)
	{
		statueHealthbar.setFillColor(sf::Color::Blue);
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

		ScoreText.move(movement);
		CoinText.move(movement);

		AttackTowerBuildCostText.move(movement);
		HealingTowerBuildCostText.move(movement);
		BuffTowerBuildCostText.move(movement);

		TowerLevelText.move(movement);
		UpgradeCostText.move(movement);
		CanUpgradeText.move(movement);

		PlayerHPText.move(movement);
		StatueHpText.move(movement);
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

	window.draw(ScoreText);
	window.draw(CoinText);

	window.draw(PlayerHPText);
	window.draw(StatueHpText);
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
	window.draw(AttackTowerBuildCostText);
	window.draw(HealingTowerBuildCostText);
	window.draw(BuffTowerBuildCostText);
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
	window.draw(TowerLevelText);
	window.draw(UpgradeCostText);
	window.draw(CanUpgradeText);
}

