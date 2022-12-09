#include "Player.h"

Player::Player(Resources& _resources, Map& _map, unsigned& _currentScore, float& _frameTime) :
	pResources(&_resources),
	pMap(&_map),
	pCurrentScore(&_currentScore),
	pFrameTime(&_frameTime),
	player(AnimatedSprite(_resources.pathPacManTexture, _resources.pacmanAnimationTimeInMilisec)),
	currentPosition(_map.getPositionOf(TileType::PacManSpawnPoint)),
	direction(Direction::None), 
	directionBuffor(Direction::None),
	velocity(0),
	empowered(false),
	empowermentTime(7000),
	empowermentClockTimer(0)
{
	player.getSprite().setPosition(currentPosition.x, currentPosition.y);
	updateCurrentPosition();
}

sf::Vector2f Player::getPosition() 
{
	return currentTilePosition;
}

AnimatedSprite& Player::getAnimatedPlayer()
{
	return player;
}

bool Player::isInBounds()
{
	if (currentTilePosition.x >= 1 && currentTilePosition.x <= 18)  
	{
		return true; 
	} 
	else 
	{
		return false; 
	}
}

void Player::setVelocity()
{
	velocity = pResources->pacmanUnitsPerSecond * (*pFrameTime);
}

bool Player::checkTopWallCollision()
{
	return (pMap->getMap()[static_cast<int>(currentTilePosition.y - 0.6)][static_cast<int>(currentTilePosition.x)] != pMap->getWallID());
}

bool Player::checkBottomWallCollision()
{
	return (pMap->getMap()[static_cast<int>(currentTilePosition.y + 0.6)][static_cast<int>(currentTilePosition.x)] != pMap->getWallID() && 
		pMap->getMap()[static_cast<int>(currentTilePosition.y + 0.6)][static_cast<int>(currentTilePosition.x)] != pMap->getGhostGateID());
}

bool Player::checkLeftWallCollision()
{
		return (pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x - 0.6)] != pMap->getWallID());
}

bool Player::checkRightWallCollision()
{
		return (pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x + 0.6)] != pMap->getWallID());
}

void Player::changeDirection()
{
	if (directionBuffor == Direction::Up)
	{
		if ((checkTopWallCollision()) &&
			((std::fmod(currentTilePosition.x, 1) > 0.40) && (std::fmod(currentTilePosition.x, 1) < 0.60)))
		{
			direction = directionBuffor;
			player.getSprite().setRotation(270);
		}
	}
	else if (directionBuffor == Direction::Down)
	{
		if ((checkBottomWallCollision()) &&
			((std::fmod(currentTilePosition.x, 1) > 0.40) && (std::fmod(currentTilePosition.x, 1) < 0.60)))
		{
			direction = directionBuffor;
			player.getSprite().setRotation(90);
		}
	}
	else if (directionBuffor == Direction::Left)
	{
		if ((checkLeftWallCollision()) &&
			((std::fmod(currentTilePosition.y, 1) > 0.40) && (std::fmod(currentTilePosition.y, 1) < 0.60)))
		{
			direction = directionBuffor;
			player.getSprite().setRotation(180);
		}
	}
	else if (directionBuffor == Direction::Right)
	{
		if ((checkRightWallCollision()) &&
			((std::fmod(currentTilePosition.y, 1) > 0.40) && (std::fmod(currentTilePosition.y, 1) < 0.60)))
		{
			direction = directionBuffor;
			player.getSprite().setRotation(0);
		}
	}
	else if (directionBuffor == Direction::None) 
	{
		direction = directionBuffor;
	}
}

void Player::moveToSpawnPoint()
{
	player.getSprite().setPosition(pMap->getPositionOf(TileType::PacManSpawnPoint));
}

void Player::updateCurrentPosition()
{
	currentPosition.x = player.getSprite().getPosition().x;
	currentPosition.y = player.getSprite().getPosition().y;
	currentTilePosition.x = currentPosition.x / pResources->tileSize - pResources->mapPixelOffsetWidth / pResources->tileSize;
	currentTilePosition.y = currentPosition.y / pResources->tileSize - pResources->mapPixelOffsetHeight / pResources->tileSize;
}

void Player::keepMoving()
{
	if ((direction == Direction::Up) && (checkTopWallCollision()))
	{
		player.getSprite().move(0, -velocity);
	}
	else if ((direction == Direction::Down) && (checkBottomWallCollision()))
	{
		player.getSprite().move(0, velocity);
	}
	else if ((direction == Direction::Left) && (checkLeftWallCollision()))
	{
		player.getSprite().move(-velocity, 0);
	}
	else if ((direction == Direction::Right) && (checkRightWallCollision()))
	{
		player.getSprite().move(velocity, 0);
	}
}

void Player::collectPoints()
{
	if ((pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == pMap->getSmallDotID()))
	{
		pMap->setDotToEmptySpace(currentTilePosition);
		*pCurrentScore += 10;
	}
	if ((pMap->getMap()[static_cast<int>(currentTilePosition.y)][static_cast<int>(currentTilePosition.x)] == pMap->getBigDotID()))
	{
		pMap->setDotToEmptySpace(currentTilePosition);
		*pCurrentScore += 50;
		empowered = true;
		empowermentClockTimer = empowermentClock.getElapsedTime().asMilliseconds();
	}
}

bool Player::isEmpowered()
{
	return empowered;
}

void Player::manageEmpowerment()
{
	if (empowered == true) 
	{
		if (empowermentClock.getElapsedTime().asMilliseconds() - empowermentClockTimer >= empowermentTime)
		{
			empowered = false;
		}
	}
}

Direction Player::getDirection()
{
	return direction;
}


void Player::warpPlayer()
{
	if (!isInBounds() && direction == Direction::Left) {
		player.getSprite().move(-static_cast<float>(velocity), 0);
		if (currentTilePosition.x - 0.6 <= -1 && direction == Direction::Left)
		{
			player.getSprite().setPosition(624, currentPosition.y);
		}
	}
	else if (!isInBounds() && direction == Direction::Right) {
		player.getSprite().move(static_cast<float>(velocity), 0);
		if (currentTilePosition.x + 0.6 >= 20 && direction == Direction::Right)
		{
			player.getSprite().setPosition(-16, currentPosition.y);
		}
	}
}

void Player::setDirection(Direction _direction)
{
	directionBuffor = _direction;
}

void Player::update()
{
	updateCurrentPosition();
	setVelocity();
	if (isInBounds())
	{
		keepMoving();
		collectPoints();
		manageEmpowerment();
		changeDirection();
	}
	warpPlayer();
	if (direction != Direction::None)
	{
		player.update();
	}
}

void Player::render(sf::RenderTarget& _target)
{
	_target.draw(player.getSprite());
}