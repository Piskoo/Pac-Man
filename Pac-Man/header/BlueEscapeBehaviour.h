#pragma once
#include "Behaviour.h"
class BlueEscapeBehaviour : public Behaviour
{
public:
	BlueEscapeBehaviour(Map& _map);
	virtual void calculateTarget() override;
};

