#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <filesystem>

class Button
{
	sf::Text text;
	sf::RectangleShape rectangle;
public:
	Button(sf::Font& _font, std::string _text, int _fontSize, sf::Vector2f _position);
	~Button() = default;
	const sf::FloatRect getGlobalBounds();
	const sf::Text& getText();
	const sf::RectangleShape& getRectangleShape();
	void setColor(sf::Color _color);
	void render(sf::RenderTarget& _target);
};

