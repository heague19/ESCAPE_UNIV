#include "CursorColor.hpp"
void SelectCursorColor(int R, int G, int B)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RGB(R,G,B));// CursorColor 변경 함수입니다. 그냥 원하시는 색상표 확인하신 후 사용하시면 됩니다.

}
void InitCursorColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);// CursorColor 초기화 함수입니다.( 흰색) 
	// 다른 개발자를 위해 색상을 초기화 해주세요 구현후 맨 마지막에 넣어주시면 됩니다.
}