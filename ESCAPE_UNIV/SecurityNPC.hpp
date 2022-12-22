#pragma once
#include"Timer.hpp"
#include"PlayerMove.hpp"
#include<vector>
#include"GameOver.h"
#include"GameTool.hpp"
class SecurityNPC {
	//현재 방향
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	//방향에 따른 아이콘
	string icon[4] = {"◁","▷","△","▽"};
	//활성 여부
	bool active = false;
	//위치
	COORD pos;
	PlayerMove& playerMove;
	MapManager& mapManager;
	Console console;
	//방향 전환 주기
	const double rotateRate = 3.0;
	double rotateTimer = 3.0;
	//현재 패턴
	int patternIdx = 0;
	//시야 사거리
	const int range = 10;
public:
	//방향
	enum Dir
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	}dir;

	//npc방향 전환 패턴(랜덤이 아닌 패턴 순서에 따라 주기적인 방향 변화)
	vector<Dir> pattern;

	SecurityNPC(int x, int y,PlayerMove&,MapManager&,bool active);
	//활성화/비활성화
	void SetActive(bool);
	//맵에 표시/제거
	void Show();
	void Delete();
	//방향 전환 등 매 틱마다 할 작업
	void Update();
	//플레이어 충돌 처리(한 줄만 체크)
	bool DetectCollision(COORD _pos);
	//플레이어 충돌 처리(세 줄 체크)
	bool DetectCollision();
	//방향 전환 패턴 추가
	void InsertPattern(Dir);
	bool IsActive();
};