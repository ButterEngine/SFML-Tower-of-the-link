#include "Bufftower.h"

Bufftower::Bufftower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos) :
	animation(texture, imageCount, switchTime)
{
	level = 1;
	row = 0;
	body.setSize(sf::Vector2f(240.0f, 240.0f));
	body.setPosition(TowerPos.x, TowerPos.y);
	body.setFillColor(sf::Color::Green);
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

float Bufftower::Buff()
{
	return level * 0.2;
}

void Bufftower::upgrade()
{
	level += 1;
}

