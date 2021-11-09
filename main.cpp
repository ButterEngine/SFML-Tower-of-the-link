#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Platform.h"
#include"MapHandler.h"
#include"Global_variable.h"
#include"Enemy.h"
#include"Aoetower.h"
#include"HealingTower.h"
#include"Item.h"
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

struct ScoreDataStruct {
	string Name;
	int Score;
}TempHighScoreData[6];


bool compareTwoStudents(ScoreDataStruct a, ScoreDataStruct b)
{
	if (a.Score != b.Score)
	{
		return a.Score > b.Score;
	}
}

void computeRanks(ScoreDataStruct a[], int n)
{
	sort(a, a + n, compareTwoStudents);
}

int main()
{
	string Data[12];
	string NameData[6];
	int ScoreData[6];
	int round = 0;
	fstream HighScoreFile;
	HighScoreFile.open("HighScore.txt", ios::in);
	if (HighScoreFile.is_open())
	{
		string line;
		while (getline(HighScoreFile, line))
		{
			round++;
			Data[round - 1] = line;
		}
		round = 0;
		HighScoreFile.close();
	}
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
		if (i % 2 != 0)
		{
			if (i == 1)
			{
				TempHighScoreData[0].Score = stoi(Data[i]);
			}
			else
			{
				TempHighScoreData[i / 2].Score = stoi(Data[i]);
			}
		}
		else
		{
			TempHighScoreData[i / 2].Name = Data[i];
		}
	}
		/*
		for (int i = 0; i < 5; i++)
		{
			cout << NameData[i] << " " << ScoreData[i] << endl;
		}*/

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
				else if (j == 31 && i >= 22 && i <= 24)
				{
					map_test[i][j] = 3;
				}
				else if (i == 24 && j >= 31 && j <= 44)
				{
					map_test[i][j] = 3;
				}
				else if (j == 45 && i >= 24 && i <= 29)
				{
					map_test[i][j] = 3;
				}
				else if (i == 29 && j >= 19 && j <= 43)
				{
					map_test[i][j] = 3;
				}
				else if (i == 34 && j >= 19 && j <= 45)
				{
					map_test[i][j] = 3;
				}
				else if (i == 39 && j >= 19 && j <= 45)
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
				else if (j == 45 && i >= 34 && i <= 39)
				{
					map_test[i][j] = 3;
				}
				else if ((i == 26 || i == 27) && (j == 18 || j == 19))
				{
					map_test[i][j] = 7;
				}
				else if ((i == 26 || i == 27) && (j == 41 || j == 42))
				{
					map_test[i][j] = 7;
				}
				else if ((i == 31 || i == 32) && (j == 37 || j == 38))
				{
					map_test[i][j] = 7;
				}
				else if ((i == 36 || i == 37) && (j == 25 || j == 26))
				{
					map_test[i][j] = 7;
				}
				else if ((i == 41 || i == 42) && (j == 21 || j == 22))
				{
					map_test[i][j] = 7;
				}
				else if ((i == 41 || i == 42) && (j == 44 || j == 45))
				{
					map_test[i][j] = 7;
				}
				else
				{
					map_test[i][j] = 0;
				}
				//std::cout << map_test[i][j];
			}
			//std::cout << std::endl;
		}

		Gamefont.loadFromFile("assets/font/GameFont.otf");
		BuffTowerTexture.loadFromFile("assets/texture/Tower/Obelisk_effects.png");
		HealingTowerTexture.loadFromFile("assets/texture/Tower/skull_tower_green_free_idle-Sheet.png");
		//playerTexture.loadFromFile("assets/texture/Tower/Obelisk_effects.png");
		Player player(&playerTexture, sf::Vector2u(1, 1), 0.2f, 450.0f);
		MapHandler Map_01;
		sf::Texture map;
		sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5376, 3024));
		map.loadFromFile("assets/texture/map/Map_7.png");
		sf::RectangleShape Menu(sf::Vector2f(1920.0f, 1080.0f));
		sf::Texture MenuTexture;
		MenuTexture.loadFromFile("assets/Menu/Menu.png");
		Menu.setTexture(&MenuTexture);
		Menu.setPosition(0.0f, 0.0f);

		sf::RectangleShape EnterName(sf::Vector2f(1920.0f, 1080.0f));
		sf::Texture EnterNameTexture;
		EnterNameTexture.loadFromFile("assets/Menu/EnterYourName.png");
		EnterName.setTexture(&EnterNameTexture);
		EnterName.setPosition(0.0f, 0.0f);

		sf::RectangleShape background(sf::Vector2f(7680.0f, 7680.0f));
		sf::RectangleShape mousehitBox(sf::Vector2f(10.0f, 10.0f));
		background.setPosition(sf::Vector2f(0.0f, 0.0f));
		background.setTexture(&map);
		//Aoetower Tower_test(&aoetowerTexture, sf::Vector2u(1, 1), 0.2f);
		//arrayofAoetower.push_back(Tower_test);
		sf::Texture enemytexture1;
		sf::RectangleShape PreBuildTower;
		PreBuildTower.setSize(sf::Vector2f(240.0f, 240.0f));
		PreBuildTower.setFillColor(sf::Color(51, 255, 85, 120));
		float deltaTime = 0.0f;
		Map_01.MapCreate(map_test);
		sf::Clock clock;
		float spawnCooldownMax = 30.0f;
		float spawnCooldown = spawnCooldownMax;
		float monsterSpeed = 400.0f;
		float monsterHp = 40.0f;
		bool canSpawn = false;
		bool col = false;
		bool TowerMenu = false;
		bool UpgradeTowerMenu = false;
		bool canbuild = false;
		bool Buffed = false;
		bool aoeCooldown = false;
		bool SpecialMonster = false;
		bool isGameStart = false;
		bool MainMenu = true;
		bool EnterNameMenu = false;
		bool HowToPlayMenu = false;
		int Mouse_x;
		string PlayerName;
		int Mouse_y;
		int Mouse_x_temp;
		int Mouse_y_temp;
		int playerDamage = 10;
		int aoeDamage = 0;
		bool firstwave = true;
		bool KeyHold = false;
		sf::Vector2f preTower;
		wave = 1;
		int Enemy_Count = 0;
		int temp_Enemy_Count = Enemy_Count;
		int itemType = 0;
		sf::Clock cooldown;
		float click_interval = 0.1f;
		float cooldown_click = 0.1f;
		float cooldown_upgrade = 0.1f;
		float cooldown_aoe = 0.0f;
		float cooldown_timer = 0.0f;
		float DebounceBuildnUpgrade = 0.0f;
		float WaveChangeCooldown = 10.0f;
		srand(time(NULL));
		int enemydamage = 5;

		sf::Text StartText;
		StartText.setString("START");
		StartText.setFont(Gamefont);
		StartText.setCharacterSize(80);
		StartText.setPosition(900.0f, 440.0f);
		StartText.setFillColor(sf::Color::White);
		StartText.setOutlineColor(sf::Color::Black);
		StartText.setOutlineThickness(10);

		sf::Text HighScoreText;
		HighScoreText.setString("HIGHSCORE");
		HighScoreText.setFont(Gamefont);
		HighScoreText.setCharacterSize(80);
		HighScoreText.setPosition(845.0f, 580.0f);
		HighScoreText.setFillColor(sf::Color::White);
		HighScoreText.setOutlineColor(sf::Color::Black);
		HighScoreText.setOutlineThickness(10);

		sf::Text HowToPlayText;
		HowToPlayText.setString("HOW TO PLAY");
		HowToPlayText.setFont(Gamefont);
		HowToPlayText.setCharacterSize(80);
		HowToPlayText.setPosition(820.0f, 720.0f);
		HowToPlayText.setFillColor(sf::Color::White);
		HowToPlayText.setOutlineColor(sf::Color::Black);
		HowToPlayText.setOutlineThickness(10);

		sf::Text ExitText;
		ExitText.setString("Exit");
		ExitText.setFont(Gamefont);
		ExitText.setCharacterSize(80);
		ExitText.setPosition(920.0f, 845.0f);
		ExitText.setFillColor(sf::Color::White);
		ExitText.setOutlineColor(sf::Color::Black);
		ExitText.setOutlineThickness(10);

		sf::Text PlayerNameText;
		PlayerNameText.setPosition(540.0f, 500.0f);
		PlayerNameText.setFont(Gamefont);
		PlayerNameText.setCharacterSize(180);
		PlayerNameText.setFillColor(sf::Color::White);
		PlayerNameText.setOutlineColor(sf::Color::Black);
		PlayerNameText.setOutlineThickness(10);

		while (window.isOpen()) {
			//std::cout << WaveChangeCooldown << "\n";
			view.setCenter(player.getBody().getPosition());
			deltaTime = clock.restart().asSeconds();
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}
			if (!isGameStart)
			{
				//std::cout << sf::Mouse::getPosition().x << " / " << sf::Mouse::getPosition().y << "\n";
				if (MainMenu)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.close();
					}
					window.draw(Menu);
					window.draw(StartText);
					window.draw(HighScoreText);
					window.draw(HowToPlayText);
					window.draw(ExitText);

					StartText.setFillColor(sf::Color::White);
					HighScoreText.setFillColor(sf::Color::White);
					HowToPlayText.setFillColor(sf::Color::White);
					ExitText.setFillColor(sf::Color::White);

					if (sf::Mouse::getPosition().x >= 597 && sf::Mouse::getPosition().x <= 1351 && sf::Mouse::getPosition().y >= 480 && sf::Mouse::getPosition().y <= 578)
					{
						StartText.setFillColor(sf::Color::Green);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							EnterNameMenu = true;
							MainMenu = false;
							HowToPlayMenu = false;
						}
					}
					if (sf::Mouse::getPosition().x >= 597 && sf::Mouse::getPosition().x <= 1351 && sf::Mouse::getPosition().y >= 624 && sf::Mouse::getPosition().y <= 722)
					{
						HighScoreText.setFillColor(sf::Color::Green);
					}
					if (sf::Mouse::getPosition().x >= 597 && sf::Mouse::getPosition().x <= 1351 && sf::Mouse::getPosition().y >= 761 && sf::Mouse::getPosition().y <= 858)
					{
						HowToPlayText.setFillColor(sf::Color::Green);
					}
					if (sf::Mouse::getPosition().x >= 597 && sf::Mouse::getPosition().x <= 1351 && sf::Mouse::getPosition().y >= 900 && sf::Mouse::getPosition().y <= 992)
					{
						ExitText.setFillColor(sf::Color::Green);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							window.close();
						}
					}
				}
				if (EnterNameMenu)
				{
					window.draw(EnterName);
					window.draw(PlayerNameText);
					if (event.type == sf::Event::TextEntered)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && PlayerName.size() != 0 && !KeyHold)
						{
							PlayerName.pop_back();
							KeyHold = true;
						}
						else if (((event.text.unicode >= 48 && event.text.unicode <= 57) || (event.text.unicode >= 65 && event.text.unicode <= 90) || (event.text.unicode >= 97 && event.text.unicode <= 122)) && !KeyHold && PlayerName.size() < 12)
						{
							PlayerName.push_back((char)event.text.unicode);
							KeyHold = true;
						}
						PlayerNameText.setString(PlayerName);
					}
					else
					{
						KeyHold = false;
					}
					if (sf::Mouse::getPosition().x >= 46 && sf::Mouse::getPosition().x <= 184 && sf::Mouse::getPosition().y >= 890 && sf::Mouse::getPosition().y <= 1090)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							PlayerName = "";
							PlayerNameText.setString(PlayerName);
							EnterNameMenu = false;
							HowToPlayMenu = false;
							MainMenu = true;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						isGameStart = true;
						WaveChangeCooldown = 10.0f;
					}
					if (sf::Mouse::getPosition().x >= 1655 && sf::Mouse::getPosition().x <= 1835 && sf::Mouse::getPosition().y >= 562 && sf::Mouse::getPosition().y <= 743)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							isGameStart = true;
							WaveChangeCooldown = 10.0f;
						}
					}
				}
				window.display();
			}
			if (isGameStart)
			{
				//std::cout << "X = " << sf::Mouse::getPosition().x << "     " << "Y = " << sf::Mouse::getPosition().y << "\n";
				cooldown_timer = cooldown.restart().asSeconds();
				if (firstwave)
				{
					firstwave = false;
					cooldown_timer = 0;
				}
				cooldown_upgrade -= cooldown_timer;
				cooldown_click -= cooldown_timer;
				cooldown_aoe -= cooldown_timer;
				DebounceBuildnUpgrade -= cooldown_timer;
				if (arrayofEnemy.size() == 0)
				{
					WaveChangeCooldown -= cooldown_timer;
				}
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

				if (WaveChangeCooldown <= 0.0f)
				{
					if (spawnCooldown < spawnCooldownMax)
					{
						spawnCooldown += 0.125f;
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
						if ((1 + rand() % 6) == 4 && wave >= 4)
						{
							SpecialMonster = true;
						}
						if (wave == 1)
						{
							Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, monsterSpeed, monsterHp * wave, enemydamage * wave, SpecialMonster);
							arrayofEnemy.push_back(enemy1);
							Enemy_Count++;
						}
						if (wave == 2)
						{
							Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, monsterSpeed, monsterHp * wave, enemydamage * wave, SpecialMonster);
							arrayofEnemy.push_back(enemy1);
							Enemy_Count++;
						}
						if (wave == 3)
						{
							Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, monsterSpeed, monsterHp * wave, enemydamage * wave, SpecialMonster);
							arrayofEnemy.push_back(enemy1);
							Enemy_Count++;
						}
						if (wave >= 4)
						{
							Enemy enemy1(&enemytexture1, sf::Vector2u(1, 1), 0.2f, monsterSpeed, monsterHp * wave, enemydamage * wave, SpecialMonster);
							arrayofEnemy.push_back(enemy1);
							Enemy_Count++;
						}
						SpecialMonster = false;
					}
				}
				if (Enemy_Count % 15 == 0 && Enemy_Count != temp_Enemy_Count)
				{
					WaveChangeCooldown = 10.0f;
					temp_Enemy_Count = Enemy_Count;
					wave += 1;
					spawnCooldownMax -= 1.0f;
					if (spawnCooldownMax < 15.0f)
					{
						spawnCooldownMax = 15.0f;
					}
				}

				//////////////enemy1.Update(deltaTime, map_test);
				player.Update(deltaTime, map_test);
				for (int i = 0; i < arrayofBufftower.size(); i++)
				{
					arrayofBufftower[i].Update(deltaTime);
				}
				window.clear(sf::Color::Black);
				window.draw(background);
				//std::cout << towerNumber << "\n";
				//Map_01.MapDraw(arrayofplatform);
				if (TowerMenu)
				{
					window.draw(PreBuildTower);
				}
				player.Draw(window);
				/////////////enemy1.Draw(window);
				mousehitBox.setPosition(mousePosWindow.x, mousePosWindow.y);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Mouse_x = mousePosWindow.x / 120;
					Mouse_y = mousePosWindow.y / 120;
					if (map_test[Mouse_y][Mouse_x] == 7)
					{
						DebounceBuildnUpgrade = 0.3f;
						canbuild = true;
						if ((Mouse_x == 18 || Mouse_x == 19) && (Mouse_y == 26 || Mouse_y == 27))
						{
							preTower.x = 18.0f * 120.0f;
							preTower.y = 26.0f * 120.0f;
							Mouse_x_temp = 18;
							Mouse_y_temp = 26;
						}
						if ((Mouse_x == 41 || Mouse_x == 42) && (Mouse_y == 26 || Mouse_y == 27))
						{
							preTower.x = 41.0f * 120.0f;
							preTower.y = 26.0f * 120.0f;
							Mouse_x_temp = 41;
							Mouse_y_temp = 26;
						}
						if ((Mouse_x == 37 || Mouse_x == 38) && (Mouse_y == 31 || Mouse_y == 32))
						{
							preTower.x = 37.0f * 120.0f;
							preTower.y = 31.0f * 120.0f;
							Mouse_x_temp = 37;
							Mouse_y_temp = 31;
						}
						if ((Mouse_x == 25 || Mouse_x == 26) && (Mouse_y == 36 || Mouse_y == 37))
						{
							preTower.x = 25.0f * 120.0f;
							preTower.y = 36.0f * 120.0f;
							Mouse_x_temp = 25;
							Mouse_y_temp = 36;
						}
						if ((Mouse_x == 21 || Mouse_x == 22) && (Mouse_y == 41 || Mouse_y == 42))
						{
							preTower.x = 21.0f * 120.0f;
							preTower.y = 41.0f * 120.0f;
							Mouse_x_temp = 21;
							Mouse_y_temp = 41;
						}
						if ((Mouse_x == 44 || Mouse_x == 45) && (Mouse_y == 41 || Mouse_y == 42))
						{
							preTower.x = 44.0f * 120.0f;
							preTower.y = 41.0f * 120.0f;
							Mouse_x_temp = 44;
							Mouse_y_temp = 41;
						}
						PreBuildTower.setPosition(preTower.x, preTower.y);
						TowerMenu = true;
						UpgradeTowerMenu = false;
					}
					if (TowerMenu && canbuild && DebounceBuildnUpgrade <= 0.0f)
					{
						AttackBuildCost = 100 * (arrayofAoetower.size() + 1);
						HealingBuildCost = 75 * (arrayofHealingtower.size() + 1);
						BuffBuildCost = 200 * (arrayofBufftower.size() + 1);

						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1881 && sf::Mouse::getPosition().y >= 187 && sf::Mouse::getPosition().y <= 200)
						{
							TowerMenu = false;
						}
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1567 && sf::Mouse::getPosition().y >= 378 && sf::Mouse::getPosition().y <= 548)
						{
							if (Coin >= AttackBuildCost)
							{
								Coin -= AttackBuildCost;
								Aoetower Tower_test(&aoetowerTexture, sf::Vector2u(1, 1), 0.2f, preTower);
								arrayofAoetower.push_back(Tower_test);
								map_test[Mouse_y_temp + 1][Mouse_x_temp] = 8;
								map_test[Mouse_y_temp + 1][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp] = 8;
								canbuild = false;
								TowerMenu = false;
							}
						}
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1567 && sf::Mouse::getPosition().y >= 552 && sf::Mouse::getPosition().y <= 705)
						{
							if (Coin >= HealingBuildCost)
							{
								Coin -= HealingBuildCost;
								HealingTower Healing_Tower_test(&HealingTowerTexture, sf::Vector2u(12, 1), 0.125f, preTower);
								arrayofHealingtower.push_back(Healing_Tower_test);
								map_test[Mouse_y_temp + 1][Mouse_x_temp] = 8;
								map_test[Mouse_y_temp + 1][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp] = 8;
								canbuild = false;
								TowerMenu = false;
							}
						}
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1567 && sf::Mouse::getPosition().y >= 710 && sf::Mouse::getPosition().y <= 873)
						{
							if (Coin >= BuffBuildCost)
							{
								Coin -= BuffBuildCost;
								Bufftower Buff_tower_test(&BuffTowerTexture, sf::Vector2u(14, 1), 0.125f, preTower);
								arrayofBufftower.push_back(Buff_tower_test);
								map_test[Mouse_y_temp + 1][Mouse_x_temp] = 8;
								map_test[Mouse_y_temp + 1][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp + 1] = 8;
								map_test[Mouse_y_temp][Mouse_x_temp] = 8;
								canbuild = false;
								TowerMenu = false;
							}
						}
					}
					if (map_test[Mouse_y][Mouse_x] == 8)
					{
						DebounceBuildnUpgrade = 0.3f;
						for (int i = 0; i < arrayofAoetower.size(); i++)
						{
							if (arrayofAoetower[i].GetCollider().CheckCollision(mousehitBox))
							{
								UpgradeTowerMenu = true;
								TowerMenu = false;
								towerType = 1;
								towerNumber = i;
								CurrentTowerLevel = arrayofAoetower[i].getLevel();
								AttackUpgradeCost = CurrentTowerLevel * 150;
								CurrentUpgradeCost = AttackUpgradeCost;
							}
						}
						for (int i = 0; i < arrayofHealingtower.size(); i++)
						{
							if (arrayofHealingtower[i].GetCollider().CheckCollision(mousehitBox))
							{
								UpgradeTowerMenu = true;
								TowerMenu = false;
								towerType = 2;
								towerNumber = i;
								CurrentTowerLevel = arrayofHealingtower[i].getLevel();
								HealingUpgradeCost = CurrentTowerLevel * 100;
								CurrentUpgradeCost = HealingUpgradeCost;
							}
						}
						for (int i = 0; i < arrayofBufftower.size(); i++)
						{
							if (arrayofBufftower[i].GetCollider().CheckCollision(mousehitBox))
							{
								UpgradeTowerMenu = true;
								TowerMenu = false;
								towerType = 3;
								towerNumber = i;
								CurrentTowerLevel = arrayofBufftower[i].getLevel();
								BuffUpgradeCost = CurrentTowerLevel * 250;
								CurrentUpgradeCost = BuffUpgradeCost;
							}

						}
					}
					if (UpgradeTowerMenu && DebounceBuildnUpgrade <= 0.0f)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1881 && sf::Mouse::getPosition().y >= 187 && sf::Mouse::getPosition().y <= 200)
						{
							UpgradeTowerMenu = false;
						}
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= 1567 && sf::Mouse::getPosition().y >= 887 && sf::Mouse::getPosition().y <= 1208 && cooldown_upgrade <= 0.0f)
						{
							if (towerType == 1 && Coin >= AttackUpgradeCost && arrayofAoetower[towerNumber].getLevel() < 5)
							{
								cooldown_upgrade = 0.3f;
								Coin -= AttackUpgradeCost;
								arrayofAoetower[towerNumber].upgrade();
								CurrentTowerLevel = arrayofAoetower[towerNumber].getLevel();
								AttackUpgradeCost = CurrentTowerLevel * 150;
							}
							if (towerType == 2 && Coin >= HealingUpgradeCost && arrayofHealingtower[towerNumber].getLevel() < 5)
							{
								cooldown_upgrade = 0.3f;
								Coin -= HealingUpgradeCost;
								arrayofHealingtower[towerNumber].upgrade();
								CurrentTowerLevel = arrayofHealingtower[towerNumber].getLevel();
								HealingUpgradeCost = CurrentTowerLevel * 150;
							}
							if (towerType == 3 && Coin >= BuffUpgradeCost && arrayofBufftower[towerNumber].getLevel() < 5)
							{
								cooldown_upgrade = 0.3f;
								Coin -= BuffUpgradeCost;
								arrayofBufftower[towerNumber].upgrade();
								CurrentTowerLevel = arrayofBufftower[towerNumber].getLevel();
								BuffUpgradeCost = CurrentTowerLevel * 150;
							}
						}
					}
					if (cooldown_click <= click_interval && map_test[Mouse_y][Mouse_x] != 8 && map_test[Mouse_y][Mouse_x] != 7)
					{
						if (!(sf::Mouse::getPosition().x >= 1567 && (TowerMenu || UpgradeTowerMenu)))
						{
							cooldown_click = 1.0f;
							Bullet arrow1(&bullettexture1, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(player.getBody().getPosition().x, player.getBody().getPosition().y), rotation);
							arrow1.setvelo(aimDirNorm * 15.0f);
							arrow1.getBody().setRotation(rotation);
							arrayofBullet.push_back(arrow1);
						}
					}
				}
				for (int i = 0; i < arrayofAoetower.size(); i++)
				{
					arrayofAoetower[i].Update(window);
					arrayofAoetower[i].Draw(window);
				}
				for (int i = 0; i < arrayofHealingtower.size(); i++)
				{
					arrayofHealingtower[i].Update(deltaTime);
					arrayofHealingtower[i].Draw(window);
				}
				for (int i = 0; i < arrayofBufftower.size(); i++)
				{
					arrayofBufftower[i].Draw(window);
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
							arrayofEnemy[j].Hit(playerDamage);
							if (arrayofEnemy[j].Die())
							{
								Score += wave * 20;
								Coin += wave * 10;
								if ((1 + rand() % 6) == 4)
								{
									itemType = (1 + rand() % 3);
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
					aoeDamage = 0;
					for (int j = 0; j < arrayofEnemy.size(); j++)
					{
						if (arrayofAoetower[i].GetCollider().CheckCollision(arrayofEnemy[j].GetCollider()))
						{
							aoeDamage = arrayofAoetower[i].getDamage();
							arrayofEnemy[j].Hit(aoeDamage);
						}
						if (arrayofEnemy[j].Die())
						{
							Score += wave * 15;
							Coin += wave * 5;
							arrayofEnemy.erase(arrayofEnemy.begin() + j);
							j--;
						}
					}
					if (aoeDamage != 0)
					{
						arrayofAoetower[i].Cooldown();
					}
				}

				for (int i = 0; i < arrayofHealingtower.size(); i++)
				{
					if (arrayofHealingtower[i].GetCollider().CheckCollision(player.GetCollider()))
					{
						arrayofHealingtower[i].Healing();
					}
				}

				for (int i = 0; i < arrayofBufftower.size(); i++)
				{
					int count_buff = 0;
					if (arrayofBufftower[i].GetCollider().CheckCollision(player.GetCollider()))
					{
						count_buff++;
						Buffed = true;
					}
					else if (count_buff == 0)
					{
						Buffed = false;
					}
					if (Buffed)
					{
						click_interval = arrayofBufftower[i].Buff();
					}
					else
					{
						click_interval = 0.0f;
					}
				}


				for (int i = 0; i < arrayofEnemy.size(); i++)
				{
					if (arrayofEnemy[i].getBody().getPosition().y <= 2640)
					{
						statueHP -= 1;
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
						arrayofEnemy[i].Attack(arrayofEnemy[i].getDamage());
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
						arrayofItem[i].Useitem(arrayofItem[i].getType());
						arrayofItem.erase(arrayofItem.begin() + i);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					TowerMenu = false;
					UpgradeTowerMenu = false;
				}
				if (TowerMenu)
				{
					player.Draw_TowerMenu();
				}
				if (UpgradeTowerMenu)
				{
					player.Draw_UpgradeTowerMenu();
				}
				if (player.Die() || statueHP == 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
				{
					TempHighScoreData[5].Name = PlayerName;
					TempHighScoreData[5].Score = Score;
					computeRanks(TempHighScoreData, 6);
					for (int i = 0; i < 6; i++)
					{
						cout << "Name : " << TempHighScoreData[i].Name << " Score : " << TempHighScoreData[i].Score << endl;
					}
					HighScoreFile.open("HighScore.txt", ios::out);
					if (HighScoreFile.is_open())
					{
						for (int i = 0; i < 5; i++)
						{
							HighScoreFile << TempHighScoreData[i].Name << endl;
							HighScoreFile << TempHighScoreData[i].Score << endl;
						}
						HighScoreFile.close();
					}
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				{
					Coin += 10;
					Score += 10;
				}
				window.setView(view);
				window.display();
			}
		}
	}
