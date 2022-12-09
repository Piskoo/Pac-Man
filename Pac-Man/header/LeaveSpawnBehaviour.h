#pragma once
#include "Behaviour.h"
class LeaveSpawnBehaviour : public Behaviour
{
public:
	LeaveSpawnBehaviour(Map& _map);
	virtual void calculateTarget() override;
	void selectPath(sf::Vector2f& _currentTile, std::vector<Direction>& _lastThreeDirections, unsigned& _decisionCooldown) override;
};

