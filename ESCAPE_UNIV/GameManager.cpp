#include "GameManager.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager()
	:aggresiveNPC(mapManager,playermove,timer)
	, itemManager(inventory),playermove(mapManager,itemManager)
{
	mapManager.ChangeMap(0);
}
void GameManager::MainLoop() {
	console.RemoveCursor();
	
	console.SetConsoleSize(150, 40);// cmd â ũ�� ���� �Լ� by �Լ� (��ȯ�� ��������� �������..) �ּ��� ����...
	inventory.Constructor_All_Init_Inventory();// ������ â ����
	
	mapManager.DisplayMap();
	
	ChatDialog::Init();// ���ڸ� �޾� �Ϲ������� ����� �� �ְ� ��������ϴ�. 
	ChatDialog::PrintMessage("Ahahahah");
	
	while (true) {
		playermove.Move();
		timer.Update();
		console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y);
		aggresiveNPC.NPCMove();
	}// ���� ���� ���� �ڵ� ��
}