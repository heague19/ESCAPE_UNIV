#include "Timer.hpp"
Timer::Timer():deltaTime(0.0),curTime()
{

    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
    //1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ� (������. �ý��� ���ý� ������)


    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
    // �������Լ��� Update()�Լ����� ������ ����Ǳ� ������ lastTime�� ����.

    timeScale = 1.0 / (double)periodFrequency.QuadPart;
    // �̸�  '1 / �ʴ�������'  �� ���·� ����� ���´�.
    // ��ǻ�ʹ� ���������꺸�� ���������� �� �����⶧���� �� �����Ӹ��� ������ �ؾ��Ұ�� 
    //������ �������� ���� ��궧 �����ϰ� �������°� ����.
}


void Timer::Update()
{
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime); // ���� ������ ������ ����.

    deltaTime = (double)(curTime.QuadPart - lastTime.QuadPart) * timeScale; // (���� ������ ������ - ���� ������ ������) * ( 1 / �ʴ������� )

    lastTime = curTime; // ���� �������� ���� ���������� ����. ���� ��� �ݺ�.
}

double Timer::GetDeltaTime() // �ʿ��Ѱ����� ������ ����.
{
    return deltaTime;
}