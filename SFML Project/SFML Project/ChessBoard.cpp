#include "ChessBoard.h"



ChessBoard::ChessBoard()
{
	bool bIsBlack = true;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{

			sf::Vector2f SquarePosition((float)SQUARE_SIZE * col, (float)SQUARE_SIZE * row);
			sf::Color SquareColor = (bIsBlack ? sf::Color::Green : sf::Color::White);
			Squares[row][col] = new ChessSquare();
			Squares[row][col]->Initialize(SquareColor, sf::Vector2u(row, col), SquarePosition);

			if (row == 6)
			{
				ChessPiece* pawn = new Pawn();
				pawn->Initialize(sf::Color::White, SquarePosition);
				Pawns.push_back(pawn);
				Squares[row][col]->SetPieceOccupyingSquare(Pawns.back());
			}
			if (row == 1)
			{
				ChessPiece* pawn = new Pawn();
				pawn->Initialize(sf::Color::Black, SquarePosition);
				Pawns.push_back(pawn);
				Squares[row][col]->SetPieceOccupyingSquare(Pawns.back());
			}


			if (col != 7)
				bIsBlack = !bIsBlack;
		}
	}
}


ChessBoard::~ChessBoard()
{
}

void ChessBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			target.draw(*Squares[row][col], states);
		}
	}

	for (auto& pawn : Pawns)
		target.draw(*pawn, states);
}

ChessSquare* ChessBoard::GetSquare(int row, int col)
{
	return Squares[col][row];
}
