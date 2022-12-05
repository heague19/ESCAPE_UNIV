#pragma once
#include<windows.h>
#include "PlayerMove.hpp"
#include "Timer.hpp"
#include "GameOver.h"
#include "Inventory.hpp"
using namespace std;
/*
���� Ű �ڵ�
https://learn.microsoft.com/ko-kr/windows/win32/inputdev/virtual-key-codes
*/
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_P 0x50
#define VK_I 0x49
#define VK_Z 0x5A
class InputManager {
private:
	Timer& timer;
	PlayerMove& playerMove;
	MapManager& mapManager;
	ItemManager& itemManager;
	Inventory& inventory;
	bool flag_p = false;
	bool flag_i = false;
public:
	InputManager(PlayerMove& playerMove,Timer& timer, MapManager& mapManager, ItemManager& itemManager, Inventory& inventory);
	void Input();
};