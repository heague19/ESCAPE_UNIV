#include "Inventory.hpp"
using namespace std;
Console console;
vector<string> vector_s;
void Inventory::Constructor_All_Init_Inventory()
{
    Constructor_Inventory_Boundary();
    Constructor_Item_List();
    Constructor_Explainer();
}

void Inventory:: Constructor_Inventory_Boundary()
{
    BoxUI Main_Inventory(INVENTORY_WIDTH,	 INVENTORY_HEIGTH,	 INVENTORY_ORIGIN_X,	 INVENTORY_ORIGIN_Y);
    Main_Inventory.ConstructorBox();
}

void Inventory:: Constructor_Item_List()
{
    SelectCursorColor(DARK_GREEN);// 폰트 색상 변경함수 
    BoxUI Item_List(ITEM_LIST_WIDTH,	ITEM_LIST_HEIGHT,	ITEM_LIST_ORIGIN_X,	ITEM_LIST_ORIGIN_Y); 
    Item_List.ConstructorBox();
    InitCursorColor();// 폰트 색상 초기화 함수

    Print_Item_List(Item_List,	vector_s); // 벡터 함수 리스트 출력 함수
    //vector_s에 필요한 Vector<string> 변수 넣으면 됨
    
}

void Inventory::Constructor_Explainer()
{
    BoxUI ExplainerBox(EXPLAINER_WIDTH,	EXPLAINER_HEIGHT,	EXPLAINER_ORIGIN_X,	EXPLAINER_ORIGIN_Y);
    ExplainerBox.ConstructorBox();
    ExplainerBox.Print("W : ↑ A : ← S : ↓ D : →\n I: 인벤토리 열기 Z : 아이템 선택\n\n※아이템 조합 방법\n조합하고자 하는 아이템 두개를 \n차례로 선택하면 된다 ");
    Constructor_Exit(false);
}
void Inventory::Constructor_Exit(bool flag) {
    if (!flag)
        SelectCursorColor(DARK_BLUE);
    else
        SelectCursorColor(GREEN);

    BoxUI EXIT(EXIT_WIDTH / 2,	 EXIT_HEIGHT / 2,	 EXIT_ORIGIN_X+ (EXIT_WIDTH)+12,	 EXIT_ORIGIN_Y + 6);
    EXIT.ConstructorBox();
    EXIT.Print("EXIT");
    InitCursorColor();
}
void Inventory::Print_Item_List(BoxUI &List,	vector<string> Item)
{
    Console console;
    int x=1,	 y=1;
    if (Item.empty()) // 벡터 존재 확인 여부 함수
        return;
    else
    {
        
        for (int i = 0; i < Item.size(); i++)
        {
            console.SetCurrentCursorPos(List.SInit_X + x,	 List.SInit_Y + y);
            if (Item[i]=="5층 남자 화장실 열쇠") {
                cout << i + 1 << ". " << Item[i];
            }
            else { cout << i + 1 << ". " << Item[i] << "               "; }// Info를 알고 있다는 가정하에 각 네모 박스안 리스트 출력
            y++;
        }
        console.SetCurrentCursorPos(List.SInit_X + x,	 List.SInit_Y + y);
        cout << "                   ";
    }
}
void Inventory::Print_Item_List(BoxUI& List,	 vector<string> Item,	 int select1,	 int select2)
{
    Console console;
    int x = 1,	 y = 1;
    if (Item.empty()) // 벡터 존재 확인 여부 함수
        return;
    else
    {
        for (int i = 0; i < Item.size(); i++)
        {
            console.SetCurrentCursorPos(List.SInit_X + x,	 List.SInit_Y + y);
            if (select1 == i)SelectCursorColor(GREEN);
            if (select2 == i)SelectCursorColor(RED);
            cout << i + 1 << ". " << Item[i];// Info를 알고 있다는 가정하에 각 네모 박스안 리스트 출력
            y++;
            InitCursorColor();
        }
    }
}
