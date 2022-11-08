#include "GameManager.hpp"
using namespace std;
GameManager& GameManager::Instance() {
	static GameManager instance;
	return instance;
}
GameManager::GameManager() {

}
void GameManager::MainLoop() {
	Console console;
	console.RemoveCursor();
	console.SetConsoleSize(150, 40);
	while (true) {

	}
}