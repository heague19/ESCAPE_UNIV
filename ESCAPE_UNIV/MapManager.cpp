#include "MapManager.hpp"
#include "Map_5_floor.h"
#include "Map_6_floor.h"
using namespace std;
MapManager::MapManager() {
	mapData.push_back(Map6);
	mapData.push_back(Map5);
	mapData.push_back(Box_Quiz_Map5_1);
	mapData.push_back(Map5_2_Upper);
	mapData.push_back(Map5_2_Bottom);
	mapData.push_back(Map5_4);
	mapcpy = mapData[mapid];
}
void MapManager::ChangeMap(int mapid) {
	console.SetCurrentCursorPos(4, 2);
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			printf("  ");
		}
	}
	console.SetCurrentCursorPos(curPos.X, curPos.Y);
	this->mapid = mapid;
	this->width = mapData[mapid][0].size(); this->height = mapData[mapid].size();
	remap(); DisplayMap();
}
void MapManager::DisplayMap() {
	console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y); // 맵 시작 지점
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			switch (mapcpy[y][x]) {
			case 99:
				printf("■ ");
				break;
			case 100: // 미는 박스
				printf("▨ ");
				break;
			default:
				break;
			}
			if ((mapcpy[y][x] - 1) / 100 == 1) printf("ⓘ "); // 101~150까지 각각 아이템 1번부터 50번까지 해당됨
			if ((mapcpy[y][x] - 1) / 100 == 2) printf("─ ");
			if ((mapcpy[y][x] - 1) / 100 == 3) printf("│ ");
		}
	}
	console.SetCurrentCursorPos(curPos.X, curPos.Y);
}
void MapManager::ReBox() {
	console.SetCurrentCursorPos(4, 2);
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			if (mapcpy[y][x] == 100) {
				printf("  ");
			}
		}
	}
	console.SetCurrentCursorPos(curPos.X, curPos.Y);
}

int MapManager::CheckMap(COORD pos) {
	if (pos.X >= width || pos.X < 0 || pos.Y >= height || pos.Y < 0)return false;
	if (mapcpy[pos.Y][pos.X] == 0)return 1;
	if ((mapcpy[pos.Y][pos.X] - 1) / 100 == 1)return mapcpy[pos.Y][pos.X];
	return 0;
}

void MapManager::ClearPos(COORD pos) {
	if (pos.X >= width || pos.X < 0 || pos.Y >= height || pos.Y < 0)return;
	mapcpy[pos.Y][pos.X] = 0;
}

vector<vector<int>> MapManager::GetMap()
{
	return mapcpy;
}

void MapManager::SetMap(vector<vector<int>> p) {
	p.swap(mapcpy);
	p.clear();
}
void MapManager::remap() {
	mapcpy = mapData[mapid];
}
