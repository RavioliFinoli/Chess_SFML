#include "ChessSquare.h"
#include "Defines.h"


ChessSquare::ChessSquare()
{
}


ChessSquare::~ChessSquare()
{
}

void ChessSquare::Initialize(sf::Color inColor, sf::Vector2u inPositionIndex, sf::Vector2f inPosition, ChessPiece* inPieceOccupying)
{
	Position = inPosition;
	PositionIndex = inPositionIndex;
	PieceOccupyingSquare = inPieceOccupying;

	mSprite.setSize(sf::Vector2f((float)SQUARE_SIZE, (float)SQUARE_SIZE));
	mSprite.setFillColor(inColor);
	mSprite.setPosition(Position);
}

ChessPiece* ChessSquare::GetPieceOccupyingSquare()
{
	return PieceOccupyingSquare;
}

void ChessSquare::SetPieceOccupyingSquare(ChessPiece* inPiece)
{
	PieceOccupyingSquare = inPiece;
}

sf::Vector2f ChessSquare::GetPosition()
{
	return Position;
}

void ChessSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite);
}
