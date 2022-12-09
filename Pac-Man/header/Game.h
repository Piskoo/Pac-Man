#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <string>
#include "Player.h"
#include "Map.h"
#include "Hud.h"
#include "Menu.h"
#include "Ladderboard.h"
#include "GameOver.h"
#include "Resources.h"
#include "GhostManager.h"
#include "GameStateLadderboard.h"
#include "GameStateLost.h"
#include "GameStateMenu.h"
#include "GameStatePlaying.h"
#include "GameState.h"
#include <map>
#include "GameStateLoading.h"

//dodac jthread albo cos innego

class Game
{
private:
	Resources resources;
	sf::VideoMode videoMode;
	std::shared_ptr<sf::RenderWindow> gameWindow;
	sf::Event gameEvent;

	std::map<GameStateType,std::unique_ptr<GameState>> gameStateMap;
	GameStateType currentState;

	unsigned currentScore;
	unsigned lifes;

	Map map;
	Player player;
	Hud hud;
	Menu menu;
	Ladderboard ladderboard;
	GameOver gameOver;
	GhostManager ghostManager;

	sf::String playerInput;

	sf::Clock frameTimeClock;
	float frameTime;

	void calculateFrameTime();
	void restartGameInitialValues();
	void update();
	void render();
public:
	Game();
	~Game() = default;
	void run();
};