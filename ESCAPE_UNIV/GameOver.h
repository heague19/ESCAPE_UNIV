#pragma once
#include "GameTool.hpp"
#include "PartPos.hpp"
#include <iostream>
using namespace std;
class GameOver {
public:
	GameOver();
	//게임 오버 여부
	static bool Oflag;
	static void GAMEOVERPrint();
	static void GAMEOVERrePrint();
};