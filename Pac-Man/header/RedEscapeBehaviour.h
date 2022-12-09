#pragma once
#include "Behaviour.h"
class RedEscapeBehaviour : public Behaviour
{
public:
	RedEscapeBehaviour(Map& _map);
	virtual void calculateTarget() override;
};

