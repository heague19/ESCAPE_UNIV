
#include <vector>
#include <iostream>
#include <queue>
#include "Console.hpp"
#include "MapManager.hpp"
#include "PlayerMove.hpp"
#include "Timer.hpp"
#include "PartPos.hpp"
#include "GameOver.h"
using namespace std;
#define N 50
class AggresiveNPC
{
private:
	Console console;
	MapManager& mapManager;
	PlayerMove& playerMove;
	//이동 주기와 이동주기 체크용 타이머
	double moveRate = 0.5;
	double moveTimer = 0.0;
	Timer& timer;
	bool active=false;
	//경로 탐색용
	queue<COORD> bfs;
	vector<vector<int>> check;
	vector<vector<COORD>> from;
	//현재 위치
	COORD pos;
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };
public:
	AggresiveNPC(MapManager& mapManager,PlayerMove& playerMove,Timer& timer);
	//출력
	void ShowNPC();
	void DeleteNPC();
	//이동
	void NPCMove();
	//경로찾기
	COORD NPCPathFind();
	//충돌판정
	bool NPCDetectCollision(COORD nextPos);

	bool IsActive();
	void SetActive(bool active);
	void SetActive(bool active, COORD startPos);
};

