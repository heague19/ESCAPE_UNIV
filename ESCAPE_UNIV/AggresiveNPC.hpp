#pragma once
#include<vector>
#include<iostream>
#include "Console.hpp"
using namespace std;
class AggresiveNPC
{
private:
	Console console;


public:
	AggresiveNPC();
	COORD pos;
	void ShowNPC();
	void DeleteNPC();
	void NPCMove();
	COORD NPCPathFind();
	bool NPCDetectCollision(COORD nextPos);
};

