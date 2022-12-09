#pragma once
#include "Behaviour.h"
class OrangeEscapeBehaviour : public Behaviour
{
public:
	OrangeEscapeBehaviour(Map& _map);
	virtual void calculateTarget() override;
};

