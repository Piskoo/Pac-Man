#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <string>
#include <filesystem>
#include "TileType.h"
#include "WallType.h"
#include "Resources.h"

//dodac wczytywanie mapy i maski mapy z pliku. nastepnie uzupelnic brakujace miejsca w resetach z klasie game. (2)

class Map
{
	Resources* pResources;
	std::vector<std::vector<unsigned>> mapLayout;
	std::vector<std::vector<unsigned>> wallTypes;

	sf::VertexArray tilesArray;
	sf::Texture texture;
	unsigned dotsCount;

	void fillVertexArray();
public:
	Map(Resources& _resources);
	~Map() = default;
	void buildAMap();
	std::vector<std::vector<unsigned>>& getMap();
	const unsigned getEmptySpaceID() const;
	const unsigned getWallID() const;
	const unsigned getSmallDotID() const;
	const unsigned getBigDotID() const;
	const unsigned getWarpID() const;
	const unsigned getGhostGateID() const;
	const unsigned getPacManSpawnPointID() const;
	const unsigned getDotsCount() const;

	sf::Vector2f getPositionOf(unsigned _tiletype);

	void setDotToEmptySpace(sf::Vector2f& _position);
	void render(sf::RenderTarget& _target);
};

