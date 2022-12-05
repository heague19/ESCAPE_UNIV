#include "GameManager.hpp"

using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager()
	:aggresiveNPC(mapManager,playermove,timer)
	, itemManager(inventory),playermove(mapManager,itemManager),mapManager(itemManager)
	,inputManager(playermove,timer,mapManager,itemManager,inventory)
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
	itemManager.GetItem(3);
	itemManager.GetItem(6);
	itemManager.GetItem(7);
	//INTROPrint();

	
	while (true) {
		//ChatDialog::PrintMessage(playermove.NPCPos.X + " " + playermove.NPCPos.Y);
		//playermove.Move();
		inputManager.Input();
		if (GameOver::flag)return;
		timer.Update();
		console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y);
		aggresiveNPC.NPCMove();
		if (GameOver::flag)return;
		/*
		if (Detect == 0) // �̷��� �ϸ� ��� �����ؼ� ����� ���ҽ��ϴ�. 
		{ //�ѹ������� �ϸ� ���� �������� ����, ��Ȯ�ϰԴ� INPUT Manger�� ����� �ٽ� �����ؾ� �ɰ� �� �⵵ �մϴ�. 
			GAMEOVERPrint();
			if (restart == 0)
				continue;
			else if (ending == 1)
				break;
			else if (re_main_menu == 2)
				re_main_menu = 1;
			break;
		}
		����۰����� ������ main���� ���൵ �� �� ����
		�й� �� MainLoop ����-> main���� �Է� ����->��쿡 ���� MainLoop�ٽ� ����
		*/
	}// ���� ���� ���� �ڵ� ��
	
}