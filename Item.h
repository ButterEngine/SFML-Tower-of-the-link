#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class Item
{
public:
	Item(int type, sf::Vector2f position);
	void Draw();
	int getType();
	sf::RectangleShape getBody() { return this->body; }
	Collider GetCollider() { return Collider(body); }
private:
	int type;
	sf::RectangleShape body;
};

