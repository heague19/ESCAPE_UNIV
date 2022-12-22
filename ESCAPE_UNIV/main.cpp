#include <iostream>
#include "GameManager.hpp"
#include "GameOver.h"
#include "InputManager.hpp"
#include "INTRO.h"

using namespace std;
int main() {
	Console console;
	console.SetConsoleSize(150, 40);


	bool reflag = false;
	int selectflag = 0;

	while (true) {


		try {
			GameManager::Instance().MainLoop();
		}
		catch (const char* str) {
			cout << str;
			getchar();
		}




		GameOver::GAMEOVERPrint();
		bool flag_down = false, flag_up = false;
		selectflag = 0;
		reflag = true;
		while (true)
		{
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (!flag_down) {
					selectflag++;
					if (selectflag > 2)
						selectflag = 0;
					reflag = true;
				}
				flag_down = true;
			}
			else flag_down = false;

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				if (!flag_up) {
					selectflag--;
					if (selectflag < 0)
						selectflag = 2;
					reflag = true;
				}
				flag_up = true;
			}
			else flag_up = false;
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				if (selectflag == 0) {
					break;
				}
				else if (selectflag == 1) {
					return 0;
				}
				else if (selectflag == 2) {
					return 0;
				}
			}
			if (reflag) {
				if (selectflag == 2)
				{
					SelectCursorColor(GREEN);
				}
				else SelectCursorColor(WHITE);
				BoxUI ENDING_EXIT(17, 5, 108, 29);
				ENDING_EXIT.ConstructorBox();
				ENDING_EXIT.Print("\n\n\             종료하기");

				if (selectflag == 1)
				{
					SelectCursorColor(GREEN);
				}
				else SelectCursorColor(WHITE);
				BoxUI RE_MENU(17, 5, 108, 16);
				RE_MENU.ConstructorBox();
				RE_MENU.Print("\n\n\          메뉴로 돌아가기");

				if (selectflag == 0)
				{
					SelectCursorColor(GREEN);
				}
				else SelectCursorColor(WHITE);
				BoxUI RE_START(17, 5, 108, 3);
				RE_START.ConstructorBox();
				RE_START.Print("\n\n\              재시작");
				reflag = false;

			}

		}
	}
	return 0;
}