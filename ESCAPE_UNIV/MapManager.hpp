#pragma once
#include "GameTool.hpp"
#include <vector>
#include "PartPos.hpp"
#include "ItemManager.hpp"

class MapManager {
	Console console;
	ItemManager &item;
	int width, height;
	std::vector<std::vector<std::vector<int>>> mapData; // ��� ���� ���� ��� ���� 3���� vector
	vector<vector<int>> mapcpy;
	vector<int> roomId;
	typedef enum ColorKinds {      //��������
		black, blue, green, skyBlue, red, pink, Orange, white, gray, lightBlue, brightGreen, sky, brightRed, brightPink, brightYellow, brightWhite
	}ColorKinds;
public:
	int mapid;
	MapManager(ItemManager &item);
	void DisplayMap();
	void ReBox();
	int GetMapIdByRoomNumber(int);
	COORD CalculateStartLocation(int, int, int, int);
	void ChangeMap(int mid); // ���� �� ���̵� �ٲٴ� �Լ�
	//�ش� ��ǥ�� �� ��/��ֹ��̸� false, �̵����ɱ����̸� true:�ۼ��� ������
	int CheckMap(COORD pos);
	int GetMapAt(COORD pos);
	vector<vector<int>> GetMap();
	void SetMap(vector<vector<int>>);
	void ClearPos(COORD pos);
	void remap();
	void Colorset(int , int);
};