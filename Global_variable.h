#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<iostream>
#include"Enemy.h"
#include<vector>
#include"Bullet.h"

using namespace std;

extern vector <Enemy> arrayofEnemy;
extern vector <Bullet> arrayofBullet;
extern vector <Platform> arrayofplatform;
extern sf::RenderWindow window;
extern sf::Texture playerTexture;
extern sf::Texture bullettexture1;
extern int wave;

class Global_variable
{
};

