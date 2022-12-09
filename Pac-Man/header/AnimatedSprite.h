#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>

class AnimatedSprite
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	unsigned numberOfFrames;
	unsigned animationTime;
	unsigned currentFrame;
public:
	AnimatedSprite(std::filesystem::path _texturePath, unsigned _animationTime);
	~AnimatedSprite() = default;
	sf::Sprite& getSprite();
	void setTexture(sf::Texture& _texture);
	void update();
};

