#include "MapManager.hpp"
using namespace std;
MapManager::MapManager() {
	// �ϴ� �ӽù������� ���⿡ �� ����� ����
	vector<vector<int>> map1 = {
		{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 99, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 113, 0, 99, 0, 99, 99, 99, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 99, 0, 99, 0, 99, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 99, 0, 99, 100, 99, 0, 99, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 99, 0, 99, 0, 99, 0, 99, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 99},
		{99, 0, 99, 0, 100, 0, 0, 0, 0, 99, 99, 100, 99, 99, 0, 99, 100, 99, 0, 99, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 99, 0, 99, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 100, 99, 0, 99, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 99, 0, 99, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 100, 99, 0, 99, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 99, 0, 99, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 99, 99, 0, 99, 0, 99, 99, 99, 99, 99, 0, 0, 0, 0, 100, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 99, 99, 99, 99, 99, 0, 99},
		{99, 99, -1, -1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 0, 0, 0, 0, 0, 99, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 99, 100, 99, 99, 99, 0, 99, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 99, 0, 99, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 100, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 99, 0, 99, 0, 99, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 99, 0, 99, 0, 99, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 99, 0, 99, 0, 99, 0, -2},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 100, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 100, 0, -2},
		{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 ,99, 99, 99, 99, 99 ,99}
	};
	mapData.push_back(map1);
	mapcpy = mapData[mapid];
}
void MapManager::ChangeMap(int mapid) {
	this->mapid = mapid;
	this->width = mapData[mapid][0].size(); this->height = mapData[mapid].size();
}
void MapManager::DisplayMap() {
	console.SetCurrentCursorPos(4, 2);
	COORD curPos = console.GetCurrentCursorPos();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			console.SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			switch (mapcpy[y][x]) {
			case 99:
				printf("�� ");
				break;
			case 100: // �̴� �ڽ�
				printf("�� ");
				break;
			case -1:
				printf("�� ");
				break;
			case -2:
				printf("�� ");
				break;
			default:
				break;
			}
			if (mapcpy[y][x] > 100) printf("�� "); // 101~150���� ���� ������ 1������ 50������ �ش��
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
	if (mapcpy[pos.Y][pos.X] > 100)return mapcpy[pos.Y][pos.X];
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
