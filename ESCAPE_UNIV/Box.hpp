#pragma once
#include <iostream>
#include "Console.hpp"
#include <vector>
#include <string>
using namespace std;

class BoxUI
{
private:
	Console console;
	friend void AddContentsString(BoxUI &box, string content);
	friend void PrintText(BoxUI box);
	friend class Inventory;

	//Box DaTa
	int **Info;
	int width, height;
	int SInit_X, SInit_Y;
	string content;

public:
	friend class AddContent;
	BoxUI(int ,int ,int, int);
	void ConstructorBox();
	
};

