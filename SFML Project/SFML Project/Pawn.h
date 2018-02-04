#pragma once
#include "ChessPiece.h"
#include "Defines.h"

class Pawn :
	public ChessPiece
{
public:
	void Initialize(sf::Color PlayerColor, sf::Vector2f Position) override;
	bool IsMoveLegal(sf::Vector2u Origin, sf::Vector2u Destination) override;
	Pawn();
	~Pawn();
};

