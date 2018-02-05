#pragma once
#include "ChessPiece.h"
class Queen :
	public ChessPiece
{
public:
	void Initialize(sf::Color PlayerColor, sf::Vector2f Position) override;
	bool IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination) override;

	Queen();
	~Queen();
};

