#pragma once
#include "GameState.h"
#include "Ladderboard.h"

class GameStateLadderboard : public GameState
{
	Ladderboard* pLadderboard;
public:
	GameStateLadderboard(sf::RenderWindow& _gameWindow, Ladderboard& _ladderboard);
	virtual GameStateType processInputs() override;
	virtual void update() override;
	virtual void render() override;
};


