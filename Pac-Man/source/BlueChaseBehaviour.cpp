#include "BlueChaseBehaviour.h"

BlueChaseBehaviour::BlueChaseBehaviour(Map& _map, Player& _player, Ghost& _redGhost) :
	Behaviour(_map),
	pPlayer(&_player),
	pRedGhost(&_redGhost)
{
}

void BlueChaseBehaviour::calculateTarget()
{
	sf::Vector2f positionDifference = sf::Vector2(pPlayer->getPosition().x - pRedGhost->getPosition().x, pPlayer->getPosition().y - pRedGhost->getPosition().y);
	target = sf::Vector2f(pPlayer->getPosition().x + positionDifference.x, pPlayer->getPosition().y + positionDifference.y);
	if (target.x >= 17) 
	{
		target.x = 17;
	}
	if (target.x <= 1)
	{
		target.x = 1;
	}
	if (target.y >= 20)
	{
		target.y = 20;
	}
	if (target.y <= 1)
	{
		target.y = 1;
	}
}