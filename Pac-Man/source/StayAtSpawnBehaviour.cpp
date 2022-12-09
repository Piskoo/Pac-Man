#include "StayAtSpawnBehaviour.h"

StayAtSpawnBehaviour::StayAtSpawnBehaviour(Map& _map) :
	Behaviour(_map)
{
}

void StayAtSpawnBehaviour::calculateTarget()
{
	target = sf::Vector2f(9, 10);
}

void StayAtSpawnBehaviour::selectPath(sf::Vector2f& _currentTile, std::vector<Direction>& _lastThreeDirections, unsigned& _decisionCooldown)
{
	bool middleOfTileX = (std::fmod(_currentTile.x, 1) > 0.40) && (std::fmod(_currentTile.x, 1) < 0.60);
	bool middleOfTileY = (std::fmod(_currentTile.y, 1) > 0.40) && (std::fmod(_currentTile.y, 1) < 0.60);
	if ((!rightCollision(_currentTile)) && middleOfTileY)
	{
		_lastThreeDirections[0] = Direction::Left;
	}
	else if ((!leftCollision(_currentTile)) && middleOfTileY)
	{
		_lastThreeDirections[0] = Direction::Right;
	}
	else 
	{

	}
}