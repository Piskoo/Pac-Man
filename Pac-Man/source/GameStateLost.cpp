#include "GameStateLost.h"

GameStateLost::GameStateLost(sf::RenderWindow& _gameWindow, GameOver& _gameOver, Ladderboard& _ladderboard, sf::String& _playerInput, unsigned& _currentScore) :
	GameState(_gameWindow),
	pGameOver(&_gameOver),
	pLadderboard(&_ladderboard),
	pPlayerInput(&_playerInput),
	pCurrentScore(&_currentScore)
{
	
}

GameStateType GameStateLost::processInputs()
{
	while (pGameWindow->pollEvent(gameEvent))
	{
		if (gameEvent.type == sf::Event::Closed)
		{
			pGameWindow->close();
		}
		else if (gameEvent.type == sf::Event::KeyPressed)
		{
			if (pLadderboard->pointsHigherThanLowestScore(*pCurrentScore))
			{
				if ((gameEvent.key.code == sf::Keyboard::Enter) && pGameOver->checkIfNameIsValid())
				{
					pLadderboard->saveNewScore(*pPlayerInput, *pCurrentScore);
					return GameStateType::Ladderboard;
				}
			}
			else
			{
				return GameStateType::Ladderboard;
			}
		}
		else if (gameEvent.type == sf::Event::TextEntered)
		{
			if (gameEvent.text.unicode == '\b' && pPlayerInput->getSize() > 0)
			{
				pPlayerInput->erase(pPlayerInput->getSize() - 1, 1);
			}
			else if (gameEvent.text.unicode < 128 && gameEvent.text.unicode != '\b' && gameEvent.text.unicode != '\r')
			{
				*pPlayerInput += gameEvent.text.unicode;
			}
		}
	}
	return GameStateType::Lost;
}

void GameStateLost::update()
{
	pGameOver->update();
	if (pLadderboard->pointsHigherThanLowestScore(*pCurrentScore))
	{
		pGameOver->setDrawHelp(true);
	}
	else
	{
		pGameOver->setDrawHelp(false);
	}
}

void GameStateLost::render()
{
	pGameOver->render(*pGameWindow);
}