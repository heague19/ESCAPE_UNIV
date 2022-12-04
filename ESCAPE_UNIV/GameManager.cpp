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
	
	console.SetConsoleSize(150, 40);// cmd 창 크기 고정 함수 by 함수 (정환아 만들었으면 얘기해줘..) 주석을 써줘...
	inventory.Constructor_All_Init_Inventory();// 아이템 창 구현
	
	mapManager.DisplayMap();
	//적 npc 활성화/비활성화 함수
	aggresiveNPC.SetActive(true);
	ChatDialog::Init();// 인자를 받아 일반적으로 사용할 수 있게 만들었습니다. 
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
		if (Detect == 0) // 이렇게 하면 어떨까 생각해서 만들어 보았습니다. 
		{ //넘버링으로 하면 되지 않을까라는 생각, 정확하게는 INPUT Manger를 만들고 다시 생각해야 될것 같 기도 합니다. 
			GAMEOVERPrint();
			if (restart == 0)
				continue;
			else if (ending == 1)
				break;
			else if (re_main_menu == 2)
				re_main_menu = 1;
			break;
		}
		재시작같은거 선택은 main에서 해줘도 될 것 같음
		패배 시 MainLoop 종료-> main에서 입력 받음->경우에 따라 MainLoop다시 실행
		*/
	}// 게임 구성 실행 코드 현
	
}