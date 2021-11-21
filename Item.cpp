#include "Item.h"
#include "Global_variable.h"

Item::Item(int type, sf::Vector2f position, sf::Texture* texture)
{
	cooldown_item = 7.0f;
	this->type = type;
	body.setPosition(position.x, position.y);
	body.setSize(sf::Vector2f(120.0f, 120.0f));
	body.setTexture(texture);
}

void Item::Draw()
{
	window.draw(body);
}

bool Item::EraseItem()
{
	cooldown_item -= cooldown.restart().asSeconds();
	if (cooldown_item <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
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
}
