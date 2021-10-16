#include <SFML/Graphics.hpp>
//#include <iostream>
#include"Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720),"Tower Defense");


	sf::RectangleShape player(sf::Vector2f(145.0f, 130.0f));
	player.setPosition(320, 240);
	player.setOrigin(player.getSize().x, player.getSize().y);
	

	////// Texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("assets/texture/player_left.png");

	////// Sprite
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(3, 4), 0.3f);

	float deltaTime = 0.0f;

	sf::Clock clock;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				// Close window button clicked.
				window.close();
			}
		}
		animation.Update(2, deltaTime);
		player.setTextureRect(animation.uvRect);
		window.clear(sf::Color::Black);
		window.draw(player); // Drawing our shape.
		window.display();
	}
}