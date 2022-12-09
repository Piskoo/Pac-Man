#include "Game.h"

Game::Game() : resources(Resources()),
	videoMode(sf::VideoMode(resources.windowWidth, resources.windowHeight)),
	gameWindow(std::make_shared<sf::RenderWindow>()),
	gameEvent(),
	currentScore(0),
	lifes(resources.noOfLifes),
	playerInput(""),
	map(resources),
	player(resources, map, currentScore, frameTime),
	hud(resources, ladderboard, currentScore, lifes),
	menu(resources, frameTime),
	ladderboard(resources),
	gameOver(resources, ladderboard, playerInput, currentScore),
	ghostManager(resources, map, player, frameTime, lifes, currentScore),
	currentState(GameStateType::Loading)
{
	gameStateMap.insert(std::pair(GameStateType::Menu, std::make_unique<GameStateMenu>(*gameWindow, menu)));
	gameStateMap.insert(std::pair(GameStateType::Ladderboard, std::make_unique<GameStateLadderboard>(*gameWindow, ladderboard)));
	gameStateMap.insert(std::pair(GameStateType::Playing, std::make_unique<GameStatePlaying>(*gameWindow, map, hud, player, ghostManager, lifes)));
	gameStateMap.insert(std::pair(GameStateType::Lost, std::make_unique<GameStateLost>(*gameWindow, gameOver, ladderboard, playerInput, currentScore)));
	gameStateMap.insert(std::pair(GameStateType::Loading, std::make_unique<GameStateLoading>(*gameWindow)));
	gameWindow->create(videoMode, resources.gameTitle, sf::Style::Close);
	gameWindow->setFramerateLimit(resources.frameRate);
}

void Game::restartGameInitialValues() 
{
	if (currentState == GameStateType::Menu)
	{
		lifes = resources.noOfLifes;
		currentScore = 0;
		playerInput = "";
		player.moveToSpawnPoint();
		player.setDirection(Direction::None);
		ghostManager.restartPositions();
		map.buildAMap();
	}
}

void Game::calculateFrameTime() 
{
	frameTime = frameTimeClock.restart().asSeconds();
}

void Game::update() 
{
	currentState = gameStateMap.at(currentState)->processInputs();
	gameStateMap.at(currentState)->update();
	calculateFrameTime();
	restartGameInitialValues();
}

void Game::render() {
	gameStateMap.at(currentState)->render();
	gameWindow->display();
	gameWindow->clear();
}

void Game::run() 
{
	while (gameWindow->isOpen())
	{
		render();
		update();
	}
}