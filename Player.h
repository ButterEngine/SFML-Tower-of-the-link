#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
#include"MapHandler.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltatime, int map[64][64]);
	void Draw(sf::RenderWindow& window);
	bool isblock()
	{
		return blocked;
	}
	void setblocked(bool blocked)
	{
		this->blocked = blocked;
	}
	bool Die();
	void Draw_TowerMenu();

	sf::Vector2i Check_Player_Position();
	sf::Vector2f GetPostion() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape getBody() { return this->body; }

private:
	sf::RectangleShape body;
	sf::RectangleShape Healthbar;
	sf::RectangleShape Healthbarframe;
	sf::RectangleShape MaxHealthbar;
	sf::RectangleShape statueHealthbar;
	sf::RectangleShape statueHealthbarframe;
	sf::RectangleShape statueMaxHealthbar;
	sf::RectangleShape TowerMenu;
	sf::Text HP;
	Animation animation;
	unsigned int row;
	float speed;
	float playerMaxHP = 100;
	float statueMaxHP = 30;
	bool blocked = false;
};
