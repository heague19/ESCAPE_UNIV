#pragma once
#include<Windows.h>
class Timer
{
private:
	LARGE_INTEGER periodFrequency, lastTime, curTime;
	double timeScale;
	static double deltaTime;
public:
	Timer();
	//�� ƽ���� ����
	void Update();
	//DeltaTime ��ȯ
	static double GetDeltaTime();
};

