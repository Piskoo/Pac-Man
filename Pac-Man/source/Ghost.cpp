#include "Ghost.h"

Ghost::Ghost(Resources& _resources, Map& _map, Behaviour& _behaviour, float& _frameTime, std::filesystem::path _path, unsigned _tileType) :
	pResources(&_resources),
	pMap(&_map),
	pBehaviour(&_behaviour),
	pFrameTime(&_frameTime),
	ghost(_path, _resources.ghostAnimationTimeInMilisec),
	currentPosition(_map.getPositionOf(_tileType)),
	lastThreeDirections({Direction::None,Direction::None,Direction::Right }),
	velocity(0),
	clock(sf::Clock()),
	movementLocked(false),
	decisionCooldown(50),
	spawnTile(_tileType),
	unitsPerSecond(120)
{
	ghost.getSprite().setPosition(_map.getPositionOf(_tileType));
	updateCurrentPosition();
}

void Ghost::setGhostDecisionCooldown(unsigned _value) 
{
	decisionCooldown = _value;
}

void Ghost::setVelocity()
{
	velocity = unitsPerSecond * (*pFrameTime);
}

void Ghost::setUnitsPerSecond(unsigned _value)
{
	unitsPerSecond = _value;
}

void Ghost::moveToSpawnPoint()
{
	ghost.getSprite().setPosition(pMap->getPositionOf(spawnTile));
}

void Ghost::moveToSpawnBox()
{
	ghost.getSprite().setPosition(pMap->getPositionOf(TileType::BlueGhostSpawnPoint));
}

bool Ghost::isAtSpawnPoint()
{
	if (pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == TileType::PinkGhostSpawnPoint ||
		pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == TileType::OrangeGhostSpawnPoint ||
		pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == TileType::BlueGhostSpawnPoint ||
		pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == TileType::GhostGate) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Ghost::updateCurrentPosition()
{
	currentPosition.x = ghost.getSprite().getPosition().x;
	currentPosition.y = ghost.getSprite().getPosition().y;
	currentTilePosition.x = currentPosition.x / pResources->tileSize - pResources->mapPixelOffsetWidth / pResources->tileSize;
	currentTilePosition.y = currentPosition.y / pResources->tileSize - pResources->mapPixelOffsetHeight / pResources->tileSize;
}

void Ghost::keepMoving()
{
	if ((lastThreeDirections[0] == Direction::Up) && (pBehaviour->topCollision(currentTilePosition)))
	{
		ghost.getSprite().move(0, -velocity);
	}
	else if ((lastThreeDirections[0] == Direction::Down) && (pBehaviour->bottomCollision(currentTilePosition)))
	{
		ghost.getSprite().move(0, velocity);
	}
	else if ((lastThreeDirections[0] == Direction::Left) && (pBehaviour->leftCollision(currentTilePosition)))
	{
		ghost.getSprite().move(-velocity, 0);
	}
	else if ((lastThreeDirections[0] == Direction::Right) && (pBehaviour->rightCollision(currentTilePosition)))
	{
		ghost.getSprite().move(velocity, 0);
	}
}

sf::Vector2f Ghost::getPosition()
{
	return currentTilePosition;
}

void Ghost::changeBehaviour(Behaviour& _behaviour)
{
	pBehaviour = &_behaviour;
}

void Ghost::setTexture(sf::Texture& _texture)
{
	ghost.setTexture(_texture);
}

void Ghost::update()
{
	pBehaviour->calculateTarget();
	updateCurrentPosition();
	setVelocity();
	pBehaviour->selectPath(currentTilePosition,lastThreeDirections,decisionCooldown);
	keepMoving();
	ghost.update();
}
void Ghost::render(sf::RenderTarget& _target)
{
	_target.draw(ghost.getSprite());
}