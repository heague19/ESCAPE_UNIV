#pragma once
#include<windows.h>
#include "PlayerMove.hpp"
#include "Timer.hpp"
#include "GameOver.h"
using namespace std;
/*
가상 키 코드
https://learn.microsoft.com/ko-kr/windows/win32/inputdev/virtual-key-codes
*/
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_P 0x50
class InputManager {
private:
	Timer& timer;
	PlayerMove& playerMove;
	MapManager& mapManager;
	ItemManager& itemManager;
	bool flag_p = false;
public:
	InputManager(PlayerMove& playerMove,Timer& timer, MapManager& mapManager, ItemManager& itemManager);
	void Input();
};