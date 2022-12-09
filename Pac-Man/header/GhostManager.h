#pragma once
#include <memory>
#include "Ghost.h"
#include "RedChaseBehaviour.h"
#include "PinkChaseBehaviour.h"
#include "OrangeChaseBehaviour.h"
#include "BlueChaseBehaviour.h"
#include "LeaveSpawnBehaviour.h"
#include "RedEscapeBehaviour.h"
#include "OrangeEscapeBehaviour.h"
#include "BlueEscapeBehaviour.h"
#include "PinkEscapeBehaviour.h"
#include <map>
#include "GhostType.h"
#include "StayAtSpawnBehaviour.h"
#include <thread>

class GhostManager
{
	Resources* pResources;
	Map* pMap; 
	Player* pPlayer; 
	float* pFrameTime;
	unsigned* pLifesCount;
	unsigned* pCurrentScore;
	
	bool previousPlayerStatus;

	std::map< GhostType,std::shared_ptr<sf::Texture>> textureContainer;
	std::shared_ptr<sf::Texture> scaredTexture;

	std::map<GhostType, std::shared_ptr<Behaviour>> chaseBehaviourContainer;
	std::map<GhostType, std::shared_ptr<Behaviour>> escapeBehaviourContainer;
	std::shared_ptr <LeaveSpawnBehaviour> leaveSpawnBehaviour;
	std::shared_ptr <StayAtSpawnBehaviour> stayAtSpawnBehaviour;

	std::map<GhostType, std::shared_ptr<Ghost>> ghostContainer;
	void collisionCheck();
	void manageBehaviour(std::pair<const GhostType, std::shared_ptr<Ghost>> _ghost);
	void manageTextures();
public:
	GhostManager(Resources& _resources, Map& _map, Player& _player, float& _frameTime, unsigned& _lifesCount, unsigned& _currentScore);
	void restartPositions();
	void update();
	void render(sf::RenderTarget& _target);
};

