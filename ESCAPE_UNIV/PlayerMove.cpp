#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove()
{
    pos.X = 10; pos.Y = 10;
    ShowPlayer();
}
void PlayerMove::Move() {
    getkey();
}

void PlayerMove::down() {
    if (!DetectCollision(pos.X, pos.Y+1)) {
        return;
    }
    DeletePlayer();
    pos.Y++;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    if (!DetectCollision(pos.X, pos.Y-1)) {
        return;
    }
    DeletePlayer();
    pos.Y--;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    if (!DetectCollision(pos.X-1, pos.Y)) {
        return;
    }
    DeletePlayer();
    pos.X -= 1;
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    if (!DetectCollision(pos.X+1, pos.Y)) {
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


bool PlayerMove::DetectCollision(int x, int y) {
    
    int arrx = pos.X-MAP_ORIGIN_X/2;
    int arry = pos.Y-MAP_ORIGIN_Y;
    
    return 1;
}
COORD PlayerMove::GetPos() {
    COORD pos_;
    pos_.X = pos.X-MAP_ORIGIN_X/2;
    pos_.Y = pos.Y-MAP_ORIGIN_Y;
    return pos_;
}