#pragma once
#include <iostream>
#include <sstream>
#include "Console.hpp"
#include <vector>
#include <string>
using namespace std;

class BoxUI
{
public:
	Console console;
	friend void AddContentsString(BoxUI &box, string content);
	friend void PrintText(BoxUI box);
	friend class Inventory;

	//Box DaTa
	int **Info;
	int width, height;
	int SInit_X, SInit_Y;
	vector<vector<int>> Map_Info;

public:
	friend class AddContent;
	BoxUI();
	BoxUI(int width ,int height ,int start_X, int start_Y);
	void ConstructorBox();
	void Print(string content);
	void VectorBoxUI(int width, int height, int start_X, int start_Y);
	
};

