#pragma once
#include <iostream>
#include "Console.hpp"
#include <vector>
#include <string>
using namespace std;

class Box
{
public:
	Console console;
	friend void AddContentsString(Box &box, string content);
	friend void PrintText(Box box);
	
	//Box DaTa
	int **Info;
	int width, height;
	int SInit_X, SInit_Y;
	string content;

public:
	friend class AddContent;
	Box(int width ,int height ,int start_X, int start_Y);
	void ConstructorBox();
	
};

