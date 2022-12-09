#include "RedChaseBehaviour.h"

RedChaseBehaviour::RedChaseBehaviour(Map& _map, Player& _player) : 
	Behaviour(_map),
	pPlayer(&_player)
{
}

void RedChaseBehaviour::calculateTarget()
{
	target = sf::Vector2f(pPlayer->getPosition().x, pPlayer->getPosition().y);
}