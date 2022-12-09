#include "OrangeChaseBehaviour.h"

OrangeChaseBehaviour::OrangeChaseBehaviour(Map& _map, Player& _player, Ghost& _orangeGhost) :
	Behaviour(_map),
	pPlayer(&_player),
	pOrangeGhost(&_orangeGhost)
{
}

void OrangeChaseBehaviour::calculateTarget()
{
	if (abs(pOrangeGhost->getPosition().y - pPlayer->getPosition().y) >= 4 ||
		abs(pOrangeGhost->getPosition().x - pPlayer->getPosition().x) >= 4) 
	{
	target = sf::Vector2f(pPlayer->getPosition().x, pPlayer->getPosition().y);
	}
	else 
	{
		target = sf::Vector2f(1, 20);
	}
}