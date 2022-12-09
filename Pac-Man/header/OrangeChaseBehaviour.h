#pragma once
#include "Behaviour.h"
#include "Ghost.h"
class OrangeChaseBehaviour : public Behaviour
{
	Player* pPlayer;
	Ghost* pOrangeGhost;
public:
	OrangeChaseBehaviour(Map& _map, Player& _player, Ghost& _orangeGhost);
	virtual void calculateTarget() override;
};

