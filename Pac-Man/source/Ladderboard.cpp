#include "Ladderboard.h"

Ladderboard::Ladderboard(Resources& _resources) :
	pResources(&_resources),
	back(_resources.basicFont, "Back", _resources.ladderboardFontSize, sf::Vector2f(static_cast<float>(_resources.windowWidth / 2), 
		static_cast<float>(_resources.windowHeight / 8 * 7))),
	name("Name", _resources.basicFont, _resources.ladderboardFontSize),
	score("Score", _resources.basicFont, _resources.ladderboardFontSize)
{
	back.setColor(sf::Color::Yellow);
	name.setPosition(sf::Vector2f(70, static_cast<float>(120)));
	score.setPosition(sf::Vector2f(420, static_cast<float>(120)));
	name.setFillColor(sf::Color::Yellow);
	score.setFillColor(sf::Color::Yellow);
	std::fstream file;
	file.open(_resources.pathLadderboard, std::ios::in);
	std::string temp;
	std::string line;

	if (file.is_open()) 
	{
		while (std::getline(file, line))
		{
			std::string word;
			std::stringstream ss(line);
			std::pair<int,std::string> tempPair;
			std::getline(ss, word, ',');
			tempPair.second = word;			
			std::getline(ss, word, ',');
			tempPair.first = stoi(word);
			fileData.push_back(tempPair);
		}
		file.close();
	}
	std::ranges::sort(fileData, std::ranges::greater{});
	size_t numberOfRecords = fileData.size();
	if (numberOfRecords > 10) 
	{
		numberOfRecords = 10;
	}
	for (size_t i = 0; i != numberOfRecords; i++)
	{
		ladderData.push_back(sf::Text(fileData[i].second, _resources.basicFont, _resources.ladderboardFontSize));
		ladderData.push_back(sf::Text(std::to_string(fileData[i].first), _resources.basicFont, _resources.ladderboardFontSize));
	}
	putIntoPositions();
}

void Ladderboard::putIntoPositions()
{
	for (int i = 0; i != ladderData.size(); ++i)
	{
		if (i % 2 == 0)
		{
			ladderData[i].setPosition(sf::Vector2f(70, static_cast<float>(120 + pResources->ladderboardFontSize * 1.7 + pResources->ladderboardFontSize * 1.7 * (i / 2))));
		}
		else
		{
			ladderData[i].setPosition(sf::Vector2f(420, static_cast<float>(120 + pResources->ladderboardFontSize * 1.7 + pResources->ladderboardFontSize * 1.7 * (i / 2))));
		}
	}
}

unsigned Ladderboard::getHighestScore() 
{
	if (ladderData.size() > 0) 
	{
		return std::stoi(((ladderData.begin()+1)->getString().toAnsiString()));
	}
	else 
	{
		return 0;
	}
}
unsigned Ladderboard::getLowestScore()
{
	if (ladderData.size() >= 20 )
	{
	return std::stoi((ladderData.end() - 1)->getString().toAnsiString());
	}
	else
	{
		return 0;
	}
}

bool Ladderboard::pointsHigherThanLowestScore(unsigned& _points)
{
	if (_points > getLowestScore()) 
	{
		return true;
	}
	else
	{
		return false;
	}
}



void Ladderboard::saveToFile()
{
	std::ofstream file;
	file.open(pResources->pathLadderboard, std::ios::trunc || std::ios::out);
	if (file.is_open())
	{
		for(size_t i = 0; i != ladderData.size() - 2; i+=2)
		{
			file << ladderData[i].getString().toAnsiString() << ',' << ladderData[i + 1].getString().toAnsiString() << std::endl;
		}
		file << ladderData[ladderData.size() - 2].getString().toAnsiString() << ',' << ladderData[ladderData.size() - 1].getString().toAnsiString();
		file.close();
	}
}

void Ladderboard::saveNewScore(const std::string _name, const unsigned _points)
{
	if (ladderData.size() >= 2)
	{
		for (int i = 1; i < ladderData.size(); i += 2)
		{
			if (static_cast<float>(std::stoi(ladderData[i].getString().toAnsiString())) < _points && ladderData.size() <= 20)
			{
				ladderData.insert(ladderData.begin() + i - 1, sf::Text(_name, pResources->basicFont, pResources->ladderboardFontSize));
				ladderData.insert(ladderData.begin() + i, sf::Text(std::to_string(_points), pResources->basicFont, pResources->ladderboardFontSize));
				break;
			}

		}
		if (ladderData.size() < 20)
		{
			ladderData.push_back(sf::Text(_name, pResources->basicFont, pResources->ladderboardFontSize));
			ladderData.push_back(sf::Text(std::to_string(_points), pResources->basicFont, pResources->ladderboardFontSize));
		}
		else if (ladderData.size() > 20)
		{
			ladderData.pop_back();
			ladderData.pop_back();
		}
	}
	else
	{
		ladderData.push_back(sf::Text(_name, pResources->basicFont, pResources->ladderboardFontSize));
		ladderData.push_back(sf::Text(std::to_string(_points), pResources->basicFont, pResources->ladderboardFontSize));
	}
	putIntoPositions();
	saveToFile();
}

void Ladderboard::render(sf::RenderTarget& _target)
{
	_target.draw(name);
	_target.draw(score);
	for(auto &i : ladderData)
	{
		_target.draw(i);
	}
	back.render(_target);
}
