#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove(MapManager& mapManager) :Map(mapManager)
{
    pos.X = 10; pos.Y = 10; //콘솔 좌표
    pox.X = pos.X - MAP_ORIGIN_X / 2;
    pox.Y = pos.Y - MAP_ORIGIN_Y;
    console.SetCurrentCursorPos(50, 30);
    
    ShowPlayer();
}
void PlayerMove::Move() {
    getkey();
}

void PlayerMove::down() {
    pox.Y++;
    if (!Map.CheckMap(pox)) {
        if (!MoveBox(pox.X, pox.Y, M_DOWN)) {
            pox.Y--;
            return;
        }
    }
    DeletePlayer();
    pos.Y++;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    pox.Y--;
    if (!Map.CheckMap(pox)) {
        if (!MoveBox(pox.X, pox.Y, M_UP)) {
            pox.Y++;
            return;
        }
    }
    DeletePlayer();
    pos.Y--;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    pox.X--;
    if (!Map.CheckMap(pox)) {
        if (!MoveBox(pox.X, pox.Y, M_LEFT)) {
            pox.X++;
            return;
        }
    }
    DeletePlayer();
    pos.X -= 1;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    pox.X++;
    if (!Map.CheckMap(pox)) {
        if (!MoveBox(pox.X, pox.Y, M_RIGHT)) {
            pox.X--;
            return;
        }
    }
    DeletePlayer();
    pos.X += 1;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(curPos.X*2, curPos.Y);
    cout << "ⓟ";
    console.SetCurrentCursorPos(curPos.X*2, curPos.Y);
};

void PlayerMove::DeletePlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pos.X*2, pos.Y);
    cout << "  ";
    console.SetCurrentCursorPos(pos.X*2, pos.Y);
}

void PlayerMove::getkey() {
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            auto key = _getch();
            switch (key) {
            case 'w': up(); break;
            case 's': down(); break;
            case 'a': left(); break;
            case 'd': right(); break;
            }
        }
    }
}


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

//x,y는 박스의 위치 검사하기 위한 좌표
//vector 정신 나갈 것 같아 ~~
//참고로 박스 안밀림 *발
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
        
        if (mapdata[BOX_POS.X][BOX_POS.Y]!=0  || BOX_POS.X >= height-1 || BOX_POS.X < 1 || BOX_POS.Y >= width-1|| BOX_POS.Y < 1) {  //박스가 이동 가능한지 검사
            return 0;
        }
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