#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Global_variable.h"
#include<vector>
#include<iostream>

using namespace std;
class MapHandler
{
public:
	void addPlatform(float x, float y);
	void MapCreate(int map[64][64]);
	void MapDraw(vector<Platform> arrayofplatform);
};

