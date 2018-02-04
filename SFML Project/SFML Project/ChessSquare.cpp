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
	sf::String fileName = "../Resources/SquareTexture_";
	fileName += (inColor == sf::Color::Black ? "black.png" : "white.png");

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!mTexture.loadFromFile(fileName))
	{
		
	}

	Position = inPosition;
	PositionIndex = inPositionIndex;
	PieceOccupyingSquare = inPieceOccupying;

	mSprite.setSize(sf::Vector2f((float)SQUARE_SIZE, (float)SQUARE_SIZE));
	mSprite.setFillColor(inColor);
	mSprite.setTexture(&mTexture);
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
