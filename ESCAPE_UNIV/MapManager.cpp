#include "MapManager.hpp"
#include "Map_3_floor.h"
#include "Map_4_floor.h"
#include "Map_5_floor.h"
#include "Map_6_floor.h"

using namespace std;
MapManager::MapManager(ItemManager &item):item(item) {
	roomId = { 60, 50, 51, 52, 53, 54,55, 40, 41, 42, 43, 44, 45 };
	mapData.push_back(Map6); // 0
	
	mapData.push_back(Map5); // 1
	// 5층 방 4개 (2 ~ 5)
	mapData.push_back(Box_Quiz_Map5_1); // 2
	mapData.push_back(Map5_2_Bottom); // 3 (임시)
	mapData.push_back(Map5_2_Upper); // 4 (임시)
	//mapData.push_back(Map5_)
	mapData.push_back(Map5_4); // 5 (임시)
	
	mapData.push_back(Map4); // 6
	// 4층 방 5개 (7 ~ 11)
	mapData.push_back(Map4_Room1); // 7
	mapData.push_back(vector<vector<int>>()); // 8 (임시)
	mapData.push_back(vector<vector<int>>()); // 9 (임시)
	mapData.push_back(vector<vector<int>>()); // 10 (임시)
	mapData.push_back(vector<vector<int>>()); // 11 (임시)
	//mapData.push_back(Map3);
	mapid = 0;
	mapcpy = mapData[mapid];
	
}
int MapManager::GetMapIdByRoomNumber(int roomNumber) { // 열쇠가 필요한 문이면 -1 반환
	int loc = -1;
	for (int i = 0; i < roomId.size(); i++) {
		if (roomId[i] == roomNumber) loc = i;
	}
	return loc;
}
COORD MapManager::CalculateStartLocation(int before, int after, int dy, int dx) { // 맵 아이디 전과 후가 주어지면 다음 시작 위치 반환
	auto& maptmp = mapData[after];
	for (int i = 0; i < maptmp.size(); i++) {
		for (int j = 0; j < maptmp[i].size(); j++) {
			if (maptmp[i][j] % 100 == roomId[before]) {
				if (i + dy < 0 || i + dy >= maptmp.size()) dy *= -1;
				if (j + dx < 0 || j + dx >= maptmp[i].size()) dx *= -1;
				if (maptmp[i + dy][j + dx] != 0) dy *= -1, dx *= -1;
				return { (short)(j + dx), (short)(i + dy) };
			}
		}
	}
}
void MapManager::ChangeMap(int mapid) {
	MapFloorUI::Show(mapid);
	console.SetCurrentCursorPos(4, 2);
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			printf("  ");
		}
	}
	console.SetCurrentCursorPos(curPos.X, curPos.Y);
	mapData[this->mapid] = mapcpy;
	this->mapid = mapid;
	this->width = mapData[mapid][0].size(); this->height = mapData[mapid].size();
	remap(); DisplayMap();
}
void MapManager::DisplayMap() {
	MapFloorUI::Show(mapid);
	console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y); // 맵 시작 지점
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			switch (mapcpy[y][x]) {
			case 99:
				Colorset(white, gray);
				printf("■");
				Colorset(black, white);
				break;
			case 100: // 미는 박스
				printf("▨ ");
				break;
			default:
				break;
			}
			if ((mapcpy[y][x] - 1) / 100 == 1) printf("ⓘ "); // 101~150까지 각각 아이템 1번부터 50번까지 해당됨
			if ((mapcpy[y][x] - 1) / 100 == 2) {
				Colorset( black, brightWhite);
				printf("━ ");
				Colorset(black, white);
			}
			if ((mapcpy[y][x] - 1) / 100 == 3) printf("┃ ");
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

int MapManager::GetMapAt(COORD pos) {
	if (pos.X >= width || pos.X < 0 || pos.Y >= height || pos.Y < 0)return false;
	return mapcpy[pos.Y][pos.X];
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

void MapManager::Colorset(int backColor, int textColor) {         //색 변환 함수
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Handle, (backColor << 4) + textColor);
}
