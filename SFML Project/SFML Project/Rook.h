#pragma once
#include "ChessPiece.h"
#include "Defines.h"

class ChessBoard;

class Rook :
	public ChessPiece
{
public:
	void Initialize(sf::Color PlayerColor, sf::Vector2f Position) override;
	bool IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination) override;
	Rook();
	~Rook();
};
