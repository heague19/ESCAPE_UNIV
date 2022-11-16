#pragma once
#include <iostream>
#include "Console.hpp"
class Box
{
private:
	Console console;
	
	//Box DaTa
	int **Info;
	int width, height;
	int SInit_X, SInit_Y;

public:
	Box(int ,int ,int, int);
	void ConstructorBox();
};

