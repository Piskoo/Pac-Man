#include "Menu.h"

Menu::Menu(Resources& _resources, float& _frameTime) : 
	pResources(&_resources),
	isSelectedPlay(1), 
	isSelectedLadderboard(0), 
	isSelectedQuit(0),
	play(pResources->basicFont, "Play", pResources->menuFontSize, sf::Vector2f(static_cast<float>(pResources->windowWidth / 2), static_cast<float>(pResources->windowHeight / 8 * 5))),
	ladderboard(pResources->basicFont, "LADDERBOARD", pResources->menuFontSize, sf::Vector2f(static_cast<float>(pResources->windowWidth / 2), static_cast<float>(pResources->windowHeight / 8 * 6))),
	quit(pResources->basicFont, "QUIT", pResources->menuFontSize, sf::Vector2f(static_cast<float>(pResources->windowWidth / 2), static_cast<float>(pResources->windowHeight / 8 * 7))),
	pacman(sf::Text("pac-man", pResources->logoFont, pResources->logoFontSize)),
	velocity(0),
	pFrameTime(&_frameTime)
{
	pacman.setFillColor(sf::Color::Yellow);
	pacman.setOutlineColor(sf::Color::Yellow);
	pacman.setOrigin(pacman.getGlobalBounds().width / 2, pacman.getGlobalBounds().height / 2);
	pacman.setPosition(static_cast<float>(_resources.windowWidth / 2), static_cast<float>(_resources.windowHeight / 8 * 2));

	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathScaredGhostTexture, pResources->pacmanAnimationTimeInMilisec));
	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathPacManTexture, pResources->pacmanAnimationTimeInMilisec));
	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathRedGhostTexture, pResources->pacmanAnimationTimeInMilisec));
	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathPinkGhostTexture, pResources->pacmanAnimationTimeInMilisec));
	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathBlueGhostTexture, pResources->pacmanAnimationTimeInMilisec));
	characters.push_back(std::make_shared<AnimatedSprite>(pResources->pathOrangeGhostTexture, pResources->pacmanAnimationTimeInMilisec));

	characters[0]->getSprite().setPosition(sf::Vector2f(320.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
	characters[1]->getSprite().setPosition(sf::Vector2f(256.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
	characters[2]->getSprite().setPosition(sf::Vector2f(120.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
	characters[3]->getSprite().setPosition(sf::Vector2f(80.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
	characters[4]->getSprite().setPosition(sf::Vector2f(40.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
	characters[5]->getSprite().setPosition(sf::Vector2f(0.f, static_cast<float>(pResources->windowHeight / 8 * 3)));
}

void Menu::higlightActiveButton() 
{
	if (isSelectedPlay == 1)
	{
		play.setColor(sf::Color::Yellow);
		ladderboard.setColor(sf::Color::White);
		quit.setColor(sf::Color::White);
	}
	else if (isSelectedLadderboard == 1)
	{
		play.setColor(sf::Color::White);
		ladderboard.setColor(sf::Color::Yellow);
		quit.setColor(sf::Color::White);
	}
	else if (isSelectedQuit == 1)
	{
		play.setColor(sf::Color::White);
		ladderboard.setColor(sf::Color::White);
		quit.setColor(sf::Color::Yellow);
	}
}

void Menu::menuMoveUp()
{
	if (isSelectedLadderboard == 1)
	{
		isSelectedLadderboard = 0;
		isSelectedPlay = 1;
	}
	else if (isSelectedQuit == 1)
	{
		isSelectedQuit = 0;
		isSelectedLadderboard = 1;
	}
}

void Menu::menuMoveDown()
{
	if (isSelectedLadderboard == 1)
	{
		isSelectedLadderboard = 0;
		isSelectedQuit = 1;
	}
	else if (isSelectedPlay == 1)
	{
		isSelectedPlay = 0;
		isSelectedLadderboard = 1;
	}
}

bool Menu::getIsSelectedPlay()
{
	return isSelectedPlay;
}
bool Menu::getIsSelectedLadderboard() 
{
	return isSelectedLadderboard;
}
bool Menu::getIsSelectedQuit() 
{
	return isSelectedQuit;
}

void Menu::setAnimationVelocity()
{
	velocity = pResources->pacmanUnitsPerSecond * (*pFrameTime);
}

void Menu::update()
{
	//if ((player.getSprite().getPosition().y != pResources->windowHeight / 8 * 3) || (player.getSprite().getPosition().x > pResources->windowWidth+32)) 
	//{
	//	player.getSprite().setPosition(-16.f, static_cast<float>(pResources->windowHeight / 8 * 3));
	//}
	setAnimationVelocity();
	for (auto& i : characters) 
	{
		i->getSprite().move(velocity, 0);
		i->update();
		if (i->getSprite().getPosition().x > pResources->windowWidth + pResources->tileSize) 
		{
			i->getSprite().setPosition(-16.f, static_cast<float>(pResources->windowHeight / 8 * 3));
		}
	}
	higlightActiveButton();
}

void Menu::render(sf::RenderTarget& _target)
{
	_target.draw(pacman);
	play.render(_target);
	ladderboard.render(_target);
	quit.render(_target);
	for (auto& i : characters) 
	{
		_target.draw(i->getSprite());
	}

}