#include "Bufftower.h"
#include "Global_variable.h"

Bufftower::Bufftower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos) :
	animation(texture, imageCount, switchTime)
{
	level = 1;
	row = 0;
	body.setSize(sf::Vector2f(500.0f, 1000.0f));
	body.setPosition(TowerPos.x - 120, TowerPos.y - 740);
	aoe.setSize(sf::Vector2f(720.0f, 720.0f));
	aoe.setPosition(TowerPos.x - 240.0f, TowerPos.y - 240.0f);
	aoe.setFillColor(sf::Color(255, 154, 0, 120));
	//aoe.setOrigin(body.getSize() / 2.0f);

	////// Sprite
	body.setTexture(texture);
}

void Bufftower::Draw(sf::RenderWindow& window)
{
	window.draw(aoe);
	window.draw(body);
}

void Bufftower::Update(float deltatime)
{
	animation.Update(row, deltatime);
	body.setTextureRect(animation.uvRect);
}

float Bufftower::Buff()
{
	return level * 0.125;
}

void Bufftower::upgrade()
{
	level += 1;
	BuffUpgradeCost = level * 250;
	CurrentUpgradeCost = BuffUpgradeCost;
}

