#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "Console.hpp"
#include "MapManager.hpp"
#include "PlayerMove.hpp"
#include "Timer.hpp"
#include "PartPos.hpp"
using namespace std;
#define N 50
class AggresiveNPC
{
private:
	Console console;
	MapManager& mapManager;
	PlayerMove& playerMove;
	//�̵� �ֱ�� �̵��ֱ� üũ�� Ÿ�̸�
	double moveRate = 0.5;
	double moveTimer = 0.0;
	Timer& timer;

	//��� Ž����
	queue<COORD> bfs;
	vector<vector<int>> check;
	vector<vector<COORD>> from;
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };
public:
	AggresiveNPC(MapManager& mapManager,PlayerMove& playerMove,Timer& timer);
	//���� ��ġ
	COORD pos;
	//���
	void ShowNPC();
	void DeleteNPC();
	//�̵�
	void NPCMove();
	//���ã��
	COORD NPCPathFind();
	//�浹����
	bool NPCDetectCollision(COORD nextPos);
};
