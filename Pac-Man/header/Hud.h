#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <filesystem>
#include "Resources.h"
#include "Ladderboard.h"

class Hud
{
	Resources* pResources;
	Ladderboard* pLadderboard;
	unsigned* pCurrentScore;
	unsigned* pLifesCount;

	sf::Text oneUp;
	sf::Text highScore;
	sf::Text currentPoints;
	sf::Text highestPoints;

	sf::VertexArray lifesArray;
	sf::Texture lifeTexture;
public:
	Hud(Resources& _resources, Ladderboard& _ladderboard, unsigned& _currentScore, unsigned& _lifesCount);
	void update();
	void render(sf::RenderTarget& _target);
};

