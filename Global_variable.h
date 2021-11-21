#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<iostream>
#include"Enemy.h"
#include<vector>
#include"Bullet.h"
#include"Aoetower.h"
#include"Item.h"
#include"HealingTower.h"
#include"Bufftower.h"

using namespace std;

extern vector <Enemy> arrayofEnemy;
extern vector <Bullet> arrayofBullet;
extern vector <Platform> arrayofplatform;
extern vector <Aoetower> arrayofAoetower;
extern vector <HealingTower> arrayofHealingtower;
extern vector <Bufftower> arrayofBufftower;
extern vector <Item> arrayofItem;
extern sf::RenderWindow window;
extern sf::Texture playerTexture;
extern sf::Font Gamefont;
extern sf::Texture bullettexture1;
extern sf::Texture aoetowerTexture;
extern sf::Texture BuffTowerTexture;
extern sf::Texture HealingTowerTexture;
extern sf::Texture HealthPotion;
extern sf::Texture CoinBar;
extern sf::Texture ScoreBar;
extern sf::Texture TowerBuild;
extern sf::Texture AttackTowerUpgrade;
extern sf::Texture HealingTowerUpgrade;
extern sf::Texture BuffTowerUpgrade;
extern sf::Texture AoeAttackTexture;
extern sf::Texture FlyingEnemyTexture;
extern sf::Texture SkeletonTexture;
extern sf::Texture GoblinTexture;
extern sf::Texture MushroomTexture;
extern sf::Texture CoinTexture;
extern sf::Texture HpPotionTexture;
extern sf::Texture StatuePotionTexture;
extern int AttackBuildCost;
extern int HealingBuildCost;
extern int BuffBuildCost;
extern int AttackUpgradeCost;
extern int HealingUpgradeCost;
extern int BuffUpgradeCost;
extern int CurrentUpgradeCost;
extern int CurrentTowerLevel;
extern int wave;
extern int statueHP;
extern int playerExp;
extern int playerLevel;
extern int Coin;
extern int Score;
extern int towerType;
extern int towerNumber;

extern int playerHP;

class Global_variable
{
};

