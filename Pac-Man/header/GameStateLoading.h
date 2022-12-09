#pragma once
#include "GameState.h"
class GameStateLoading : public GameState
{
	sf::Clock clock;
	const sf::Int32 loadingTime = 1500;
public:

	GameStateLoading(sf::RenderWindow& _gameWindow);
	virtual GameStateType processInputs() override;
	virtual void update() override;
	virtual void render() override;
};

