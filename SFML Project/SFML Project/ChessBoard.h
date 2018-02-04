#pragma once
#include <SFML\Graphics.hpp>
#include "Pawn.h"
#include "ChessSquare.h"
#include <vector>

class ChessBoard :
	public sf::Drawable
{
public:
	ChessBoard();
	~ChessBoard();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	std::vector<ChessPiece*>* GetPiecesVector();
	ChessSquare* GetSquare(int row, int col);
private:
	ChessSquare* Squares[8][8];

	std::vector<ChessPiece*> Pawns;
};

