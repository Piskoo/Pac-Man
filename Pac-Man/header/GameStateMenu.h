#pragma once
#include "GameState.h"
#include "Menu.h"
class GameStateMenu : public GameState
{
	Menu* pMenu;
public:
	GameStateMenu(sf::RenderWindow& _gameWindow, Menu& _menu);
	virtual GameStateType processInputs() override;
	virtual void update() override;
	virtual void render() override;
};

