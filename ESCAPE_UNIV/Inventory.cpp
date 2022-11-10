#include "Inventory.hpp"
#include "Console.hpp"
using namespace std;
Console console;

void Inventory::Constructor_All_Init_Inventory()
{
    Constructor_Inventory_Boundary();
    Constructor_Item_List();
    Constructor_Player_State_HP_Bar();
    Constructor_Player_State_Stamina_Bar();
}

void Inventory:: Constructor_Inventory_Boundary()
{
    
    for (int x = 0; x < WIDTH + 2; x++)
    {
        Inventory_Board[HEIGTH+ 1][x] = 1;
        Inventory_Board[0][x] = 1;
    }// 위, 아래 테두리 가로줄 배열 1 정의

    for (int y = 0; y < HEIGTH + 2; y++)
    {
        for (int x = 0; x < WIDTH + 2; x++)
        {
            if (x == 0 || x == (WIDTH + 1))
                Inventory_Board[y][x] = 1;
        }
    }// 양옆 테두리 세로줄 배열 1 정의

    for (int y = 0; y < HEIGTH + 2; y++)
    {
        for (int x = 0; x < WIDTH + 2; x++)
        {// 해당 배열에 맞게 각 포인트멸로 문자 출력 
            console.SetCurrentCursorPos(INVENTORY_ORIGIN_X+ (x * 2), INVENTORY_ORIGIN_Y + y);
            if (y == 0 && x == 0)
                cout<<"┌";
            else if (y == 0 && x == WIDTH + 1)
                cout<<"┐";
            else if (y == HEIGTH + 1 && x == 0)
                cout<<"└";
            else if (y == HEIGTH + 1 && x == WIDTH + 1)
                cout<<"┘";
            else if (Inventory_Board[y][x] == 1 && !(y == HEIGTH + 1 || y == 0))
                cout<<"│"; 
            else if (Inventory_Board[y][x] == 1 && (y == HEIGTH + 1 || y == 0))
                cout<<"─"; 
        }
    }

    console.SetCurrentCursorPos(0, 0);
}

void Inventory:: Constructor_Item_List()
{
    for (int y = 1; y <= 8; y++)
    {
        for (int x = 1; x <= 16; x++)
        {
            console.SetCurrentCursorPos(INVENTORY_ORIGIN_X + (x * 2)+5, INVENTORY_ORIGIN_Y + (y*2) + GAP_Y+3+2); // 그 밑 줄 위에 글자를쓰기 위해 2칸씩 띄어 출력하게 만들었다.
            cout << "─";
        }
    }
}

void Inventory::Constructor_Player_State_HP_Bar()
{
    for (int i = 0; i < _HP; i++)
        HP[i] = 1; // HP 정보 배열에 초기 1값 정의

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 폰트 색깔 변경 함수
    console.SetCurrentCursorPos(INVENTORY_ORIGIN_X  + 2, INVENTORY_ORIGIN_Y + 1 + GAP_Y);
    cout << "HP     | ";
    
    for (int i = 0; i < _HP; i++)
    {    
        console.SetCurrentCursorPos(INVENTORY_ORIGIN_X + (i * 2) + GAP_X, INVENTORY_ORIGIN_Y + 1 + GAP_Y);
        if (HP[i] == 1)
            cout << "■";
    }
    
}

void Inventory::Constructor_Player_State_Stamina_Bar()
{
    for (int i = 0; i < _STAMINA; i++)
        Stamina[i] = 1; // 스태미나 정보 배열에 초기 1 값 정의

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //폰트 색깔 변경 함수
    console.SetCurrentCursorPos(INVENTORY_ORIGIN_X + 2, INVENTORY_ORIGIN_Y + 1 + GAP_Y + 2);
    cout << "STAMIN | ";

    for (int i = 0; i < _STAMINA; i++)
    {
        console.SetCurrentCursorPos(INVENTORY_ORIGIN_X + (i * 2) + GAP_X, INVENTORY_ORIGIN_Y + 1 + GAP_Y + 2);
        if(Stamina[i]==1)
            cout << "■";
    }
}
