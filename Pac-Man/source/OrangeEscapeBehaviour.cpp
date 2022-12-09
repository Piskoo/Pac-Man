#include "OrangeEscapeBehaviour.h"

OrangeEscapeBehaviour::OrangeEscapeBehaviour(Map& _map) :
	Behaviour(_map)
{

}

void OrangeEscapeBehaviour::calculateTarget()
{
	target = sf::Vector2f(1, 20);
}