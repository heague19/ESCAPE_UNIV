#include"GameTool.hpp"
bool GameTool::Compare(COORD a, COORD b) {
	if (a.X == b.X && a.Y == b.Y)return true;
	return false;
}