#include "GhostManager.h"

GhostManager::GhostManager(Resources& _resources, Map& _map, Player& _player, float& _frameTime, unsigned& _lifesCount, unsigned& _currentScore) :
	pResources(&_resources),
	pMap(&_map),
	pPlayer(&_player),
	pFrameTime(&_frameTime),
	leaveSpawnBehaviour(std::make_shared<LeaveSpawnBehaviour>(*pMap)),
	stayAtSpawnBehaviour(std::make_shared<StayAtSpawnBehaviour>(*pMap)),
	scaredTexture(std::make_shared<sf::Texture>()),
	pLifesCount(&_lifesCount),
	pCurrentScore(&_currentScore),
	previousPlayerStatus(0)
{
	textureContainer.insert(std::pair(GhostType::RedGhost, std::make_shared<sf::Texture>()));
	textureContainer.insert(std::pair(GhostType::PinkGhost, std::make_shared<sf::Texture>()));
	textureContainer.insert(std::pair(GhostType::OrangeGhost, std::make_shared<sf::Texture>()));
	textureContainer.insert(std::pair(GhostType::BlueGhost, std::make_shared<sf::Texture>()));
	scaredTexture->loadFromFile(_resources.pathScaredGhostTexture.string());

	textureContainer.at(GhostType::RedGhost)->loadFromFile(_resources.pathRedGhostTexture.string());
	textureContainer.at(GhostType::PinkGhost)->loadFromFile(_resources.pathPinkGhostTexture.string());
	textureContainer.at(GhostType::OrangeGhost)->loadFromFile(_resources.pathOrangeGhostTexture.string());
	textureContainer.at(GhostType::BlueGhost)->loadFromFile(_resources.pathBlueGhostTexture.string());
	ghostContainer.insert(std::pair(GhostType::RedGhost,
		std::make_shared<Ghost>(_resources, _map, *stayAtSpawnBehaviour, _frameTime, _resources.pathRedGhostTexture, TileType::RedGhostSpawnPoint)));
	ghostContainer.insert(std::pair(GhostType::PinkGhost,
		std::make_shared<Ghost>(_resources, _map, *stayAtSpawnBehaviour, _frameTime, _resources.pathPinkGhostTexture, TileType::PinkGhostSpawnPoint)));
	ghostContainer.insert(std::pair(GhostType::OrangeGhost,
		std::make_shared<Ghost>(_resources, _map, *stayAtSpawnBehaviour, _frameTime, _resources.pathOrangeGhostTexture, TileType::OrangeGhostSpawnPoint)));
	ghostContainer.insert(std::pair(GhostType::BlueGhost,
		std::make_shared<Ghost>(_resources, _map, *stayAtSpawnBehaviour, _frameTime, _resources.pathBlueGhostTexture, TileType::BlueGhostSpawnPoint)));

	chaseBehaviourContainer.insert(std::pair(GhostType::RedGhost, std::make_shared<RedChaseBehaviour>(*pMap, *pPlayer)));
	chaseBehaviourContainer.insert(std::pair(GhostType::PinkGhost, std::make_shared<PinkChaseBehaviour>(*pMap, *pPlayer)));
	chaseBehaviourContainer.insert(std::pair(GhostType::OrangeGhost, std::make_shared<OrangeChaseBehaviour>(*pMap, *pPlayer, *ghostContainer.at(GhostType::OrangeGhost))));
	chaseBehaviourContainer.insert(std::pair(GhostType::BlueGhost, std::make_shared<BlueChaseBehaviour>(*pMap, *pPlayer, *ghostContainer.at(GhostType::RedGhost))));

	escapeBehaviourContainer.insert(std::pair(GhostType::RedGhost, std::make_shared<RedEscapeBehaviour>(*pMap)));
	escapeBehaviourContainer.insert(std::pair(GhostType::PinkGhost, std::make_shared<PinkEscapeBehaviour>(*pMap)));
	escapeBehaviourContainer.insert(std::pair(GhostType::OrangeGhost, std::make_shared<OrangeEscapeBehaviour>(*pMap)));
	escapeBehaviourContainer.insert(std::pair(GhostType::BlueGhost, std::make_shared<BlueEscapeBehaviour>(*pMap)));
}

void GhostManager::manageTextures()
{
	if (previousPlayerStatus == false && pPlayer->isEmpowered() == true)
	{
		for (auto i : ghostContainer)
		{
			i.second->setTexture(*scaredTexture);
		}
	}
	if (previousPlayerStatus == true && pPlayer->isEmpowered() == false)
	{
		for (auto i : ghostContainer)
		{
			i.second->setTexture(*textureContainer.at(i.first));
		}
	}
	previousPlayerStatus = pPlayer->isEmpowered();
}

void GhostManager::collisionCheck()
{
	for (auto i : ghostContainer) 
	{
		if((static_cast<int>(pPlayer->getPosition().x) == static_cast<int>(i.second->getPosition().x)) &&
			static_cast<int>(pPlayer->getPosition().y) == static_cast<int>(i.second->getPosition().y)) 
		{
			if (pPlayer->isEmpowered()) 
			{
				i.second->moveToSpawnBox();
				*pCurrentScore += 200;
			}
			else 
			{
				restartPositions();
				pPlayer->moveToSpawnPoint();
				--(*pLifesCount);
			}
		}
	}
}

void GhostManager::restartPositions()
{
	for (auto i : ghostContainer)
	{
		i.second->moveToSpawnPoint();
	}
}

void GhostManager::manageBehaviour(std::pair<const GhostType, std::shared_ptr<Ghost>> _ghost) 
{
	if (pPlayer->isEmpowered() == false)
	{
		_ghost.second->setUnitsPerSecond(120);
		if (_ghost.second->isAtSpawnPoint())
		{
			if (_ghost.first == GhostType::BlueGhost && pMap->getDotsCount() > 125)
			{
				_ghost.second->changeBehaviour(*stayAtSpawnBehaviour);
			}
			else if (_ghost.first == GhostType::OrangeGhost && pMap->getDotsCount() > 95)
			{
				_ghost.second->changeBehaviour(*stayAtSpawnBehaviour);

			}
			else
			{
				_ghost.second->changeBehaviour(*leaveSpawnBehaviour);
			}
			_ghost.second->setGhostDecisionCooldown(60);
		}
		else
		{
			_ghost.second->changeBehaviour(*chaseBehaviourContainer.at(_ghost.first));
			_ghost.second->setGhostDecisionCooldown(120);
		}
	}
	else if (pPlayer->isEmpowered() == true)
	{
		_ghost.second->setGhostDecisionCooldown(80);
		_ghost.second->setUnitsPerSecond(80);
		if (!_ghost.second->isAtSpawnPoint())
		{
			_ghost.second->changeBehaviour(*escapeBehaviourContainer.at(_ghost.first));
		}
		else
		{
			_ghost.second->changeBehaviour(*stayAtSpawnBehaviour);
		}
	}
	_ghost.second->update();

}


void GhostManager::update()
{
	collisionCheck();
	manageTextures();
	std::vector<std::jthread> threadHandler;
	for (auto i : ghostContainer)
	{
		threadHandler.push_back(std::jthread(&GhostManager::manageBehaviour, this, i));
	}
}

void GhostManager::render(sf::RenderTarget& _target) 
{
	for (auto i : ghostContainer)
	{
		i.second->render(_target);
	}
}