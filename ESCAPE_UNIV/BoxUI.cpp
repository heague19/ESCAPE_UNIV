#include "BoxUI.hpp"
#include "Inventory.hpp"

using namespace std;

BoxUI::BoxUI(int w, int h, int X, int Y) 
{
    width = w;
    height = h;
    SInit_X = X;
    SInit_Y = Y;
    content = " ";

    // Box Info 배열 생성
    Info = new int *[height+2];
    for (int j = 0; j < height+2; j++)
        Info[j] = new int[width+2];

    // Box Info 배열 Data 저장
    for (int x = 0; x < width + 2; x++)
    {
    Info[height + 1][x] = 1;
    Info[0][x] = 1;
    }// 위, 아래 테두리 가로줄 배열 1 정의

    for (int y = 1; y < height + 1; y++)
    {
        for (int x = 0; x < width + 2; x++)
        {
            if (x == 0 || x == (width + 1))
                Info[y][x] = 1;
            else
                Info[y][x] = 0;
            
        }
    }// 양옆 테두리 세로줄 배열 1 정의
}

void BoxUI::ConstructorBox()
{
    console.SetCurrentCursorPos(SInit_X, SInit_Y);
    
    for (int y = 0; y < height + 2; y++)
    {
        for (int x = 0; x < width + 2; x++)
        {// 해당 배열에 맞게 각 포인트 별로 문자 출력 
            console.SetCurrentCursorPos(SInit_X + (x * 2), SInit_Y + y);
            if (y == 0 && x == 0)
                cout << "┌";
            else if (y == 0 && x == width + 1)
                cout << "┐";
            else if (y == height + 1 && x == 0)
                cout << "└";
            else if (y == height + 1 && x == width + 1)
                cout << "┘";
            else if (Info[y][x] == 1 && !(y == height + 1 || y == 0))
                cout << "│";
            else if (Info[y][x] == 1 && (y == height + 1 || y == 0))
                cout << "─";
        }
    }

    console.SetCurrentCursorPos(0, 0);
}

