#pragma once
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <memory>
#include "Button.h"
#include "Resources.h"

class Menu
{
	Resources* pResources;
	float* pFrameTime;
	sf::Font logoFont;
	sf::Text pacman;
	Button play;
	Button ladderboard;
	Button quit;
	std::vector<std::shared_ptr<AnimatedSprite>> characters;
	bool isSelectedPlay;
	bool isSelectedLadderboard;
	bool isSelectedQuit;
	float velocity;

	void higlightActiveButton();
	void setAnimationVelocity();

public:
	Menu(Resources& _resources, float& _frameTime);
	~Menu() = default;

	void menuMoveUp();
	void menuMoveDown();
	bool getIsSelectedPlay();
	bool getIsSelectedLadderboard();
	bool getIsSelectedQuit();
	void update();
	void render(sf::RenderTarget& _target);
};

