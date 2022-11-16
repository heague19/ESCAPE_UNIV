#pragma once
#include<Windows.h>
class Timer
{
private:
	LARGE_INTEGER periodFrequency, lastTime, curTime;
	double deltaTime,timeScale;
public:
	Timer();
	//매 틱마다 실행
	void Update();
	//DeltaTime 반환
	double GetDeltaTime();
};

