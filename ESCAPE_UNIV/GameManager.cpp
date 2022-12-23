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
	/*
	itemManager.GetItem(4);
	itemManager.GetItem(15);
	itemManager.GetItem(14);
	itemManager.GetItem(3);
	itemManager.GetItem(6);
	itemManager.GetItem(7);
	itemManager.GetItem(4);
	*/
	//INTROPrint();
	//�������� ����(�� ������ ���ڰ� Ȱ��ȭ ����)
	//SecurityNPC securityNPC1(2,3,playermove,mapManager,false);
	//�������� ���� �߰�(����� ���� ������ ���� ��ȯ)
	//securityNPC1.InsertPattern(SecurityNPC::DOWN);
	//securityNPC1.InsertPattern(SecurityNPC::UP);
	//�������� ��Ȱ��ȭ
	//securityNPC1.SetActive(false);
	SecurityNPC securityNPC1(10, 15, playermove, mapManager, false);
	securityNPC1.InsertPattern(SecurityNPC::DOWN);
	securityNPC1.InsertPattern(SecurityNPC::LEFT);
	securityNPC1.InsertPattern(SecurityNPC::UP);
	securityNPC1.InsertPattern(SecurityNPC::RIGHT);
	
	SecurityNPC securityNPC2(31, 10, playermove, mapManager, false);
	securityNPC2.InsertPattern(SecurityNPC::DOWN);
	securityNPC2.InsertPattern(SecurityNPC::UP);
	securityNPC2.InsertPattern(SecurityNPC::LEFT);
	securityNPC2.InsertPattern(SecurityNPC::RIGHT);

	SecurityNPC securityNPC3(6, 20, playermove, mapManager, false);
	securityNPC3.InsertPattern(SecurityNPC::DOWN);
	securityNPC3.InsertPattern(SecurityNPC::UP);
	securityNPC3.InsertPattern(SecurityNPC::LEFT);
	securityNPC3.InsertPattern(SecurityNPC::RIGHT);

	SecurityNPC floor3NPC1(21, 7, playermove, mapManager, false);
	floor3NPC1.InsertPattern(SecurityNPC::LEFT);
	floor3NPC1.InsertPattern(SecurityNPC::UP);
	SecurityNPC floor3NPC2(29, 18, playermove, mapManager, false);
	floor3NPC2.InsertPattern(SecurityNPC::UP);
	floor3NPC2.InsertPattern(SecurityNPC::DOWN);
	int cnt = 0;
	BoxUI l(18, 20, 108, 3);
	int x = 1, y = 1;
	bool zzz = false;
	while (true) {	

		if (playermove.movenpc && !aggresiveNPC.IsActive()) {
			COORD p;
			if (mapManager.GetMapid() == 0) { p.X = 32; p.Y = 13; }
			if (mapManager.GetMapid() == 14) { p.X = 20; p.Y = 10; zzz = true; }
			aggresiveNPC.SetActive(true, p);
		}
		else if (!playermove.movenpc) aggresiveNPC.SetActive(false);

		if (mapManager.GetMapid() == 13 && zzz == true ) {
			COORD z = playermove.GetPos();
			if (z.X >3) {
				zzz = false;
				playermove.movenpc = true;
				COORD p;
				p.X = 1; p.Y = 2;
				aggresiveNPC.speed = 2;
				aggresiveNPC.SetActive(true, p);
			}
		}
		else if(!playermove.movenpc) aggresiveNPC.SetActive(false);


		if (mapManager.mapid == 2 && !securityative) {
			securityative = true;
			securityNPC1.SetActive(true, 10, 15);
			securityNPC2.SetActive(true, 31, 10);
		}
		else if (mapManager.mapid == 5 && !securityative)
		{
			securityative = true;
			securityNPC1.SetActive(true, 10, 6);
			securityNPC2.SetActive(true, 31, 12);
			securityNPC3.SetActive(true, 6, 20);
		}
		else if (mapManager.mapid != 2 && mapManager.mapid != 5) {
			securityative = false;
			securityNPC1.SetActive(false, 0, 0);
			securityNPC2.SetActive(false, 0, 0);
			securityNPC3.SetActive(false, 0, 0);
		}
		if (mapManager.mapid == 13 && !securityative) {
			securityative = true;
			floor3NPC1.SetActive(true, 21, 6);
			floor3NPC2.SetActive(true, 29, 18);
		}
		else if (mapManager.mapid != 13) {
			securityative = false;
			floor3NPC1.SetActive(false, 21, 7);
			floor3NPC2.SetActive(false, 29, 18);
		}


		if (itemManager.usesit) {
			playermove.Usestick();
		}
		COORD px = playermove.GetPos();
		int f = 1;
		


		if (mapManager.mapid == 17 && px.X < 35 && y==1) {
			for (int i = 0; i < 22; i++) {
				if (itemManager.FindItem(i)) {
					itemManager.DeleteItem(i);
					console.SetCurrentCursorPos(l.SInit_X + x, l.SInit_Y + y);
					cout << "                   ";
					y++;
				}
			}
			for (int i = 22; i < 27; i++) {
				itemManager.GetItem(i);
			}
			while (f) {
				ChatDialog::PrintMessage("������ �о��?                                     ```ENTER");
				inputManager.Input();
				if (inputManager.flg == true) {
					inputManager.flg = false;
					f = false;
				}

			}
		}

		if (mapManager.mapid == 17 && px.X < 25) {
			Sleep(100);
			inputManager.Input();

			if (inputManager.flg == true) {
				inputManager.flg = false;
				cnt++;
			}
			
			if (cnt == 1) {
				ChatDialog::PrintMessage("STAY....?    �̰� ����?                                  ```ENTER");
			}
			if (cnt == 2) {
				ChatDialog::PrintMessage("��ø� �ٵ� �� �и� 6���������� ���������ٵ� ���� 2���̶��? ```ENTER");
			}
			if (cnt == 3) {
				ChatDialog::PrintMessage("??? : ���̾� �� ���� �� ���� ���� �̷��� �ִ°Ŵ�?        ```ENTER");
			}
			if (cnt == 4) {
				ChatDialog::PrintMessage("??? : ���̾� ���� �Ͼ�� ���̾�!!!!!                     ```ENTER");
			}
			if (cnt == 4) {
				OutTro::OutTroPrint();
				Sleep(5000);
				
				break;
			}

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
		securityNPC2.Update();
		floor3NPC1.Update();
		floor3NPC2.Update();

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