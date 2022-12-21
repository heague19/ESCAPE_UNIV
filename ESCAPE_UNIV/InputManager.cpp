#include "InputManager.hpp"
InputManager::InputManager(PlayerMove& playerMove, Timer& timer, MapManager& mapManager, ItemManager& itemManager, Inventory& inventory)
    :playerMove(playerMove), timer(timer), mapManager(mapManager), itemManager(itemManager), inventory(inventory) {

}
void InputManager::Input() {
    playerMove.moveTimer += timer.GetDeltaTime();
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        flag_in++;

    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        //flag_in--;
    }



    if (playerMove.moveTimer >= playerMove.moveRate) {
        if (GetAsyncKeyState(VK_W) & 0x8000) {
            playerMove.up();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_A) & 0x8000) {
            playerMove.left();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_S) & 0x8000) {
            playerMove.down();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_D) & 0x8000) {
            playerMove.right();
            playerMove.moveTimer = 0;
        }
        if (playerMove.GetPos().X == playerMove.NPCPos.X && playerMove.GetPos().Y == playerMove.NPCPos.Y)
            GameOver::GAMEOVERPrint();
    }

    for (int i = 0x31; i <= 0x39; i++)
        if (GetAsyncKeyState(i) & 0x8000)
            itemManager.UseItem(i - 0x30);

    //맵 리로딩
    if (GetAsyncKeyState(VK_P) & 0x8000) {
        if (!flag_p) {
            mapManager.ReBox();
            mapManager.remap();
            mapManager.DisplayMap();
        }
        flag_p = true;
    }
    else flag_p = false;

    //인벤토리 접근
    if (GetAsyncKeyState(VK_I) & 0x8000) {
        //종료 트리거
        int flag = 0;
        //선택 트리거
        bool flag_z=false;
        //선택된 아이템
        int select1 = 0, select2=-1;
        //입력 타이머
        double inputRate = 0.3;
        double inputTimer = inputRate;
        //아이템 출력용
        int itemSize = itemManager.items.size();
        BoxUI Item_List(ITEM_LIST_WIDTH, ITEM_LIST_HEIGHT, ITEM_LIST_ORIGIN_X + 2, ITEM_LIST_ORIGIN_Y);
        vector<string> datas;
        for (int i = 0; i < itemSize; i++)datas.push_back(itemManager.items[i].name);


        while (!flag_i)
        {
            //인벤토리 접근 종료
            if (flag == 0 && !(GetAsyncKeyState(VK_I) & 0x8000))flag++;
            if (flag == 1 && (GetAsyncKeyState(VK_I) & 0x8000))break;
            if (inputTimer >= inputRate) {
                //선택 위로
                if (GetAsyncKeyState(VK_W) & 0x8000) {
                    if (select2 == -1) {
                        select1--;
                        if (select1 < 0)select1 = 0;
                    }
                    else {
                        select2--;
                        if (select2 < 0)select2 = 0;
                    }
                    inputTimer = 0;
                }
                //선택 아래로
                if (GetAsyncKeyState(VK_S) & 0x8000) {
                    if (select2 == -1) {
                        select1++;
                        if (select1 >= itemSize)select1 = itemSize-1;
                    }
                    else {
                        select2++;
                        if (select2>= itemSize)select2 = itemSize-1;
                    }
                    inputTimer = 0;
                }
                //선택
                if (GetAsyncKeyState(VK_Z) & 0x8000) {
                    if (!flag_z) {
                        if (select2 == -1) {
                            select2 = select1;
                        }
                        else {
                            if (select1 == select2) {
                                itemManager.UseItem(select1+1);
                                break;
                            }
                            else {
                                itemManager.CombineItem(itemManager.items[select1].id,itemManager.items[select2].id);
                                datas.clear();
                                for (int i = 0; i < itemManager.items.size(); i++)datas.push_back(itemManager.items[i].name);
                                inventory.Print_Item_List(Item_List, datas);
                                return;
                            }
                        }
                    }
                    flag_z = true;
                }
                else flag_z = false;
            }
            else inputTimer += timer.GetDeltaTime();
            timer.Update();
            inventory.Print_Item_List(Item_List, datas,select1,select2);

        }

        inventory.Print_Item_List(Item_List, datas);
        flag_i = true;
    }
    else flag_i = false;

}