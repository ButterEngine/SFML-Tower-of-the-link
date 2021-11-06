#include "HealingTower.h"
#include "Global_variable.h"

HealingTower::HealingTower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos) :
	animation(texture, imageCount, switchTime)
{
	cooldown_healing = 0.0f;
	heal = 3;
	level = 1;
	row = 0;
	body.setSize(sf::Vector2f(240.0f, 240.0f));
	body.setPosition(TowerPos.x, TowerPos.y);
	body.setFillColor(sf::Color::Green);
	aoe.setSize(sf::Vector2f(720.0f, 720.0f));
	aoe.setPosition(TowerPos.x - 240.0f, TowerPos.y - 240.0f);
	aoe.setFillColor(sf::Color(51, 255, 85, 120));

	////// Sprite
	body.setTexture(texture);
}

void HealingTower::Draw(sf::RenderWindow& window)
{
	window.draw(aoe);
	window.draw(body);
}

void HealingTower::Update()
{
	if (cooldown_healing <= 0.3)
	{
		aoe.setFillColor(sf::Color(51, 255, 85, 120));
	}
	cooldown_healing -= cooldown.restart().asSeconds();
}

void HealingTower::Healing()
{
	int temp_heal;
	if (cooldown_healing <= 0)
	{
		aoe.setFillColor(sf::Color(47, 229, 47, 120));
		cooldown_healing = 1;
		temp_heal = level * heal;
		if (playerHP < 100)
		{
			playerHP += temp_heal;
		}
		if (playerHP >= 100)
		{
			playerHP = 100;
		}
	}
}

void HealingTower::upgrade()
{
	level += 1;
}
