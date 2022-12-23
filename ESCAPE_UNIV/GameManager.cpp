#include "GameManager.hpp"

using namespace std;
/*
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}*/
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
	aggresiveNPC.SetActive(false);
	ChatDialog::Init();// ���ڸ� �޾� �Ϲ������� ����� �� �ְ� ��������ϴ�. 
	ChatDialog::PrintMessage("Ahahahah");
	
	//itemManager.GetItem(4);
	itemManager.GetItem(19);
	//itemManager.GetItem(15);
	//itemManager.GetItem(14);
	/*
	* ������ �׽�Ʈ��
	itemManager.GetItem(3);
	itemManager.GetItem(6);
	itemManager.GetItem(7);
	itemManager.GetItem(4);*/

	//INTROPrint();
	//�������� ����(�� ������ ���ڰ� Ȱ��ȭ ����)
	//SecurityNPC securityNPC1(2,3,playermove,mapManager,false);
	//�������� ���� �߰�(����� ���� ������ ���� ��ȯ)
	//securityNPC1.InsertPattern(SecurityNPC::DOWN);
	//securityNPC1.InsertPattern(SecurityNPC::UP);
	//�������� ��Ȱ��ȭ
	//securityNPC1.SetActive(false);
	SecurityNPC securityNPC1(10, 15, playermove, mapManager, false);
	SecurityNPC securityNPC2(31, 10, playermove, mapManager, false);
	while (true) {
		if (playermove.movenpc && !aggresiveNPC.IsActive()) {
			COORD p;
			if(mapManager.GetMapid() == 0){p.X = 32;p.Y = 13;}
			
			aggresiveNPC.SetActive(true,p);
		}
		else if (!playermove.movenpc) aggresiveNPC.SetActive(false);

		if (mapManager.mapid == 2 && !securityative) {
			securityative = true;
			securityNPC1.SetActive(true,10,15);
			securityNPC1.InsertPattern(SecurityNPC::DOWN);
			securityNPC1.InsertPattern(SecurityNPC::LEFT);
			securityNPC1.InsertPattern(SecurityNPC::UP);
			securityNPC1.InsertPattern(SecurityNPC::RIGHT);

			securityNPC2.SetActive(true,31,10);
			securityNPC2.InsertPattern(SecurityNPC::DOWN);
			securityNPC2.InsertPattern(SecurityNPC::LEFT);
			securityNPC2.InsertPattern(SecurityNPC::UP);
			securityNPC2.InsertPattern(SecurityNPC::RIGHT);
		}
		else if(mapManager.mapid != 2){
			securityative = false;
			securityNPC1.SetActive(false,0,0);
			securityNPC2.SetActive(false,0,0);
		}
		if (itemManager.usesit) {
			playermove.Usestick();
		}

		
		//ChatDialog::PrintMessage(playermove.NPCPos.X + " " + playermove.NPCPos.Y);
		//playermove.Move();
		inputManager.Input();
		if (GameOver::Oflag)
			return;
		timer.Update();
		console.SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y);
		aggresiveNPC.NPCMove();
		securityNPC1.Update();
		if (GameOver::Oflag)return;
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