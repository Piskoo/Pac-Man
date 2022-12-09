#include "GameStateLoading.h"

GameStateLoading::GameStateLoading(sf::RenderWindow& _gameWindow) :
	GameState(_gameWindow),
	clock()
{
	
}

GameStateType GameStateLoading::processInputs()
{
	if(clock.getElapsedTime().asMilliseconds() > loadingTime)
	{
		return GameStateType::Menu;
		
	}
	return GameStateType::Loading;

}

void GameStateLoading::update()
{

}

void GameStateLoading::render()
{

}