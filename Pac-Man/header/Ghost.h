#pragma once
#include "Behaviour.h"
#include "AnimatedSprite.h"
#include "Resources.h"
#include "Map.h"
#include "Direction.h"
#include "RedChaseBehaviour.h"
#include <vector>

class Behaviour;

class Ghost
{
	unsigned decisionCooldown;
	unsigned unitsPerSecond;
	Resources* pResources;
	Map* pMap;
	Behaviour* pBehaviour;
	float* pFrameTime;

	unsigned spawnTile;
	AnimatedSprite ghost;
	sf::Vector2f currentPosition;
	sf::Vector2f currentTilePosition;
	sf::Clock clock;

	std::vector<Direction> lastThreeDirections;
	float velocity;
	bool movementLocked;

	void setVelocity();
	void updateCurrentPosition();
	void keepMoving();
public:
	Ghost(Resources& _resources, Map& _map, Behaviour& _behaviour, float& _frameTime ,std::filesystem::path _path, unsigned _tileType);
	sf::Vector2f getPosition();
	void setUnitsPerSecond(unsigned _value);
	void changeBehaviour(Behaviour& _behaviour);
	void moveToSpawnPoint();
	void setGhostDecisionCooldown(unsigned _value);
	void setTexture(sf::Texture& _texture);
	void moveToSpawnBox();
	bool isAtSpawnPoint();
	void update();
	void render(sf::RenderTarget& _target);
};

