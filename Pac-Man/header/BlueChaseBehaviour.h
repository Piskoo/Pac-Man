#pragma once
#include "Behaviour.h"
#include "Ghost.h"
class BlueChaseBehaviour : public Behaviour
{
	Player* pPlayer;
	Ghost* pRedGhost;
public:
	BlueChaseBehaviour(Map& _map, Player& _player, Ghost& _redGhost);
	virtual void calculateTarget() override;
};

