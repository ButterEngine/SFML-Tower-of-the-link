#include "Aoetower.h"

Aoetower::Aoetower(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f TowerPos):
	animation(texture, imageCount, switchTime)
{
	firstAttack = false;
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
	for (int i = 0; i < 8; i++)
	{
		attackSprite[i].setSize(sf::Vector2f(200.0f, 240.0f));
		if (i == 0)
		{
			attackSprite[i].setPosition(TowerPos.x + 260.0f, TowerPos.y - 240.0f);
		}
		if (i == 1)
		{
			attackSprite[i].setPosition(TowerPos.x + 20.0f, TowerPos.y - 240.0f);
		}
		if (i == 2)
		{
			attackSprite[i].setPosition(TowerPos.x - 220.0f, TowerPos.y - 240.0f);
		}
		if (i == 3)
		{
			attackSprite[i].setPosition(TowerPos.x + 260.0f, TowerPos.y);
		}
		if (i == 4)
		{
			attackSprite[i].setPosition(TowerPos.x - 220.0f, TowerPos.y);
		}
		if (i == 5)
		{
			attackSprite[i].setPosition(TowerPos.x + 260.0f, TowerPos.y + 240.0f);
		}
		if (i == 6)
		{
			attackSprite[i].setPosition(TowerPos.x + 20.0f, TowerPos.y + 240.0f);
		}
		if (i == 7)
		{
			attackSprite[i].setPosition(TowerPos.x - 220.0f, TowerPos.y + 240.0f);
		}
	}

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
		firstAttack = true;
		int damage_send;
		aoe.setFillColor(sf::Color(255, 60, 11, 120));
		damage_send = level * damage;
		return damage_send;
	}
	else
	{
		return 0;
	}
}

void Aoetower::Update(sf::RenderWindow& window)
{
	if (cooldown_attack <= cooldown_attack_temp - 0.4f)
	{
		aoe.setFillColor(sf::Color(11, 60, 253, 120));
	}
	else if(firstAttack)
	{
		for (int i = 0; i < 8; i++)
		{
			window.draw(attackSprite[i]);
		}
	}
	cooldown_attack -= cooldown.restart().asSeconds();

}

void Aoetower::Cooldown()
{
	cooldown_attack = 3.0;
	cooldown_attack_temp = cooldown_attack;
}

void Aoetower::upgrade()
{
	level += 1;
}
