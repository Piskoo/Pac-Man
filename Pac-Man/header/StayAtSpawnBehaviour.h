#pragma once
#include "Behaviour.h"
class StayAtSpawnBehaviour : public Behaviour
{
public:
	StayAtSpawnBehaviour(Map& _map);
	virtual void calculateTarget() override;
	void selectPath(sf::Vector2f& _currentTile, std::vector<Direction>& _lastThreeDirections, unsigned& _decisionCooldown) override;
};

