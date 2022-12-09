#include "GameStatePlaying.h"

GameStatePlaying::GameStatePlaying(sf::RenderWindow& _gameWindow, Map& _map, Hud& _hud, Player& _player, GhostManager& _ghostManager, unsigned& _lifesCount) :
	GameState(_gameWindow),
	pMap(&_map),
	pHud(&_hud),
	pPlayer(&_player),
	pGhostManager(&_ghostManager),
	pLifesCount(&_lifesCount),
	pauseOrigin(0)
{
}

void GameStatePlaying::collectedAllDots()
{
	if (pMap->getDotsCount() == 0)
	{
		pPlayer->getAnimatedPlayer().getSprite().setPosition(sf::Vector2f(pMap->getPositionOf(TileType::PacManSpawnPoint)));
		pPlayer->setDirection(Direction::None);
		pMap->buildAMap();
		pauseOrigin = pauseClock.getElapsedTime().asMilliseconds();
		pGhostManager->restartPositions();
	}
}

GameStateType GameStatePlaying::processInputs()
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
				pPlayer->setDirection(Direction::Up);
			}
			else if (gameEvent.key.code == sf::Keyboard::S || gameEvent.key.code == sf::Keyboard::Down)
			{
				pPlayer->setDirection(Direction::Down);
			}
			else if (gameEvent.key.code == sf::Keyboard::A || gameEvent.key.code == sf::Keyboard::Left)
			{
				pPlayer->setDirection(Direction::Left);
			}
			else if (gameEvent.key.code == sf::Keyboard::D || gameEvent.key.code == sf::Keyboard::Right)
			{
				pPlayer->setDirection(Direction::Right);
			}
			if (gameEvent.key.code == sf::Keyboard::L)
			{
				--(*pLifesCount);

			}
		}
	}
	if (*pLifesCount <= 0)
	{
		return GameStateType::Lost;
	} 
	else 
	{
		return GameStateType::Playing;
	}
}

void GameStatePlaying::update()
{
	if (pauseOrigin + 3000 <= pauseClock.getElapsedTime().asMilliseconds()) 
	{
		pPlayer->update();
		pHud->update();
		pGhostManager->update();
		collectedAllDots();
	}
}

void GameStatePlaying::render()
{
	pMap->render(*pGameWindow);
	pHud->render(*pGameWindow);
	pPlayer->render(*pGameWindow);
	pGhostManager->render(*pGameWindow);
}