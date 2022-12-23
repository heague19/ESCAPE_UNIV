#pragma once
#include"Timer.hpp"
#include"PlayerMove.hpp"
#include<vector>
#include"GameOver.h"
#include"GameTool.hpp"
class SecurityNPC {
	//���� ����
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	//���⿡ ���� ������
	string icon[4] = {"��","��","��","��"};
	//Ȱ�� ����
	bool active = false;
	//��ġ
	COORD pos;
	PlayerMove& playerMove;
	MapManager& mapManager;
	Console console;
	//���� ��ȯ �ֱ�
	const double rotateRate = 3.0;
	double rotateTimer = 3.0;
	//���� ����
	int patternIdx = 0;
	//�þ� ��Ÿ�
	const int range = 10;
	//�� ����
	typedef enum ColorKinds {      //��������
		black, blue, green, skyBlue, red, pink, Orange, white, gray, lightBlue, brightGreen, sky, brightRed, brightPink, brightYellow, brightWhite
	}ColorKinds;
public:
	//����
	enum Dir
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	}dir;

	//npc���� ��ȯ ����(������ �ƴ� ���� ������ ���� �ֱ����� ���� ��ȭ)
	vector<Dir> pattern;

	SecurityNPC(int x, int y,PlayerMove&,MapManager&,bool active);
	//Ȱ��ȭ/��Ȱ��ȭ
	void SetActive(bool,int,int);
	//�ʿ� ǥ��/����
	void Show();
	void Delete();
	//���� ��ȯ �� �� ƽ���� �� �۾�
	void Update();
	//�÷��̾� �浹 ó��(�� �ٸ� üũ)
	bool DetectCollision(COORD _pos);
	//�÷��̾� �浹 ó��(�� �� üũ)
	bool DetectCollision();
	//���� ��ȯ ���� �߰�
	void InsertPattern(Dir);
	bool IsActive();
	void Colorset(int, int);
};