#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<iostream>
#include"Enemy.h"
#include<vector>
#include"Bullet.h"
#include"Aoetower.h"
#include"Item.h"

using namespace std;

extern vector <Enemy> arrayofEnemy;
extern vector <Bullet> arrayofBullet;
extern vector <Platform> arrayofplatform;
extern vector <Aoetower> arrayofAoetower;
extern vector <Item> arrayofItem;
extern sf::RenderWindow window;
extern sf::Texture playerTexture;
extern sf::Font Gamefont;
extern sf::Texture bullettexture1;
extern sf::Texture aoetowerTexture;
extern sf::Texture HealthPotion;
extern int wave;
extern int score;
extern int playerHP;

class Global_variable
{
};

