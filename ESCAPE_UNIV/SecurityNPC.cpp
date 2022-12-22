#include "SecurityNPC.hpp"


SecurityNPC::SecurityNPC(int x, int y, PlayerMove& playerMove,MapManager& mapManager, bool active) 
	:dir(LEFT), playerMove(playerMove),mapManager(mapManager), active(active) {
	pos.X = x;
	pos.Y = y;
	if(active)
		Show();
}
void SecurityNPC::SetActive(bool flag, int x, int y) {
	active = flag;
	if (!active) { pos.X = -1; pos.Y = -1; Delete(); }
	else {pos.X = x; pos.Y = y; Show();}
}
void SecurityNPC::Show() {
	if (!active)return;
	console.SetCurrentCursorPos(pos.X * 2 + MAP_ORIGIN_X, pos.Y + MAP_ORIGIN_Y);
	cout << icon[dir];
}
void SecurityNPC::Delete() {
	console.SetCurrentCursorPos(pos.X * 2 + MAP_ORIGIN_X, pos.Y + MAP_ORIGIN_Y);
	cout << "  ";
}
void SecurityNPC::Update() {
	if (!active)return;
	rotateTimer += Timer::GetDeltaTime();
	if (rotateTimer >= rotateRate&& !pattern.empty()) {
		rotateTimer = 0;
		patternIdx = (patternIdx + 1) % pattern.size();
		dir = pattern[patternIdx];
		Show();
	}
	if (DetectCollision())GameOver::GAMEOVERPrint();
}
bool SecurityNPC::DetectCollision(COORD _pos) {
	for (int i = 0; i < range; i++) {
		if (GameTool::Compare(_pos,playerMove.GetPos()))return true;
		if (!mapManager.CheckMap(_pos))break;
		_pos.X += dx[dir];
		_pos.Y += dy[dir];
	}
	return false;
}
bool SecurityNPC::DetectCollision() {
	//중앙부분 체크
	if(DetectCollision(pos))return true;
	//양쪽부분 체크
	/*
	if (dx[dir] == 0) {
		COORD _pos = pos;
		_pos.X--;
		if (DetectCollision(_pos))return true;
		_pos = pos;
		_pos.X++;
		if (DetectCollision(_pos))return true;
	}
	else {
		COORD _pos = pos;
		_pos.Y--;
		if (DetectCollision(_pos))return true;
		_pos = pos;
		_pos.Y++;
		if (DetectCollision(_pos))return true;
	}
	*/
	return false;
}
void SecurityNPC::InsertPattern(Dir dir) {
	pattern.push_back(dir);
}

bool SecurityNPC::IsActive() {
	return active;
}