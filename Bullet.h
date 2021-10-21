#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"

class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position,float rotation);

	void Draw(sf::RenderWindow& window);
	void setPos(sf::Vector2f pos) { this->body.setPosition(pos); }
	void setColor(sf::Color color) { this->body.setFillColor(color); }
	void moveMent(sf::Vector2f moves) { this->body.move(moves); }
	sf::Vector2f GetVelo();
	void setvelo(sf::Vector2f velo);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape getBody() { return this->body; }

private:
	sf::RectangleShape body;
	float rotation;
	sf::Vector2f currVelocity;
};
