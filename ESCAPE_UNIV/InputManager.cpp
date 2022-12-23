#include "InputManager.hpp"
InputManager::InputManager(PlayerMove& playerMove,	 Timer& timer,	 MapManager& mapManager,	 ItemManager& itemManager,	 Inventory& inventory)
    :playerMove(playerMove),	 timer(timer),	 mapManager(mapManager),	 itemManager(itemManager),	 inventory(inventory) {

}
void InputManager::Input() {
    
    playerMove.moveTimer += timer.GetDeltaTime();
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        flag_in++;
        cmt++;

    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
     //   flag_in--;
        cmt++;
    }



    if (playerMove.moveTimer >= playerMove.moveRate) {
        if (GetAsyncKeyState(VK_W) & 0x8000) {
            playerMove.up();
            playerMove.moveTimer = 0;
            cmt++;
        }
        if (GetAsyncKeyState(VK_A) & 0x8000) {
            playerMove.left();
            playerMove.moveTimer = 0;
            cmt++;
        }
        if (GetAsyncKeyState(VK_S) & 0x8000) {
            playerMove.down();
            playerMove.moveTimer = 0;
            cmt++;
        }
        if (GetAsyncKeyState(VK_D) & 0x8000) {
            playerMove.right();
            playerMove.moveTimer = 0;
            cmt++;
        }
        if (playerMove.GetPos().X == playerMove.NPCPos->X && playerMove.GetPos().Y == playerMove.NPCPos->Y)
            GameOver::GAMEOVERPrint();
    }

    for (int i = 0x31; i <= 0x39; i++)
        if (GetAsyncKeyState(i) & 0x8000)
        {
            cmt++;
            itemManager.UseItem(i - 0x30);
        }

    //맵 리로딩
    if (GetAsyncKeyState(VK_P) & 0x8000) {
        cmt++;
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
        cmt++;
        //종료 트리거
        int flag = 0;
        //선택 트리거
        bool flag_z=false;
        //선택된 아이템
        int select1 = 0,	 select2=-1;
        //입력 타이머
        double inputRate = 0.3;
        double inputTimer = inputRate;
        //아이템 출력용
        int itemSize = itemManager.items.size();
        BoxUI Item_List(ITEM_LIST_WIDTH,	 ITEM_LIST_HEIGHT,	 ITEM_LIST_ORIGIN_X + 2,	 ITEM_LIST_ORIGIN_Y);
        vector<string> datas;
        for (int i = 0; i < itemSize; i++)datas.push_back(itemManager.items[i].name);


        while (!flag_i)
        {
            //인벤토리 접근 종료
            if (flag == 0 && !(GetAsyncKeyState(VK_I) & 0x8000)) { flag++; cmt++; }
            if (flag == 1 && (GetAsyncKeyState(VK_I) & 0x8000)) { cmt++; break; }
            if (inputTimer >= inputRate) {
                //선택 위로
                if (GetAsyncKeyState(VK_W) & 0x8000) {
                    cmt++;
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
                    cmt++;
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
                    cmt++;
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
                                itemManager.CombineItem(itemManager.items[select1].id,	itemManager.items[select2].id);
                                datas.clear();
                                for (int i = 0; i < itemManager.items.size(); i++)datas.push_back(itemManager.items[i].name);
                                inventory.Print_Item_List(Item_List,	 datas);
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
            inventory.Print_Item_List(Item_List,	 datas,	select1,	select2);

        }

        inventory.Print_Item_List(Item_List,	 datas);
        flag_i = true;
    }
    else flag_i = false;

    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        cmt++;
        if (!flag_esc) {
            int flag = 0;
            inventory.Constructor_Exit(true);
            while (1)
            {
                if (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && flag == 0){flag = 1; cmt++;}
                if (flag == 1 && (GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
                    cmt++;
                    inventory.Constructor_Exit(false);
                    break;
                }
                if (GetAsyncKeyState(VK_Z) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_RETURN) & 0x8000) { cmt++; exit(0); }
            }
        }
        flag_esc = true;
    }
    else flag_esc = false;

    if (mapManager.mapid == 17 && GetAsyncKeyState(VK_RETURN)) {
        cmt++;
        flg = true;
    }
}