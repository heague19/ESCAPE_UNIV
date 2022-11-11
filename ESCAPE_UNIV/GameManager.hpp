#pragma once
#include "Console.hpp"
#include "MapManager.hpp"
#include "Inventory.hpp"
#include "ItemManager.hpp"
#include "PlayerMove.hpp"


class GameManager {
public:
	static GameManager& Instance();
	GameManager();
	~GameManager() = default;
	void MainLoop();

	Console console;
	Inventory inventory;
	ItemManager itemManager;
	PlayerMove playermove;

};