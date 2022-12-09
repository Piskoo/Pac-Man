#pragma once
#include "Behaviour.h"
class PinkEscapeBehaviour : public Behaviour
{
public:
	PinkEscapeBehaviour(Map& _map);
	virtual void calculateTarget() override;
};

