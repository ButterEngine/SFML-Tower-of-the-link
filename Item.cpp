#include "Item.h"
#include "Global_variable.h"

Item::Item(int type, sf::Vector2f position)
{
	this->type = type;
	body.setPosition(position.x, position.y);
	body.setSize(sf::Vector2f(60.0f, 60.0f));
	body.setFillColor(sf::Color::Cyan);
	body.setTexture(&HealthPotion);
}

void Item::Draw()
{
	window.draw(body);
}

int Item::getType()
{
	return type;
}
