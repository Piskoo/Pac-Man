#include "PinkEscapeBehaviour.h"

PinkEscapeBehaviour::PinkEscapeBehaviour(Map& _map) :
	Behaviour(_map)
{

}

void PinkEscapeBehaviour::calculateTarget()
{
	target = sf::Vector2f(1, 1);
}