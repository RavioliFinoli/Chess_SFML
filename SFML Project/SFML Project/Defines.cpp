#include "Defines.h"
#include <SFML/Graphics.hpp>

sf::Vector2i GetSquareIndexUnderMouse(sf::Vector2i inBoardOrigin, sf::RenderWindow& inWindow)
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition(inWindow);
	sf::Vector2i Index;
	Index.x = (int)(((float)MousePosition.x - (float)inBoardOrigin.x) / (float)SQUARE_SIZE);
	Index.y = (int)(((float)MousePosition.y - (float)inBoardOrigin.y) / (float)SQUARE_SIZE);
	return Index;
}