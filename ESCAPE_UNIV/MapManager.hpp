#pragma once
#include "GameTool.hpp"
#include <vector>
#include "PartPos.hpp"
#include "ItemManager.hpp"

class MapManager {
	Console console;
	ItemManager &item;
	int width, height;
	int mapid;
	std::vector<std::vector<std::vector<int>>> mapData; // ��� ���� ���� ��� ���� 3���� vector
	vector<vector<int>> mapcpy;
public:
	MapManager(ItemManager &item);
	void DisplayMap();
	void ReBox();
	void ChangeMap(int mid); // ���� �� ���̵� �ٲٴ� �Լ�
	//�ش� ��ǥ�� �� ��/��ֹ��̸� false, �̵����ɱ����̸� true:�ۼ��� ������
	int CheckMap(COORD pos);
	int GetMapAt(COORD pos);
	vector<vector<int>> GetMap();
	void SetMap(vector<vector<int>>);
	void ClearPos(COORD pos);
	void remap();
};