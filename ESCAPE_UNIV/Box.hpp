#pragma once
#include <iostream>
#include "Console.hpp"
#include <vector>
#include <string>
using namespace std;

class Box
{
private:
	Console console;
	friend void AddContentsString(Box &box, string content);
	friend void PrintContentsString(Box box);
	friend class Inventory;

	//Box DaTa
	int **Info;
	int width, height;
	int SInit_X, SInit_Y;
	string content;

public:
	friend class AddContent;
	Box(int ,int ,int, int);
	void ConstructorBox();
	
};

