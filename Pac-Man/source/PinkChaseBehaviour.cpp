#include "PinkChaseBehaviour.h"

PinkChaseBehaviour::PinkChaseBehaviour(Map& _map, Player& _player) :
	Behaviour(_map),
	pPlayer(&_player)
{
}

void PinkChaseBehaviour::calculateTarget()
{
	Direction playerDirection = pPlayer->getDirection();
	if (playerDirection == Direction::Up)
	{
		target = sf::Vector2f(pPlayer->getPosition().x, pPlayer->getPosition().y - 2);
	} 
	else if (playerDirection == Direction::Down)
	{
		target = sf::Vector2f(pPlayer->getPosition().x, pPlayer->getPosition().y + 2);
	}
	else if (playerDirection == Direction::Right)
	{
		target = sf::Vector2f(pPlayer->getPosition().x + 2, pPlayer->getPosition().y);
	}
	else if (playerDirection == Direction::Left)
	{
		target = sf::Vector2f(pPlayer->getPosition().x - 2, pPlayer->getPosition().y);
	}
	else 
	{
		sf::Vector2f(pPlayer->getPosition().x, pPlayer->getPosition().y);
	}
}