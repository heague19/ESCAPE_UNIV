#include "GameManager.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager() {
	
}
void GameManager::MainLoop() {
	console.RemoveCursor();
	console.SetConsoleSize(150, 40);

	
	// 창크기 150 40 고정 함수 Title 설정 함수 by 이해규
	system("mode con: cols=150 lines=40 | title Escape_Univ");
	inventory.Constructor_All_Init_Inventory();// 아이템 창 구현

	while (true) {
		

	}// 게임 구성 실행 코드 현
}