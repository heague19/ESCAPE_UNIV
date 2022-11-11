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
	system("mode con: cols=150 lines=40 | title Escape_Univ");// 창크기 150 40 고정 함수 Title 설정 함수 by 이해규
	inventory.Constructor_Inventory_Boundary();
	while (true) {
		

	}// 게임 구성 실행 코드 현
}