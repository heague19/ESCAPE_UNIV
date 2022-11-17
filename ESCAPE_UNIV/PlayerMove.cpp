#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove(MapManager& mapManager) :Map(mapManager)
{
    pos.X = 11; pos.Y = 10; //ÄÜ¼Ö ÁÂÇ¥
    pox.X = pos.X - MAP_ORIGIN_X / 2;
    pox.Y = pos.Y - MAP_ORIGIN_Y;
    console.SetCurrentCursorPos(50, 30);
    
    ShowPlayer();
}
void PlayerMove::Move() {
    std::cout << pox.Y << pox.X;
    getkey();
}

void PlayerMove::down() {
    pox.Y++;
    if (!Map.CheckMap(pox)) {
        pox.Y--;
        return;
    }
    DeletePlayer();
    pos.Y++;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    pox.Y--;
    if (!Map.CheckMap(pox)) {
        pox.Y++;
        return;
    }
    DeletePlayer();
    pos.Y--;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    pox.X--;
    if (!Map.CheckMap(pox)) {
        pox.X++;
        return;
    }
    DeletePlayer();
    pos.X -= 1;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    pox.X++;
    if (!Map.CheckMap(pox)) {
        pox.X--;
        return;
    }
    DeletePlayer();
    pos.X += 1;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(curPos.X*2, curPos.Y);
    cout << "¨Ü";
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