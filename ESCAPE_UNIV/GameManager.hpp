#pragma once
#include "Console.hpp"
#include "MapManager.hpp"
class GameManager {
public:
	static GameManager& Instance();
	GameManager();
	~GameManager() = default;
	void MainLoop();
};