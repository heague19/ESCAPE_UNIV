#pragma once
#include <iostream>
#include <string>
#include<sstream>
#include "BoxUI.hpp"
#include "GameTool.hpp"
#include "PartPos.hpp"

using namespace std;
class ChatDialog {
public:
	ChatDialog();
	void Init();
	void PrintMessage(string msg);
};