#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class Item
{
public:
	Item(int type, sf::Vector2f position, sf::Texture* texture);
	void Draw();
	int getType();
	void Useitem(int type);
	bool EraseItem();
	sf::RectangleShape getBody() { return this->body; }
	Collider GetCollider() { return Collider(body); }
private:
	float cooldown_item;
	int type;
	sf::RectangleShape body;
	sf::Clock cooldown;
};

