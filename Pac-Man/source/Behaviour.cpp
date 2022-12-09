#include "Behaviour.h"

Behaviour::Behaviour(Map& _map) :
	pMap(&_map),
	target(sf::Vector2f(1, 1))
{

}

Behaviour::~Behaviour() 
{

}

const sf::Vector2f& Behaviour::getTarget()
{
	return target;
}

bool Behaviour::topCollision(sf::Vector2f& _currentTile)
{
	return (pMap->getMap()[static_cast<int>(_currentTile.y - 0.6)][static_cast<int>(_currentTile.x)] != pMap->getWallID());
}

bool Behaviour::bottomCollision(sf::Vector2f& _currentTile)
{
	return (pMap->getMap()[static_cast<int>(_currentTile.y + 0.6)][static_cast<int>(_currentTile.x)] != pMap->getWallID() &&
		pMap->getMap()[static_cast<int>(_currentTile.y + 0.6)][static_cast<int>(_currentTile.x)] != pMap->getGhostGateID());
}

bool Behaviour::leftCollision(sf::Vector2f& _currentTile)
{
	return (pMap->getMap()[static_cast<int>(_currentTile.y)][static_cast<int>(_currentTile.x - 0.6)] != pMap->getWallID() &&
		pMap->getMap()[static_cast<int>(_currentTile.y)][static_cast<int>(_currentTile.x - 0.6)] != pMap->getWarpID());
}

bool Behaviour::rightCollision(sf::Vector2f& _currentTile)
{
	return (pMap->getMap()[static_cast<int>(_currentTile.y)][static_cast<int>(_currentTile.x + 0.6)] != pMap->getWallID() &&
		pMap->getMap()[static_cast<int>(_currentTile.y)][static_cast<int>(_currentTile.x + 0.6)] != pMap->getWarpID());
}

void Behaviour::selectPath(sf::Vector2f& _currentTile, std::vector<Direction>& _lastThreeDirections, unsigned& _decisionCooldown)
{
	float tempY = target.y - _currentTile.y;
	float tempX = target.x - _currentTile.x;
	bool middleOfTileX = (std::fmod(_currentTile.x, 1) > 0.40) && (std::fmod(_currentTile.x, 1) < 0.60);
	bool middleOfTileY = (std::fmod(_currentTile.y, 1) > 0.40) && (std::fmod(_currentTile.y, 1) < 0.60);

	if (_lastThreeDirections[2] != _lastThreeDirections[0])
	{
		
		if (clock.getElapsedTime().asMilliseconds() >= static_cast<int>(_decisionCooldown))
		{
			if (_lastThreeDirections[0] == _lastThreeDirections[1])
			{
				_lastThreeDirections[0] = Direction::None;
				clock.restart();
			}
			else
			{
				_lastThreeDirections[2] = _lastThreeDirections[1];
				_lastThreeDirections[1] = _lastThreeDirections[0];
				_lastThreeDirections[0] = Direction::None;
				clock.restart();
			}
		}
		if (_lastThreeDirections[0] == Direction::None)
		{
			if (tempY >= 0)
			{
				if (tempX >= 0)
				{
					if (abs(tempY) >= abs(tempX))
					{
						if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}

					}
					else if (abs(tempY) < abs(tempX))
					{
						if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
					}
				}
				else if (tempX < 0)
				{
					if (abs(tempY) >= abs(tempX))
					{
						if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
					}
					else if (abs(tempY) < abs(tempX))
					{
						if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
					}
				}
			}
			else if (tempY < 0)
			{
				if (tempX >= 0)
				{
					if (abs(tempY) >= abs(tempX))
					{
						if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
					}
					else if (abs(tempY) < abs(tempX))
					{
						if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
					}
				}
				if (tempX < 0)
				{
					if (abs(tempY) >= abs(tempX))
					{
						if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
						else if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
					}
					else if (abs(tempY) < abs(tempX))
					{
						if ((leftCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Left;
						}
						else if ((topCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Up;
						}
						else if ((rightCollision(_currentTile)) && middleOfTileY)
						{
							_lastThreeDirections[0] = Direction::Right;
						}
						else if ((bottomCollision(_currentTile)) && middleOfTileX)
						{
							_lastThreeDirections[0] = Direction::Down;
						}
					}
				}
			}
		}
	}
	else
	{
		if (_lastThreeDirections[0] == Direction::Up && !topCollision(_currentTile))
		{
			if (leftCollision(_currentTile) && middleOfTileY && tempX < 0)
			{
				_lastThreeDirections[0] = Direction::Left;
			}
			else if (rightCollision(_currentTile) && middleOfTileY && tempX >= 0)
			{
				_lastThreeDirections[0] = Direction::Right;
			}
			else if (leftCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Left;
			}
			else if (rightCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Right;
			}
			else if (bottomCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Down;
			}
			clock.restart();
		}
		else if (_lastThreeDirections[0] == Direction::Down && !bottomCollision(_currentTile))
		{
			if (leftCollision(_currentTile) && middleOfTileY && tempX < 0)
			{
				_lastThreeDirections[0] = Direction::Left;
			}
			else if (rightCollision(_currentTile) && middleOfTileY && tempX >= 0)
			{
				_lastThreeDirections[0] = Direction::Right;
			}
			else if (leftCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Left;
			}
			else if (rightCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Right;
			}
			else if (topCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Up;
			}
			clock.restart();
		}
		else if (_lastThreeDirections[0] == Direction::Left && !leftCollision(_currentTile))
		{
			if (topCollision(_currentTile) && middleOfTileX && tempY < 0)
			{
				_lastThreeDirections[0] = Direction::Up;
			}
			else if (bottomCollision(_currentTile) && middleOfTileX && tempY >= 0)
			{
				_lastThreeDirections[0] = Direction::Down;
			}
			else if (topCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Up;
			}
			else if (bottomCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Down;
			}
			else if (rightCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Right;
			}
			clock.restart();
		}
		else if (_lastThreeDirections[0] == Direction::Right && !rightCollision(_currentTile))
		{
			if (topCollision(_currentTile) && middleOfTileX && tempY < 0)
			{
				_lastThreeDirections[0] = Direction::Up;
			}
			else if (bottomCollision(_currentTile) && middleOfTileX && tempY >= 0)
			{
				_lastThreeDirections[0] = Direction::Down;
			}
			else if (topCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Up;
			}
			else if (bottomCollision(_currentTile) && middleOfTileX)
			{
				_lastThreeDirections[0] = Direction::Down;
			}
			else if (leftCollision(_currentTile) && middleOfTileY)
			{
				_lastThreeDirections[0] = Direction::Left;
			}
			clock.restart();
		}
	}
}
