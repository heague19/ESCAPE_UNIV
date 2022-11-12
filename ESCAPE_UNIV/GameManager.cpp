#include "GameManager.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager() {
	mapManager.ChangeMap(0);
}
void GameManager::MainLoop() {
	console.RemoveCursor();
	console.SetConsoleSize(150, 40);

	
	// âũ�� 150 40 ���� �Լ� Title ���� �Լ� by ���ر�
	system("mode con: cols=150 lines=40 | title Escape_Univ");
	inventory.Constructor_All_Init_Inventory();// ������ â ����
	
	
	while (true) {
		console.SetCurrentCursorPos(4, 2);
		mapManager.DisplayMap();
		playermove.Move();
	}// ���� ���� ���� �ڵ� ��
}