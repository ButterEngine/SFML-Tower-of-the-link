
#include"Bullet.h"
#include"Player.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float rotation)
{
	this->rotation = rotation;
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


sf::Vector2f Bullet::GetVelo()
{
	return this->currVelocity;
}

void Bullet::setvelo(sf::Vector2f velo)
{
	this->currVelocity = velo;
}
