#pragma once
#include "GameTool.hpp"
#include "PartPos.hpp"
#include <iostream>
using namespace std;
class GameOver {
public:
	GameOver();
	//���� ���� ����
	static bool Oflag;
	static void GAMEOVERPrint();
	static void GAMEOVERrePrint();
};