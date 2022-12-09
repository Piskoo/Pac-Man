#include "RedEscapeBehaviour.h"

RedEscapeBehaviour::RedEscapeBehaviour(Map& _map) :
	Behaviour(_map)
{

}

void RedEscapeBehaviour::calculateTarget()
{
	target = sf::Vector2f(17, 1);
}