#include "GameStateLadderboard.h"

GameStateLadderboard::GameStateLadderboard(sf::RenderWindow& _gameWindow, Ladderboard& _ladderboard) :
	GameState(_gameWindow), 
	pLadderboard(&_ladderboard)
{

}

GameStateType GameStateLadderboard::processInputs()
{
	while (pGameWindow->pollEvent(gameEvent))
	{
		if (gameEvent.type == sf::Event::Closed)
		{
			pGameWindow->close();
		}
		else if (gameEvent.type == sf::Event::KeyPressed)
		{
			if (gameEvent.key.code == sf::Keyboard::Enter)
			{
				return GameStateType::Menu;
			}
		}
	}
	return GameStateType::Ladderboard;
}

void GameStateLadderboard::update()
{

}

void GameStateLadderboard::render()
{
	pLadderboard->render(*pGameWindow);
}