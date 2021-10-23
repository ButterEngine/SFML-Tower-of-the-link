#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Platform.h"
#include"MapHandler.h"
#include"Global_variable.h"
#include"Enemy.h"
#include"Aoetower.h"
#include"Aoetower.h"
#include"Item.h"

int main()
{
	int map_test[64][64];
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (i == 21)
			{
				map_test[i][j] = 1;
			}
			else if (i == 46)
			{
				map_test[i][j] = 1;
			}
			else if (j == 15)
			{
				map_test[i][j] = 1;
			}
			else if (j == 49)
			{
				map_test[i][j] = 1;
			}
			else if (j == 32 && i >= 22 && i <= 24)
			{
				map_test[i][j] = 3;
			}
			else if (i == 24 && j >= 32 && j <=44)
			{
				map_test[i][j] = 3;
			}
			else if (j == 44 && i >= 25 && i <= 29)
			{
				map_test[i][j] = 3;
			}
			else if (i == 29 && j >= 19 && j <= 44)
			{
				map_test[i][j] = 3;
			}
			else if (i == 34 && j >= 19 && j <= 44)
			{
				map_test[i][j] = 3;
			}
			else if (i == 39 && j >= 19 && j <= 44)
			{
				map_test[i][j] = 3;
			}
			else if (i == 44 && j >= 19 && j <= 32)
			{
				map_test[i][j] = 3;
			}
			else if (j == 32 && i >= 44 && i <= 49)
			{
				map_test[i][j] = 3;
			}
			else if (j == 19 && i >= 29 && i <= 34)
			{
				map_test[i][j] = 3;
			}
			else if (j == 19 && i >= 39 && i <= 44)
			{
				map_test[i][j] = 3;
			}
			else if (j == 44 && i >= 34 && i <= 39)
			{
				map_test[i][j] = 3;
			}
			else
			{
				map_test[i][j] = 0;
			}
			//std::cout << map_test[i][j];
		}
		//std::cout << std::endl;
	}

	playerTexture.loadFromFile("assets/texture/player_right.png");
	Player player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 450.0f);
	MapHandler Map_01;
	sf::Texture map;
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5376, 3024));
	map.loadFromFile("assets/texture/map/Map_5.png");
	sf::RectangleShape background(sf::Vector2f(7680.0f, 7680.0f));
	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	background.setTexture(&map);
	Aoetower Tower_test(&aoetowerTexture, sf::Vector2u(1, 1), 0.2f);
	arrayofAoetower.push_back(Tower_test);
	sf::Texture enemytexture1;
	float deltaTime = 0.0f;
	Map_01.MapCreate(map_test);
	sf::Clock clock;
	float spawnCooldownMax = 30.0f;
	float spawnCooldown = spawnCooldownMax;
	bool canHitted;
	float hitCooldownMax = 30.0f;
	float hitCooldown = hitCooldownMax;
	bool canSpawn = false;
	bool col = false;
	wave = 1;
	int Enemy_Count = 0;
	int itemType = 0;
	sf::Clock cooldown;
	float cooldown_click = 0.0f;
	srand(time(NULL));

	while (window.isOpen()) {
		view.setCenter(player.getBody().getPosition());
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		cooldown_click -= cooldown.restart().asSeconds();
		//Aim
		sf::Vector2f mousePosWindow;
		mousePosWindow = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		float rotation;
		sf::RectangleShape Weapon;
		float dx = mousePosWindow.x - player.getBody().getPosition().x;
		float dy = mousePosWindow.y - player.getBody().getPosition().y;
		rotation = (float)(atan2(dy, dx) * 180.0 / 3.141);
		Weapon.setRotation(rotation + 180);
		sf::Vector2f aimDir;
		sf::Vector2f aimDirNorm;
		sf::Vector2f playerCenter = player.GetPostion();
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

		if (spawnCooldown < spawnCooldownMax)
		{
			spawnCooldown += 0.1f;
		}

		if (spawnCooldown >= spawnCooldownMax)
		{
			spawnCooldown = 0.0f;
			canSpawn = true;
		}
		else
		{
			canSpawn = false;
		}
		if (canSpawn)
		{
			if (wave == 1)
			{
				Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, 400.0f, 50.0f);
				arrayofEnemy.push_back(enemy1);
				Enemy_Count++;
			}
			if (wave == 2)
			{
				Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, 400.0f, 70.0f);
				arrayofEnemy.push_back(enemy1);
				Enemy_Count++;
			}
			if (wave == 3)
			{
				Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, 400.0f, 100.0f);
				arrayofEnemy.push_back(enemy1);
				Enemy_Count++;
			}
		}
		if (Enemy_Count == 30)
		{
			wave = 2;
		}
		if (Enemy_Count == 70)
		{
			wave = 3;
		}

		//////////////enemy1.Update(deltaTime, map_test);
		player.Update(deltaTime, map_test);
		window.clear(sf::Color::Black);
		window.draw(background);
		//Map_01.MapDraw(arrayofplatform);
		player.Draw(window);
		Tower_test.Draw(window);
		/////////////enemy1.Draw(window);

		if (hitCooldown < hitCooldownMax)
		{
			hitCooldown += 0.15;
		}
		if (hitCooldown >= hitCooldownMax)
		{
			hitCooldown = 0.0f;
			canHitted = true;
		}
		else
		{
			canHitted = false;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown_click <= 0)
		{
			cooldown_click = 0.5f;
			Bullet arrow1(&bullettexture1, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(player.getBody().getPosition().x, player.getBody().getPosition().y), rotation);
			arrow1.setvelo(aimDirNorm * 15.0f);
			arrow1.getBody().setRotation(rotation);
			arrayofBullet.push_back(arrow1);
		}
		for (int i = 0; i < arrayofEnemy.size(); i++)
		{
			arrayofEnemy[i].Update(deltaTime, map_test);
			window.draw(arrayofEnemy[i].getBody());
			window.draw(arrayofEnemy[i].getHealthbar());
		}

		for (int i = 0; i < arrayofItem.size(); i++)
		{
			window.draw(arrayofItem[i].getBody());
		}
		
		for (int i = 0; i < arrayofBullet.size(); i++)
		{
			col = false;
			if (arrayofBullet[i].getBody().getPosition().x < 0 || arrayofBullet[i].getBody().getPosition().x > 7680)
			{
				arrayofBullet.erase(arrayofBullet.begin() + i);
				continue;
			}
			if (arrayofBullet[i].getBody().getPosition().y < 0 || arrayofBullet[i].getBody().getPosition().y > 7680)
			{
				arrayofBullet.erase(arrayofBullet.begin() + i);
				continue;
			}
			for (int j = 0; j < arrayofEnemy.size(); j++)
			{
				if (arrayofBullet[i].GetCollider().CheckCollision(arrayofEnemy[j].GetCollider()))
				{
					arrayofBullet.erase(arrayofBullet.begin() + i);
					arrayofEnemy[j].Hit();
					if (arrayofEnemy[j].Die())
					{
						if ((1 + rand() % 4) == 4)
						{
							itemType = (1 + rand() % 4);
							Item Item1(itemType, arrayofEnemy[j].GetPostion());
							arrayofItem.push_back(Item1);
						}
						arrayofEnemy.erase(arrayofEnemy.begin() + j);
					}
					col = true;
					break;
				}
			}
			if (col)
			{
				continue;
			}
			arrayofBullet[i].moveMent(arrayofBullet[i].GetVelo());
			arrayofBullet[i].setColor(sf::Color::Cyan);
			window.draw(arrayofBullet[i].getBody());
		}
		for (int i = 0; i < arrayofAoetower.size(); i++)
		{
			for (int j = 0; j < arrayofEnemy.size(); j++)
			{
				if (arrayofAoetower[i].GetCollider().CheckCollision(arrayofEnemy[j].GetCollider()) && canHitted)
				{
					arrayofEnemy[j].Hit();
				}
				if (arrayofEnemy[j].Die())
				{
					arrayofEnemy.erase(arrayofEnemy.begin() + j);
				}
			}
		}
		for (int i = 0; i < arrayofEnemy.size(); i++)
		{
			if (arrayofEnemy[i].getBody().getPosition().y <= 2640)
			{
				arrayofEnemy.erase(arrayofEnemy.begin() + i);
				continue;
			}
		}
		bool enemy_stuck = false;
		for (int i = 0; i < arrayofEnemy.size(); i++)
		{
			if (arrayofEnemy[i].GetCollider().CheckCollision(player.GetCollider()))
			{
				if (!player.isblock())
				{
					arrayofEnemy[i].setCanmove(false);
					player.setblocked(true);
				}
				enemy_stuck = true;
				arrayofEnemy[i].Attack();
				std::cout << playerHP << "\n";
			}
			else
			{
				arrayofEnemy[i].setCanmove(true);
			}
		}
		if (!enemy_stuck)
		{
			player.setblocked(false);
			for (int i = 0; i < arrayofEnemy.size(); i++)
			{
				arrayofEnemy[i].setCanmove(true);
			}
		}
		for (int i = 0; i < arrayofItem.size(); i++)
		{
			if (arrayofItem[i].GetCollider().CheckCollision(player.GetCollider()))
			{
				arrayofItem.erase(arrayofItem.begin() + i);
			}
		}
		if (player.Die())
		{
			//std::cout << "Die";
		}
		window.setView(view);
		window.display();
	}
}