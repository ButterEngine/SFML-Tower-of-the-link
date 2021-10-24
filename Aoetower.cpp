#include "Aoetower.h"

Aoetower::Aoetower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime)
{
	row = 0;
	body.setSize(sf::Vector2f(240.0f, 240.0f));
	body.setPosition(2520, 4920);
	body.setFillColor(sf::Color::Green);
	aoe.setSize(sf::Vector2f(720.0f, 720.0f));
	aoe.setPosition(2280, 4680);
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
