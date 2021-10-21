#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

bool Collider::CheckCollision(Collider other)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
	sf::RectangleShape thisBody = GetBody();

	float deltaX = otherPosition.x - (thisPosition.x + (thisBody.getSize().x / 2.0f));
	float deltaY = otherPosition.y - (thisPosition.y + (thisBody.getSize().y / 2.0f));

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}
	return false;
}