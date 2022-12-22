#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove(MapManager& mapManager, ItemManager& itemManager)
    :Map(mapManager), itemmanager(itemManager)
{
    Setpos(6, 10);
}

int PlayerMove::ItemGetChecker(int dy, int dx) { // 인자는 지금 움직이려고 하는 방향
    int objectid = Map.GetMapAt(pox);
    if ((objectid - 1) / 100 == 1) {
        itemmanager.GetItem(objectid - 100);
        Map.ClearPos(pox);
        ChatDialog::PrintMessage(itemmanager.GetItemData(objectid - 100).name + "을(를) 얻었다.");
        if (objectid == 113) {
            movenpc = true;
        }
        return 1;
    }
    else if ((objectid - 1) / 100 >= 2) {
        // 문 충돌 검사 부분
        //가로문은 200이고 새로 문은 300대이기 때문에 200이면 그대로 가고 300이면 100을 추가로 더 빼준다.
        int id = objectid - 200;
        id = id < 100 ? id : id - 100;
        
        int beforemapId = Map.mapid;
        int mapId = Map.GetMapIdByRoomNumber(objectid % 100); // 다음 맵 아이디
        if (mapId >= 0) {
            movenpc = false;
            Map.ChangeMap(mapId);
            pox = Map.CalculateStartLocation(beforemapId, mapId, dy, dx);
        }
        else {
            if (!itemmanager.FindItem(id)) {
                ChatDialog::PrintMessage("문이 굳게 닫혀있다.");
                return 0;
            }
        }
        ChatDialog::PrintMessage("문이 열렸다.");
        return 1;
        
        //item.DeleteItem(id);
    }
}

void PlayerMove::down() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.Y++;
    if (Map.GetMapAt(pox) && !ItemGetChecker(1, 0)) {
        if (!MoveBox(pox.X, pox.Y, M_DOWN)) {
            pox.Y--;
            ShowPlayer();
            return;
        }
    }
    pos.Y++;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.Y--;
    if (Map.GetMapAt(pox) && !ItemGetChecker(-1, 0)) {
        if (!MoveBox(pox.X, pox.Y, M_UP)) {
            pox.Y++;
            ShowPlayer();
            return;
        }
    }
    pos.Y--;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.X--;
    if (Map.GetMapAt(pox) && !ItemGetChecker(0, -1)) {
        if (!MoveBox(pox.X, pox.Y, M_LEFT)) {
            pox.X++;
            ShowPlayer();
            return;
        }
    }
    pos.X -= 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.X++;
    if (Map.GetMapAt(pox) && !ItemGetChecker(0, 1)) {
        if (!MoveBox(pox.X, pox.Y, M_RIGHT)) {
            pox.X--;
            ShowPlayer();
            return;
        }
    }
    pos.X += 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    //ChatDialog::PrintMessage(to_string(pox.X) + ", " + to_string(pox.Y));
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
    printf("ⓟ");
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
};

void PlayerMove::DeletePlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
    cout << "  ";
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
}
/*
* inputManager로 기능 이전
void PlayerMove::getkey() {
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            auto key = _getch();
            ChatDialog::PrintMessage("");
            //아이템 사용 부분
            //다른 곳에서 입력 받으면 씹힐 가능성 있어서 여기 만듬
            //나중에 inputManager 만들어서 입력 거기서만 받는게 좋을듯
            if (key >= '1' && key <= '9')itemmanager.UseItem(key - '0');
            switch (key) {
            case 'w': up(); break;
            case 's': down(); break;
            case 'a': left(); break;
            case 'd': right(); break;
            case 'p': Map.ReBox(); Map.remap(); Map.DisplayMap(); break;
            //박스 지우고 맵 다시 불러오고 다시 그림
            // 이렇게 안하면 깜빡거리더라,,
            }
        }
    }
}
*/

/*int PlayerMove::DetectCollision(int x, int y) {
    COORD pos_;
    pos_.X = x;
    pos_.Y = y;
    if (!Map.CheckMap(pos_))
        return 1;
    return 0;
}*/
COORD PlayerMove::GetPos() {
    return pox;
}

int PlayerMove::MoveBox(int y, int x, Trans m) {

    auto mapdata = Map.GetMap();
    COORD BOX_POS;
    BOX_POS.X = x; BOX_POS.Y = y;

    int width = mapdata[0].size();
    int height = mapdata.size();
    /*
    if (pox.X >= width || pox.X < 0 || pox.Y >= height || pox.Y < 0) {
        return 0;
    }*/
    if (mapdata[x][y] == 100) { //박스 확인
        switch (m)
        {
        case M_DOWN:
            BOX_POS.X++; break;
        case M_UP:
            BOX_POS.X--; break;
        case M_LEFT: 
            BOX_POS.Y--; break;
        case M_RIGHT: 
            BOX_POS.Y++; break;
        }
        
        if (mapdata[BOX_POS.X][BOX_POS.Y]!=0  || BOX_POS.X >= height-1 || BOX_POS.X < 1 || BOX_POS.Y >= width-1|| BOX_POS.Y < 1 /* || (BOX_POS.X != npc.NPCPathFind().X && BOX_POS.Y != npc.NPCPathFind().Y)*/) {  //박스가 이동 가능한지 검사
            return 0;
        }
        if (BOX_POS.Y == NPCPos->X&&BOX_POS.X==NPCPos->Y)return 0;
        mapdata[BOX_POS.X][BOX_POS.Y] = 100; //박스 위치 변경
        mapdata[x][y] = 0;
        Map.SetMap(mapdata);
        Map.DisplayMap();
        //cout << "X="+BOX_POS.X <<"Y="+ BOX_POS.Y;
        return 1;
    }
    else {
        return 0;
    }
}

void PlayerMove::Setpos(int x, int y) {
    pos.X = x; pos.Y = y; //콘솔 좌표
    pox.X = pos.X - MAP_ORIGIN_X / 2;
    pox.Y = pos.Y - MAP_ORIGIN_Y;
    console.SetCurrentCursorPos(pox.X, pox.Y);
    ShowPlayer();
}