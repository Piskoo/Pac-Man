#include "BlueEscapeBehaviour.h"

BlueEscapeBehaviour::BlueEscapeBehaviour(Map& _map) :
	Behaviour(_map)
{

}

void BlueEscapeBehaviour::calculateTarget()
{
	target = sf::Vector2f(17, 20);
}