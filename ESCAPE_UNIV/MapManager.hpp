#pragma once
#include "Console.hpp"
class MapManager {
	int width, height;
	int mapid;
public:
	MapManager();
	MapManager(int width, int height);
	void DisplayMap();
	void ChangeMap(int mid);
};