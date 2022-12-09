#include "GameOver.h"

GameOver::GameOver(Resources& _resources, Ladderboard& _ladderboard, sf::String& _playerInput, unsigned& _currentScore) :
	pResources(&_resources),
	pLadderboard(&_ladderboard),
	pPlayerInput(&_playerInput),
	pCurrentScore(&_currentScore),
	name("",pResources->basicFont, pResources->gameOverNameFontSize),
	info1("submit name", pResources->basicFont, pResources->gameOverNameFontSize/2),
	info2("(3-12 characters)", pResources->basicFont, pResources->gameOverNameFontSize/2),
	nameRegex("[A-Za-z]{3,12}"),
	drawHelp(false)
{
	texture.loadFromFile(pResources->pathGameOverImage.string());
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(static_cast<float>(pResources->windowWidth) / 2, static_cast<float>(pResources->windowHeight) / 2-100);

	name.setOrigin(name.getGlobalBounds().width / 2, name.getGlobalBounds().height / 2);
	name.setPosition(static_cast<float>(pResources->windowWidth) / 2, static_cast<float>(pResources->windowHeight / 2+ pResources->gameOverNameFontSize));
	info1.setOrigin(info1.getGlobalBounds().width / 2, info1.getGlobalBounds().height / 2);
	info1.setPosition(static_cast<float>(pResources->windowWidth) / 2, static_cast<float>(pResources->windowHeight / 2 + 3 * pResources->gameOverNameFontSize));
	info2.setOrigin(info2.getGlobalBounds().width / 2, info2.getGlobalBounds().height / 2);
	info2.setPosition(static_cast<float>(pResources->windowWidth) / 2, static_cast<float>(pResources->windowHeight / 2 + 3.5 * pResources->gameOverNameFontSize));
}

bool GameOver::checkIfNameIsValid() 
{
	if(std::regex_match(name.getString().toAnsiString(), nameRegex))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void GameOver::setDrawHelp(bool _value)
{
	drawHelp = _value;
}

void GameOver::update()
{
	name.setString(*pPlayerInput);
	name.setOrigin(name.getGlobalBounds().width / 2, name.getGlobalBounds().height / 2);
}

void GameOver::render(sf::RenderTarget& _target)
{
	_target.draw(sprite);
	_target.draw(name);
	if (drawHelp)
	{
		_target.draw(info1);
		_target.draw(info2);
	}
}