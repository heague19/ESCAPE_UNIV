#pragma once
#include<Windows.h>
class Timer
{
private:
	LARGE_INTEGER periodFrequency, lastTime, curTime;
	double deltaTime,timeScale;
public:
	Timer();
	//�� ƽ���� ����
	void Update();
	//DeltaTime ��ȯ
	double GetDeltaTime();
};

