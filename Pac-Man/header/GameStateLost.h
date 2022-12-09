#pragma once
#include "GameState.h"
#include "GameOver.h"

class GameStateLost : public GameState
{
	GameOver* pGameOver;
	Ladderboard* pLadderboard;
	sf::String* pPlayerInput;
	unsigned* pCurrentScore;
public:
	GameStateLost(sf::RenderWindow& _gameWindow, GameOver& _gameOver, Ladderboard& _ladderboard, sf::String& _playerInput, unsigned& _currentScore);
	virtual GameStateType processInputs() override;
	virtual void update() override;
	virtual void render() override;
};

