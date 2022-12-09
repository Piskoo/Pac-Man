#include "Button.h"

Button::Button(sf::Font& _font, std::string _text, int _fontSize, sf::Vector2f _position) :
	text(sf::Text(_text, _font, _fontSize))
{
	text.setPosition(_position);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	rectangle.setSize(sf::Vector2f(static_cast<float>(_fontSize*1.2 * _text.size()), static_cast<float>(_fontSize*1.5)));
	rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
	rectangle.setPosition(sf::Vector2f(_position.x+3,_position.y+3));
	rectangle.setFillColor(sf::Color(100,100,100));
}

const sf::FloatRect Button::getGlobalBounds() 
{
	return rectangle.getGlobalBounds();
}

const sf::Text& Button::getText() 
{
	return text;
}

const sf::RectangleShape& Button::getRectangleShape() 
{
	return rectangle;
}

void Button::setColor(sf::Color _color)
{
	text.setFillColor(_color);
}

void Button::render(sf::RenderTarget& _target)
{
	_target.draw(rectangle);
	_target.draw(text);
}