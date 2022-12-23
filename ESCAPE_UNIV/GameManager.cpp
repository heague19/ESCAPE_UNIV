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
	
	console.SetConsoleSize(150, 40);// cmd 창 크기 고정 함수 by 함수 (정환아 만들었으면 얘기해줘..) 주석을 써줘...
	inventory.Constructor_All_Init_Inventory();// 아이템 창 구현
	
	mapManager.DisplayMap();
	//적 npc 활성화/비활성화 함수
	aggresiveNPC.SetActive(false);
	ChatDialog::Init();// 인자를 받아 일반적으로 사용할 수 있게 만들었습니다. 
	ChatDialog::PrintMessage("Ahahahah");
	
	//itemManager.GetItem(4);
	itemManager.GetItem(19);
	//itemManager.GetItem(15);
	//itemManager.GetItem(14);
	/*
	* 아이템 테스트용
	itemManager.GetItem(3);
	itemManager.GetItem(6);
	itemManager.GetItem(7);
	itemManager.GetItem(4);*/

	//INTROPrint();
	//경비아저씨 생성(맨 마지막 인자가 활성화 여부)
	//SecurityNPC securityNPC1(2,3,playermove,mapManager,false);
	//경비아저씨 패턴 추가(저장된 패턴 순서로 방향 전환)
	//securityNPC1.InsertPattern(SecurityNPC::DOWN);
	//securityNPC1.InsertPattern(SecurityNPC::UP);
	//경비아저씨 비활성화
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