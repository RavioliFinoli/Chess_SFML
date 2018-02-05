#include "ChessBoard.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include <assert.h>

ChessBoard::ChessBoard()
{
	bool bIsBlack = true;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{

			sf::Vector2f SquarePosition(LEFT_SIDE_OFFSET + (float)SQUARE_SIZE * col, (float)SQUARE_SIZE * row);
			sf::Color SquareColor = (bIsBlack ? sf::Color(0, 190, 0, 255) : sf::Color::White);
			Squares[row][col] = new ChessSquare();
			Squares[row][col]->Initialize(SquareColor, sf::Vector2u(row, col), SquarePosition);

			if (row == 6)
			{
				ChessPiece* pawn = new Pawn();
				pawn->Initialize(sf::Color::White, SquarePosition);
				Pieces.push_back(pawn);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			if (row == 1)
			{
				ChessPiece* pawn = new Pawn();
				pawn->Initialize(sf::Color::Black, SquarePosition);
				Pieces.push_back(pawn);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//Black Rooks
			if ((row == 0 && col == 0) || (row == 0 && col == 7))
			{
				ChessPiece* rook = new Rook();
				rook->Initialize(BLACK, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//White Rooks
			if ((row == 7 && col == 0) || (row == 7 && col == 7))
			{
				ChessPiece* rook = new Rook();
				rook->Initialize(WHITE, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}

			//Black Knights
			if ((row == 0 && col == 1) || (row == 0 && col == 6))
			{
				ChessPiece* rook = new Knight();
				rook->Initialize(BLACK, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//White Knights
			if ((row == 7 && col == 1) || (row == 7 && col == 6))
			{
				ChessPiece* rook = new Knight();
				rook->Initialize(WHITE, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}

			//Black Bishops
			if ((row == 0 && col == 2) || (row == 0 && col == 5))
			{
				ChessPiece* rook = new Bishop();
				rook->Initialize(BLACK, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//White Knights
			if ((row == 7 && col == 2) || (row == 7 && col == 5))
			{
				ChessPiece* rook = new Bishop();
				rook->Initialize(WHITE, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}

			//Black King
			if ((row == 0 && col == 4))
			{
				ChessPiece* rook = new King();
				rook->Initialize(BLACK, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//White King
			if ((row == 7 && col == 4) )
			{
				ChessPiece* rook = new King();
				rook->Initialize(WHITE, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}

			//Black Queen
			if ((row == 0 && col == 3))
			{
				ChessPiece* rook = new Queen();
				rook->Initialize(BLACK, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
			}
			//White Queen
			if ((row == 7 && col == 3))
			{
				ChessPiece* rook = new Queen();
				rook->Initialize(WHITE, SquarePosition);
				Pieces.push_back(rook);
				Squares[row][col]->SetPieceOccupyingSquare(Pieces.back());
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

	for (auto& pawn : Pieces)
		target.draw(*pawn, states);
}

std::vector<ChessPiece*>* ChessBoard::GetPiecesVector()
{
	return &Pieces;
}

ChessSquare* ChessBoard::GetSquare(int row, int col)
{
	assert(!(row < 0 || row > 7 || col < 0 || col > 7));

	return Squares[col][row];
}
