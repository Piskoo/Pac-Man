#pragma once
#include "Behaviour.h"

class RedChaseBehaviour : public Behaviour
{
	Player* pPlayer;
public:
	RedChaseBehaviour(Map& _map, Player& _player);
	virtual void calculateTarget() override;
};

