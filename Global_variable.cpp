#include "Global_variable.h"

vector<Platform> arrayofplatform;
vector <Bullet> arrayofBullet;
vector <Enemy> arrayofEnemy;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tower Defense");
sf::Font Gamefont;
sf::Texture playerTexture;
sf::Texture bullettexture1;
sf::Texture aoetowerTexture;
sf::Texture HealthPotion;
vector <Item> arrayofItem;
vector <Aoetower> arrayofAoetower;
vector <HealingTower>arrayofHealingtower;
vector <Bufftower> arrayofBufftower;
int playerHP = 100;
int statueHP = 30;
int wave = 0;
int playerExp = 0;
int playerLevel = 1;
int Coin = 0;
int Score = 0;