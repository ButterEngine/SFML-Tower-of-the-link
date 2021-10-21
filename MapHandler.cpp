#include "MapHandler.h"
#include "Platform.h"
#include<vector>
#include<iostream>
#include "Global_variable.h"

using namespace std;

void MapHandler::MapCreate(int map[64][64])
{
	int row, collum;
	for (collum = 0; collum < 64; collum++)
	{
		for (row = 0; row < 64; row++)
		{
			if (map[collum][row])
			{
				Platform map_hitbox(nullptr, sf::Vector2f(120.0f, 120.0f), sf::Vector2f(row * 120.0f, collum * 120.f));
				arrayofplatform.push_back(map_hitbox);
			
			}
		}
	}
}

void MapHandler::MapDraw(vector<Platform> arrayofplatform)
{
	for (int i = 0; i < arrayofplatform.size(); i++)
	{
		window.draw(arrayofplatform[i].getBody());
	}
}
