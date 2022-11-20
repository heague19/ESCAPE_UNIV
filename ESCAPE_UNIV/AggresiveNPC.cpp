#include "AggresiveNPC.hpp"
AggresiveNPC::AggresiveNPC(MapManager& mapManager, PlayerMove& playerMove, Timer& timer)
	:mapManager(mapManager),playerMove(playerMove),timer(timer) {
	pos.X = 1;
	pos.Y = 1;
	check.resize(N);
	for (int i = 0; i < N; i++)check[i].resize(N);
	from.resize(N);
	for (int i = 0; i < N; i++)from[i].resize(N);
}
void AggresiveNPC::ShowNPC() {
	console.SetCurrentCursorPos(pos.X*2+MAP_ORIGIN_X, pos.Y + MAP_ORIGIN_Y);
	cout << "จั";
}
void AggresiveNPC::DeleteNPC() {
	console.SetCurrentCursorPos(pos.X*2 + MAP_ORIGIN_X, pos.Y + MAP_ORIGIN_Y);
	cout << "  ";
}
void AggresiveNPC::NPCMove(){
	//console.SetCurrentCursorPos(0, 0);
	//cout << playerMove.GetPos().X << " " << playerMove.GetPos().Y << "  ";
	//console.SetCurrentCursorPos(0, 1);
	//cout << pos.X << " " << pos.Y << "  ";

	moveTimer += timer.GetDeltaTime();
	if (moveTimer < moveRate)return;
	moveTimer = 0.0;
	COORD nextPos = NPCPathFind();
	if(!NPCDetectCollision(nextPos))return;
	DeleteNPC();
	pos = nextPos;
	ShowNPC();
}
COORD AggresiveNPC::NPCPathFind() {
	queue<COORD> empty;
	swap(bfs, empty);
	fill(check.begin(), check.end(), vector<int>(N));
	fill(from.begin(), from.end(), vector<COORD>(N));

	bfs.push(pos);
	check[pos.X][pos.Y] = 1;
	bool flag = false;
	string str("");
	while (!bfs.empty())
	{
		COORD data = bfs.front();
		bfs.pop();
		if (data.X == playerMove.GetPos().X&& data.Y == playerMove.GetPos().Y) {
			flag = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			COORD newData;
			newData.X = data.X + dx[i];
			newData.Y = data.Y + dy[i];
			if (!mapManager.CheckMap(newData))continue;
			if (check[newData.X][newData.Y] != 0)continue;
			check[newData.X][newData.Y] = check[data.X][data.Y] + 1;
			from[newData.X][newData.Y] = data;
			bfs.push(newData);
		}
	}
	if (flag) {
		COORD nextPos = playerMove.GetPos();
		while (from[nextPos.X][nextPos.Y].X != pos.X || from[nextPos.X][nextPos.Y].Y != pos.Y)
		{
			if (nextPos.X == from[nextPos.X][nextPos.Y].X && nextPos.Y == from[nextPos.X][nextPos.Y].Y)return pos;
			nextPos = from[nextPos.X][nextPos.Y];
		}
		return nextPos;
	}
	return pos;
}
bool AggresiveNPC::NPCDetectCollision(COORD nextPos) {
	return true;
}