#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>
#include "Resources.h"
#include <ranges>

class Ladderboard
{
	Resources* pResources;
	Button back;
	std::vector<std::pair<int, std::string>> fileData;
	std::vector<sf::Text> ladderData;
	sf::Text name;
	sf::Text score;


public:
	Ladderboard(Resources& _resources);
	~Ladderboard() = default;
	unsigned getHighestScore();
	unsigned getLowestScore();
	bool pointsHigherThanLowestScore(unsigned& _points);
	void putIntoPositions();
	void saveNewScore(const std::string _name, const unsigned _points);
	void saveToFile();
	void render(sf::RenderTarget& _target);

};
