#include "Aoetower.h"

Aoetower::Aoetower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos):
	animation(texture, imageCount, switchTime)
{
	cooldown_attack = 0.0f; 
	damage = 20;
	level = 1;
	row = 0;
	body.setSize(sf::Vector2f(240.0f, 240.0f));
	body.setPosition(TowerPos.x , TowerPos.y );
	body.setFillColor(sf::Color::Green);
	aoe.setSize(sf::Vector2f(720.0f, 720.0f));
	aoe.setPosition(TowerPos.x - 240.0f, TowerPos.y  - 240.0f);
	aoe.setFillColor(sf::Color(11,60,253,120));
	//body.setOrigin(body.getSize() / 2.0f);

	////// Sprite
	body.setTexture(texture);
}

void Aoetower::Draw(sf::RenderWindow& window)
{
	window.draw(aoe);
	window.draw(body);
}

int Aoetower::getDamage()
{
	if (cooldown_attack <= 0)
	{
		aoe.setFillColor(sf::Color(255, 60, 11, 120));
		damage = level * damage;
		return damage;
	}
	else
	{
		return 0;
	}
}

void Aoetower::Update()
{
	if (cooldown_attack <= 1.6)
	{
		aoe.setFillColor(sf::Color(11, 60, 253, 120));
	}
	cooldown_attack -= cooldown.restart().asSeconds();
}

void Aoetower::Cooldown()
{
	cooldown_attack = 2;
}
