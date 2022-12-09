#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "Resources.h"
#include <regex>
#include "Ladderboard.h"

class GameOver
{
	Resources* pResources;
	Ladderboard* pLadderboard; 
	sf::String* pPlayerInput;
	unsigned* pCurrentScore;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Text name;
	sf::Text info1;
	sf::Text info2;
	std::regex nameRegex;
	bool drawHelp;

public:
	GameOver(Resources& _resources, Ladderboard& _ladderboard, sf::String& _playerInput, unsigned& _currentScore);
	void setDrawHelp(bool _value);
	bool checkIfNameIsValid();
	void update();
	void render(sf::RenderTarget& _target);
};

