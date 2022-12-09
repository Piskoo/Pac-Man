#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "GameStateType.h"

class GameState
{
protected:
	sf::RenderWindow* pGameWindow;
	sf::Event gameEvent;
public:
	GameState(sf::RenderWindow& _gameWindow);
	virtual ~GameState();
	virtual GameStateType processInputs() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};

