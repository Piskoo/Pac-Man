#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(std::filesystem::path _texturePath, unsigned _animationTime) :
	texture(sf::Texture()), 
	sprite(sf::Sprite()), 
	animationTime(_animationTime),
	currentFrame(0)
{
	texture.loadFromFile(_texturePath.string());
	numberOfFrames = static_cast<unsigned>(round(texture.getSize().x / 32));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setOrigin(static_cast<float>(texture.getSize().x / 2 / numberOfFrames), static_cast<float>(texture.getSize().y / 2));
}

sf::Sprite& AnimatedSprite::getSprite()
{
	return sprite;
}
void AnimatedSprite::setTexture(sf::Texture& _texture) 
{
	texture = _texture;
}

void AnimatedSprite::update() 
{
	if (static_cast<unsigned>(clock.getElapsedTime().asMilliseconds()) >= animationTime / numberOfFrames * (currentFrame + 1))
	{
		++currentFrame;
		sprite.setTextureRect(sf::IntRect(32 * currentFrame, 0, 32, 32));
	}
	if (static_cast<unsigned>(clock.getElapsedTime().asMilliseconds()) >= animationTime)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		clock.restart();
		currentFrame = 0;
	}
}


