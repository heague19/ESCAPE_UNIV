#include "CursorColor.hpp"
void SelectCursorColor(int Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Color );// CursorColor ���� �Լ��Դϴ�. �׳� ���Ͻô� ����ǥ Ȯ���Ͻ� �� ����Ͻø� �˴ϴ�.

}
void InitCursorColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);// CursorColor �ʱ�ȭ �Լ��Դϴ�.( ���) 
	// �ٸ� �����ڸ� ���� ������ �ʱ�ȭ ���ּ��� ������ �� �������� �־��ֽø� �˴ϴ�.
}