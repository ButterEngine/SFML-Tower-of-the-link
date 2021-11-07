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

void Item::Useitem(int type)
{
	if (type == 1)
	{
		playerHP += 20;
		if (playerHP > 100)
		{
			playerHP = 100;
		}
	}
	if (type == 2)
	{
		statueHP += 2;
		if (statueHP > 30)
		{
			statueHP = 30;
		}
	}
	if (type == 3)
	{
		Coin += wave * 50;
	}
	if (type == 4)
	{

	}
}
