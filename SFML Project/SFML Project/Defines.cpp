#include "Defines.h"
#include "ChessPiece.h"
#include <SFML/Graphics.hpp>
#include <assert.h>

sf::Vector2i GetSquareIndexUnderMouse(sf::Vector2i inBoardOrigin, sf::RenderWindow& inWindow)
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition(inWindow);
	sf::Vector2i Index;
	Index.x = (int)(((float)MousePosition.x - (float)inBoardOrigin.x) / (float)SQUARE_SIZE);
	Index.y = (int)(((float)MousePosition.y - (float)inBoardOrigin.y) / (float)SQUARE_SIZE);
	return Index;
}

bool SquareIndexIsValid(sf::Vector2i Index)
{
	return (Index.x < 8 && Index.y < 8 && Index.x > -1 && Index.y > -1);
}

bool IsWithinRange(int x, int min, int max)
{
	return (x >= min && x <= max);
}

void RemovePiece(std::vector<ChessPiece*>& Pieces, ChessPiece* PieceToRemove)
{
	assert(PieceToRemove);

	for (int i = 0; i < Pieces.size(); i++)
	{
		if (Pieces[i] = PieceToRemove)
		{
			Pieces.erase(Pieces.begin() + i);
			delete PieceToRemove;
		}
	}
}
