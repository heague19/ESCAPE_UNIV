#include "Console.hpp"
#include "MapManager.hpp"
#include "Inventory.hpp"
#include "ItemManager.hpp"
#include "PlayerMove.hpp"
#include "AggresiveNPC.hpp"
#include "Timer.hpp"
#include "ChatDialog.hpp"
#include "InputManager.hpp"
#include "GameOver.h"
#include "INTRO.h"
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
	MapManager mapManager;
	AggresiveNPC aggresiveNPC;
	Timer timer;
	InputManager inputManager;
};