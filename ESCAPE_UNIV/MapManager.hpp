#pragma once
#include "Console.hpp"
#include <vector>
using namespace std;

class MapManager {
	Console console;
	int width, height;
	int mapid;
	std::vector<std::vector<std::vector<int>>> mapData; // 모든 맵의 정모를 담아 놓는 3차원 vector
	vector<vector<int>> mapcpy;
public:
	MapManager();
	void DisplayMap();
	void ReBox();
	void ChangeMap(int mid); // 현재 맵 아이디 바꾸는 함수
	//해당 좌표가 맵 밖/장애물이면 false, 이동가능구역이면 true:작성자 정재현
	int CheckMap(COORD pos);
	vector<vector<int>> GetMap();
	void SetMap(vector<vector<int>>);
	void ClearPos(COORD pos);
	void remap();
};