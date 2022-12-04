#include "GameManager.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager()
	:aggresiveNPC(mapManager,playermove,timer)
	, itemManager(inventory),playermove(mapManager,itemManager),mapManager(itemManager)
	,inputManager(playermove,timer,mapManager,itemManager)
{
	mapManager.ChangeMap(mapManager.mapid);
}

void GameManager::MainLoop() {
	console.RemoveCursor();
	
	console.SetConsoleSize(150, 40);// cmd â ũ�� ���� �Լ� by �Լ� (��ȯ�� ��������� �������..) �ּ��� ����...
	inventory.Constructor_All_Init_Inventory();// ������ â ����
	
	mapManager.DisplayMap();
	//�� npc Ȱ��ȭ/��Ȱ��ȭ �Լ�
	aggresiveNPC.SetActive(true);
	ChatDialog::Init();// ���ڸ� �޾� �Ϲ������� ����� �� �ְ� ��������ϴ�. 
	ChatDialog::PrintMessage("Ahahahah");
	//itemManager.GetItem(2);
	while (true) {
		//ChatDialog::PrintMessage(playermove.NPCPos.X + " " + playermove.NPCPos.Y);
		//playermove.Move();
		inputManager.Input();
		timer.Update();
		console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y);
		aggresiveNPC.NPCMove();
	}// ���� ���� ���� �ڵ� ��
}