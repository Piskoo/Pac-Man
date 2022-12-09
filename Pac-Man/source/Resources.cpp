#include "Resources.h"

Resources::Resources() 
{
	basicFont.loadFromFile(pathBasicFont.string());
	logoFont.loadFromFile(pathLogoFont.string());
}