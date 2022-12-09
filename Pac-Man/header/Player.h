#pragma once
#include <string>
#include "AnimatedSprite.h"
#include "Map.h"
#include <filesystem>
#include "Direction.h"
#include "Resources.h"

class Player
{
private:
	Resources* pResources;
	Map* pMap;
	unsigned* pCurrentScore;
	float* pFrameTime;

	AnimatedSprite player;
	sf::Vector2f currentPosition;
	sf::Vector2f currentTilePosition;
	Direction direction;
	Direction directionBuffor;
	float velocity;
	bool empowered;
	sf::Int32 empowermentTime;
	sf::Clock empowermentClock;
	sf::Int32 empowermentClockTimer;

	bool isInBounds();
	void setVelocity();
	bool checkTopWallCollision(); // 1 - no collision, 0 - collision
	bool checkBottomWallCollision(); // 1 - no collision, 0 - collision
	bool checkLeftWallCollision(); // 1 - no collision, 0 - collision
	bool checkRightWallCollision(); // 1 - no collision, 0 - collision
	void changeDirection();
	void updateCurrentPosition();
	void keepMoving();
	void collectPoints();
	void warpPlayer();
	void manageEmpowerment();
public:
	Player(Resources& _resources, Map& _map, unsigned& _currentScore, float& _frameTime);
	~Player() = default;
	AnimatedSprite& getAnimatedPlayer();
	sf::Vector2f getPosition();
	void setDirection(Direction _direction);
	Direction getDirection();
	void moveToSpawnPoint();
	bool isEmpowered();
	void update();
	void render(sf::RenderTarget& _target);
};



