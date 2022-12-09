#pragma once
#include "Map.h"
#include "Player.h"
#include <memory>


class Behaviour
{
protected:
	Map* pMap;
	sf::Vector2f target;
	sf::Clock clock;
public:
	Behaviour(Map& _map);
	virtual ~Behaviour();
	virtual void calculateTarget() = 0;
	const sf::Vector2f& getTarget();
	bool topCollision(sf::Vector2f& _currentTile);
	bool bottomCollision(sf::Vector2f& _currentTile);
	bool rightCollision(sf::Vector2f& _currentTile);
	bool leftCollision(sf::Vector2f& _currentTile);
	virtual void selectPath(sf::Vector2f& _currentTile, std::vector<Direction>& _lastThreeDirections, unsigned& _decisionCooldown);
};

