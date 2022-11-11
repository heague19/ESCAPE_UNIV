#include "GameManager.hpp"
#include "Inventory.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager() {

}
void GameManager::MainLoop() {
	Console console;
	console.RemoveCursor();
	console.SetConsoleSize(150, 40);

	Inventory inventory;
	//map.Constructor_Inventory_Boundary();
	system("mode con: cols=150 lines=40 | title Escape_Univ");// âũ�� 150 40 ���� �Լ� Title ���� �Լ� by ���ر�
	inventory.Constructor_Inventory_Boundary();
	while (true) {
		

	}// ���� ���� ���� �ڵ� ��
}