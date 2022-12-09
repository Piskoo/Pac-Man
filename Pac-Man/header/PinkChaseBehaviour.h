#pragma once
#include "Behaviour.h"
class PinkChaseBehaviour : public Behaviour
{
	Player* pPlayer;
public:
	PinkChaseBehaviour(Map& _map, Player& _player);
	virtual void calculateTarget() override;
};

