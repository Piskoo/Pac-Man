#include "Hud.h"

Hud::Hud(Resources& _resources, Ladderboard& _ladderboard, unsigned& _currentScore, unsigned& _lifesCount) :
	pResources(&_resources),
	pLadderboard(&_ladderboard),
	pCurrentScore(&_currentScore),
	pLifesCount(&_lifesCount),
	lifeTexture(sf::Texture()),
	oneUp(sf::Text("1UP", _resources.basicFont, _resources.hudFontSize)),
	highScore(sf::Text("HIGH SCORE", _resources.basicFont, _resources.hudFontSize)),
	currentPoints(sf::Text("0", _resources.basicFont, _resources.hudFontSize)),
	highestPoints(sf::Text("0", _resources.basicFont, _resources.hudFontSize))
{
	oneUp.setPosition(static_cast<float>(pResources->windowWidth / 6), 0.f);
	oneUp.setOrigin(oneUp.getGlobalBounds().width/2, 0.f);
	highScore.setPosition(static_cast<float>(pResources->windowWidth / 2), 0.f);
	highScore.setOrigin(highScore.getGlobalBounds().width / 2, 0.f);
	currentPoints.setPosition(static_cast<float>(pResources->windowWidth / 6), static_cast<float>(pResources->hudFontSize));
	currentPoints.setOrigin(currentPoints.getGlobalBounds().width / 2, 0.f);
	highestPoints.setPosition(static_cast<float>(pResources->windowWidth / 2) - static_cast<float>(pResources->hudFontSize / 2), static_cast<float>(pResources->hudFontSize));
	highestPoints.setOrigin(highestPoints.getGlobalBounds().width / 2, 0.f);

	lifeTexture.loadFromFile(pResources->pathPacManTexture.string());
	lifesArray.setPrimitiveType(sf::Quads);
	lifesArray.resize(1);
}

void Hud::update()
{
	currentPoints.setString(std::to_string(*pCurrentScore));
	currentPoints.setOrigin(currentPoints.getGlobalBounds().width / 2, 0.f);
	if (pLadderboard->getHighestScore() > *pCurrentScore)
	{
		highestPoints.setString(std::to_string(pLadderboard->getHighestScore()));
	}
	else 
	{
		highestPoints.setString(std::to_string(*pCurrentScore));
	}
	highestPoints.setOrigin(highestPoints.getGlobalBounds().width / 2, 0.f);
	if (lifesArray.getVertexCount() != (*pLifesCount) * 4)
	{
		lifesArray.resize((*pLifesCount)*4);
		for (size_t i = 0; i != (*pLifesCount) * 4; i += 4)
		{
			sf::Vertex* quad = &lifesArray[i];
			quad[0].position = sf::Vector2f(static_cast<float>(32 + i * 3 + 8 * i), static_cast<float>(pResources->windowHeight - 36));
			quad[1].position = sf::Vector2f(static_cast<float>(32 + i * 3 + 8 * (i + 4)), static_cast<float>(pResources->windowHeight - 36));
			quad[2].position = sf::Vector2f(static_cast<float>(32 + i * 3 + 8 * (i + 4)), static_cast<float>(pResources->windowHeight - 4));
			quad[3].position = sf::Vector2f(static_cast<float>(32 + i * 3 + 8 * i), static_cast<float>(pResources->windowHeight - 4));
			quad[0].texCoords = sf::Vector2f(96.f, 0.f);
			quad[1].texCoords = sf::Vector2f(64.f, 0.f);
			quad[2].texCoords = sf::Vector2f(64.f, 32.f);
			quad[3].texCoords = sf::Vector2f(96.f, 32.f);
		}
	}
}
void Hud::render(sf::RenderTarget& _target)
{
	_target.draw(oneUp);
	_target.draw(highScore);
	_target.draw(currentPoints);
	_target.draw(highestPoints);
	_target.draw(lifesArray, &lifeTexture);
}