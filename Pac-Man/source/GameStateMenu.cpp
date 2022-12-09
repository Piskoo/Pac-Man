#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(sf::RenderWindow& _gameWindow, Menu& _menu) : GameState(_gameWindow), pMenu(&_menu)
{
	
}

GameStateType GameStateMenu::processInputs()
{
	while (pGameWindow->pollEvent(gameEvent))
	{
		if (gameEvent.type == sf::Event::Closed)
		{
			pGameWindow->close();
		}
		else if (gameEvent.type == sf::Event::KeyPressed)
		{
			if (gameEvent.key.code == sf::Keyboard::W || gameEvent.key.code == sf::Keyboard::Up)
			{
				pMenu->menuMoveUp();
			}
			else if (gameEvent.key.code == sf::Keyboard::S || gameEvent.key.code == sf::Keyboard::Down)
			{
				pMenu->menuMoveDown();
			}
			else if (gameEvent.key.code == sf::Keyboard::Enter)
			{
				if (pMenu->getIsSelectedPlay() == true)
				{
					return GameStateType::Playing;
				}
				else if (pMenu->getIsSelectedLadderboard() == true)
				{
					return GameStateType::Ladderboard;
				}
				else if (pMenu->getIsSelectedQuit() == true)
				{
					pGameWindow->close();
				}
			}
		}
	}
	return GameStateType::Menu;
}

void GameStateMenu::update() 
{
	pMenu->update();
}

void GameStateMenu::render() 
{
	pMenu->render(*pGameWindow);
}
