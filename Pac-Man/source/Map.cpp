#include "Map.h"

Map::Map(Resources& _resources) :
	pResources(&_resources),
	texture(), 
	dotsCount(0)
{
	buildAMap();
	texture.loadFromFile(_resources.pathStaticObejctTextures.string());
	tilesArray.setPrimitiveType(sf::Quads);
}

std::vector<std::vector<unsigned>>& Map::getMap() 
{
	return mapLayout;
}

void Map::buildAMap()
{
	mapLayout =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //0
	{1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1}, //1
	{1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1}, //2
	{1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1}, //3
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1}, //4
	{1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1}, //5
	{1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1}, //6
	{1,1,1,1,2,1,1,1,0,1,0,1,1,1,2,1,1,1,1}, //7
	{0,0,0,1,2,1,0,0,0,7,0,0,0,1,2,1,0,0,0}, //8
	{1,1,1,1,2,1,0,1,1,5,1,1,0,1,2,1,1,1,1}, //9
	{4,0,0,0,2,0,0,1,9,8,10,1,0,0,2,0,0,0,4}, //10
	{1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1}, //11
	{0,0,0,1,2,1,0,0,0,0,0,0,0,1,2,1,0,0,0}, //12
	{1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1}, //13
	{1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1}, //14
	{1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1}, //15
	{1,3,2,1,2,2,2,2,2,6,2,2,2,2,2,1,2,3,1}, //16
	{1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1}, //17
	{1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1}, //18
	{1,2,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,2,1}, //19
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1}, //20
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //21
	};

	wallTypes =
	{
	{2,	0,	0,	0,	0,	0,	0,	0,	0,	10,	0,	0,	0,	0,	0,	0,	0,	0,	3}, //1
	{1,	88,	88,	88,	88,	88,	88,	88,	88,	1,	88,	88,	88,	88,	88,	88,	88,	88,	1}, //2
	{1,	88,	2,	3,	88,	2,	0,	3,	88,	1,	88,	2,	0,	3,	88,	2,	3,	88,	1}, //3
	{1,	88,	5,	4,	88,	5,	0,	4,	88,	9,	88,	5,	0,	4,	88,	5,	4,	88,	1}, //4
	{1,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	1}, //5
	{1,	88,	6,	7,	88,	8,	88,	6,	0,	10,	0,	7,	88,	8,	88,	6,	7,	88,	1}, //6
	{1,	88,	88,	88,	88,	1,	88,	88,	88,	1,	88,	88,	88,	1,	88,	88,	88,	88,	1}, //7
	{5,	0,	0,	3,	88,	12,	0,	7,	88,	9,	88,	6,	0,	13,	88,	2,	0,	0,	4}, //8
	{88,88,	88,	1,	88,	1,	88,	88,	88,	88,	88,	88,	88,	1,	88,	1,	88,	88,	88}, //9
	{0,	0,	0,	4,	88,	9,	88,	2,	0,	88,	0,	3,	88,	9,	88,	5,	0,	0,	0}, //10
	{88,88,	88,	88,	88,	88,	88,	1,	88,	88,	88,	1,	88,	88,	88,	88,	88,	88,	88}, //11
	{0,	0,	0,	3,	88,	8,	88,	5,	0,	0,	0,	4,	88,	8,	88,	2,	0,	0,	0}, //12
	{88,88,	88,	1,	88,	1,	88,	88,	88,	88,	88,	88,	88,	1,	88,	1,	88,	88,	88}, //13
	{2,	0,	0,	4,	88,	9,	88,	6,	0,	10,	0,	7,	88,	9,	88,	5,	0,	0,	3}, //14
	{1,	88,	88,	88,	88,	88,	88,	88,	88,	1,	88,	88,	88,	88,	88,	88,	88,	88,	1}, //15
	{1,	88,	6,	3,	88,	6,	0,	7,	88,	9,	88,	6,	0,	7,	88,	2,	7,	88,	1}, //16
	{1,	88,	88,	1,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	1,	88,	88,	1}, //17
	{12,7,	88,	9,	88,	8,	88,	6,	0,	10,	0,	7,	88,	8,	88,	9,	88,	6,	13}, //18
	{1,	88,	88,	88,	88,	1,	88,	88,	88,	1,	88,	88,	88,	1,	88,	88,	88,	88,	1}, //19
	{1,	88,	6,	0,	0,	11,	0,	7,	88,	9,	88,	6,	0,	11,	0,	0,	7,	88,	1}, //20
	{1,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	1}, //21
	{5,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4}, //22
	};

	dotsCount = 0;

	for (auto& i : mapLayout)
	{
		for (auto j : i)
		{
			if (j == TileType::SmallDot || j == TileType::BigDot)
			{
				++dotsCount;
			}
		}
	}

	tilesArray.resize(4 * mapLayout[0].size() * mapLayout.size());
	fillVertexArray();
}

const unsigned Map::getEmptySpaceID() const
{
	return TileType::EmptySpace;
}

const unsigned Map::getWallID() const
{
	return TileType::Wall;
}

const unsigned Map::getSmallDotID() const
{
	return TileType::SmallDot;
}

const unsigned Map::getBigDotID() const
{
	return TileType::BigDot;
}

const unsigned Map::getWarpID() const
{
	return TileType::Warp;
}

const unsigned Map::getGhostGateID() const
{
	return TileType::GhostGate;
}

const unsigned Map::getPacManSpawnPointID() const
{
	return TileType::PacManSpawnPoint;
}

