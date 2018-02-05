#pragma once
#include <SFML/Graphics.hpp>
#define SQUARE_SIZE 128
#define LEFT_SIDE_OFFSET 256
#define BLACK sf::Color::Black 
#define WHITE sf::Color::White 
//

class ChessPiece;

sf::Vector2i GetSquareIndexUnderMouse(sf::Vector2i inBoardOrigin, sf::RenderWindow& inWindow);
bool SquareIndexIsValid(sf::Vector2i Index);
bool IsWithinRange(int x, int min, int max);
void RemovePiece(std::vector<ChessPiece*>* Pieces, ChessPiece* PieceToRemove);