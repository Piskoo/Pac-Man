#include "LeaveSpawnBehaviour.h"

LeaveSpawnBehaviour::LeaveSpawnBehaviour(Map& _map) :
	Behaviour(_map)
{
}

void LeaveSpawnBehaviour::calculateTarget()
{
	target = sf::Vector2f(9, 5);
}

void LeaveSpawnBehaviour::selectPath(sf::Vector2f & _currentTile, std::vector<Direction>&_lastThreeDirections, unsigned& _decisionCooldown)
{
	bool middleOfTileX = (std::fmod(_currentTile.x, 1) > 0.40) && (std::fmod(_currentTile.x, 1) < 0.60);
	bool middleOfTileY = (std::fmod(_currentTile.y, 1) > 0.40) && (std::fmod(_currentTile.y, 1) < 0.60);
	if ((topCollision(_currentTile)) && middleOfTileX)
	{
		_lastThreeDirections[0] = Direction::Up;
	}
	else if ((!rightCollision(_currentTile)) && middleOfTileY)
	{
		_lastThreeDirections[0] = Direction::Left;
	}
	else if ((!leftCollision(_currentTile)) && middleOfTileY)
	{
		_lastThreeDirections[0] = Direction::Right;
	}
}