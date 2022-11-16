#pragma once
#include "Console.hpp"
#include <vector>
class MapManager {
	Console console;
	int width, height;
	int mapid;
	std::vector<std::vector<std::vector<int>>> mapData; // ��� ���� ���� ��� ���� 3���� vector
public:
	MapManager();
	void DisplayMap();
	void ChangeMap(int mid); // ���� �� ���̵� �ٲٴ� �Լ�
	//�ش� ��ǥ�� �� ��/��ֹ��̸� false, �̵����ɱ����̸� true:�ۼ��� ������
	bool CheckMap(COORD pos);
};