const unsigned Map::getDotsCount() const 
{
	return dotsCount;
}

sf::Vector2f Map::getPositionOf(unsigned _tiletype)
{
	sf::Vector2f spawnPoint(0,0);
	for (size_t i = 0; i != mapLayout.size(); ++i)
	{
		for (size_t j = 0; j != getMap()[i].size(); ++j)
		{
			if (mapLayout[i][j] == _tiletype)
			{
				spawnPoint.x = pResources->mapPixelOffsetWidth + j * pResources->tileSize + pResources->tileSize / 2;
				spawnPoint.y = pResources->mapPixelOffsetHeight + i * pResources->tileSize + pResources->tileSize / 2;
				break;
			}
		}
	}
	return spawnPoint;
}

void Map::fillVertexArray()
{
	for (size_t i = 0; i != mapLayout.size(); ++i)
	{
		for (size_t j = 0; j != mapLayout[i].size(); ++j)
		{
			sf::Vertex* quad = &tilesArray[(j + i * mapLayout[i].size()) * 4];
			quad[0].position = sf::Vector2f(pResources->mapPixelOffsetWidth + pResources->tileSize * j, pResources->mapPixelOffsetHeight + pResources->tileSize * i);
			quad[1].position = sf::Vector2f(pResources->mapPixelOffsetWidth + pResources->tileSize + pResources->tileSize * j, pResources->mapPixelOffsetHeight + pResources->tileSize * i);
			quad[2].position = sf::Vector2f(pResources->mapPixelOffsetWidth + pResources->tileSize + pResources->tileSize * j, pResources->mapPixelOffsetHeight + pResources->tileSize + pResources->tileSize * i);
			quad[3].position = sf::Vector2f(pResources->mapPixelOffsetWidth + pResources->tileSize * j, pResources->mapPixelOffsetHeight + pResources->tileSize + pResources->tileSize * i);
			if (mapLayout[i][j] == TileType::Wall)
			{
				quad[0].texCoords = sf::Vector2f(static_cast<float>(160 + 32 * wallTypes[i][j]), 0.f);
				quad[1].texCoords = sf::Vector2f(static_cast<float>(192 + 32 * wallTypes[i][j]), 0.f);
				quad[2].texCoords = sf::Vector2f(static_cast<float>(192 + 32 * wallTypes[i][j]), 32.f);
				quad[3].texCoords = sf::Vector2f(static_cast<float>(160 + 32 * wallTypes[i][j]), 32.f);
			}
			else if (mapLayout[i][j] == TileType::SmallDot)
			{
				quad[0].texCoords = sf::Vector2f(64.f, 0.f);
				quad[1].texCoords = sf::Vector2f(96.f, 0.f);
				quad[2].texCoords = sf::Vector2f(96.f, 32.f);
				quad[3].texCoords = sf::Vector2f(64.f, 32.f);
			}
			else if (mapLayout[i][j] == TileType::BigDot)
			{
				quad[0].texCoords = sf::Vector2f(96.f, 0.f);
				quad[1].texCoords = sf::Vector2f(128.f, 0.f);
				quad[2].texCoords = sf::Vector2f(128.f, 32.f);
				quad[3].texCoords = sf::Vector2f(96.f, 32.f);
			}
			else if (mapLayout[i][j] == TileType::GhostGate)
			{
				quad[0].texCoords = sf::Vector2f(128.f, 0.f);
				quad[1].texCoords = sf::Vector2f(160.f, 0.f);
				quad[2].texCoords = sf::Vector2f(160.f, 32.f);
				quad[3].texCoords = sf::Vector2f(128.f, 32.f);
			}
		}
	}
}

void Map::setDotToEmptySpace(sf::Vector2f& _position)
{
	mapLayout[static_cast<int>(_position.y)][static_cast<int>(_position.x)] = TileType::EmptySpace;
	sf::Vertex* quad = &tilesArray[(static_cast<int>(_position.x) + static_cast<int>(_position.y) * mapLayout[static_cast<int>(_position.y)].size()) * 4];
	quad[0].position = sf::Vector2f(
		pResources->mapPixelOffsetWidth + pResources->tileSize * static_cast<int>(_position.x),
		pResources->mapPixelOffsetHeight + pResources->tileSize * static_cast<int>(_position.y));
	quad[1].position = sf::Vector2f(
		pResources->mapPixelOffsetWidth + pResources->tileSize + pResources->tileSize * static_cast<int>(_position.x),
		pResources->mapPixelOffsetHeight + pResources->tileSize * static_cast<int>(_position.y));
	quad[2].position = sf::Vector2f(
		pResources->mapPixelOffsetWidth + pResources->tileSize + pResources->tileSize * static_cast<int>(_position.x),
		pResources->mapPixelOffsetHeight + pResources->tileSize + pResources->tileSize * static_cast<int>(_position.y));
	quad[3].position = sf::Vector2f(
		pResources->mapPixelOffsetWidth + pResources->tileSize * static_cast<int>(_position.x),
		pResources->mapPixelOffsetHeight + pResources->tileSize + pResources->tileSize * static_cast<int>(_position.y));
	quad[0].texCoords = sf::Vector2f(0.f, 0.f);
	quad[1].texCoords = sf::Vector2f(32.f, 0.f);
	quad[2].texCoords = sf::Vector2f(32.f, 32.f);
	quad[3].texCoords = sf::Vector2f(0.f, 32.f);
	--dotsCount;
}

void Map::render(sf::RenderTarget& _target)
{
	_target.draw(tilesArray, &(texture));
}