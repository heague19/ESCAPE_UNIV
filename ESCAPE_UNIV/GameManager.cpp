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
	console.SetConsoleSize(150, 40);// cmd 창 크기 고정 함수 by 함수 (정환아 만들었으면 얘기해줘..) 주석을 써줘...
	inventory.Constructor_All_Init_Inventory();// 아이템 창 구현

	while (true) {
		console.SetCurrentCursorPos(4, 2);
		mapManager.DisplayMap();
		playermove.Move();
	}// 게임 구성 실행 코드 현
}