#pragma once
#include <iostream>
#include <string>
#include<sstream>
#include "GameTool.hpp"
#include "PartPos.hpp"

using namespace std;
class ChatDialog {
public:
	
	ChatDialog();
	static void Init();
	static void PrintMessage(string msg);
};