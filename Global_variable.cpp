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
int score;
int wave = 0;
