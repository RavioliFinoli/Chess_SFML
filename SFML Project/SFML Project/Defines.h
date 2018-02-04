#pragma once
#include <SFML/Graphics.hpp>
#define SQUARE_SIZE 64
#define BLACK sf::Color::Black 
#define WHITE sf::Color::White 
//

sf::Vector2i GetSquareIndexUnderMouse(sf::Vector2i inBoardOrigin, sf::RenderWindow& inWindow);

bool IsWithinRange(int x, int min, int max);
