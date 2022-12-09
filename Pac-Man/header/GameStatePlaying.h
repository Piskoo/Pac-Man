#pragma once
#include "GameState.h"
#include "Map.h"
#include "Hud.h"
#include "Player.h"
#include "GhostManager.h"

class GameStatePlaying : public GameState	
{
	Map* pMap;
	Hud* pHud;
	Player* pPlayer;
	GhostManager* pGhostManager;
	unsigned* pLifesCount;
	sf::Clock pauseClock;
	sf::Int32 pauseOrigin;
public:
	GameStatePlaying(sf::RenderWindow& _gameWindow, Map& _map, Hud& _hud, Player& _player, GhostManager& _ghostManager, unsigned& _lifesCount);
	void collectedAllDots();
	virtual GameStateType processInputs() override;
	virtual void update() override;
	virtual void render() override;
};

