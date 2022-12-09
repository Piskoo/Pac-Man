#pragma once
#include <filesystem>
#include <SFML/Graphics.hpp>

class Resources
{
public:
	Resources();

	const std::string gameTitle = "Pac-Man";
	const unsigned windowWidth = 608;
	const unsigned windowHeight = 800;
	const unsigned short frameRate = 60;
	const float tileSize = 32;
	const unsigned mapPixelOffsetWidth = 0;
	const unsigned mapPixelOffsetHeight = 64;
	const unsigned pauseTimeInMilisecAfterWin = 3000;
	const unsigned noOfLifes = 4;

	const std::filesystem::path pathPacManTexture = "texture/pacman.png";
	const unsigned pacmanNumberOfAnimationFrames = 4;
	const unsigned pacmanAnimationTimeInMilisec = 500;
	const int pacmanUnitsPerSecond = 120;
	const unsigned pacmanEmpowermentStatusTimeInMilisec = 10000;

	const std::filesystem::path pathRedGhostTexture = "texture/redghost.png";
	const std::filesystem::path pathPinkGhostTexture = "texture/pinkghost.png";
	const std::filesystem::path pathBlueGhostTexture = "texture/blueghost.png";
	const std::filesystem::path pathOrangeGhostTexture = "texture/orangeghost.png";
	const std::filesystem::path pathScaredGhostTexture = "texture/scaredghost.png";
	const unsigned ghostNumberOfAnimationFrames = 4;
	const unsigned ghostAnimationTimeInMilisec = 500;


	const std::filesystem::path pathStaticObejctTextures = "texture/staticobjects.png";


	const std::filesystem::path pathBasicFont = "font/emulogic.ttf";
	sf::Font basicFont;
	const unsigned basicFontSize = 24;
	const unsigned hudFontSize = 24;
	const unsigned menuFontSize = 24;


	const std::filesystem::path pathLogoFont = "font/PAC-FONT.ttf";
	sf::Font logoFont;
	const unsigned logoFontSize = 72;

	const std::filesystem::path pathLadderboard = "ladder/ladder.csv";
	const unsigned ladderboardFontSize = 24;

	const std::filesystem::path pathGameOverImage = "texture/gameover.png";
	const std::filesystem::path pathDeathSound = "sound/death.wav";
	const unsigned gameOverNameFontSize = 24;



};

