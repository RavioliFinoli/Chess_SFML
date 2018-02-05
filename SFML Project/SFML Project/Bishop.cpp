#include "Bishop.h"
#include "Defines.h"
#include "ChessBoard.h"


void Bishop::Initialize(sf::Color PlayerColor, sf::Vector2f Position)
{
	sf::String fileName = "../Resources/BishopTexture_";
	fileName += (PlayerColor == sf::Color::Black ? "black.png" : "white.png");

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!mTexture.loadFromFile(fileName))
	{
		fileName;
	}
	Position += mSprite.getOrigin();
	mSprite.setPosition(Position);
	mSprite.setSize(sf::Vector2f((float)SQUARE_SIZE, (float)SQUARE_SIZE));
	mSprite.setTexture(&mTexture);
	mColor = PlayerColor;
}

bool Bishop::IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination)
{
	//Check if Origin and Destination are equal; if so, act as if move is illegal
	{
		if (Origin == Destination)
			return false;
	}

	int DeltaX = Origin.x - Destination.x;
	int DeltaY = Origin.y - Destination.y;

	if (abs(DeltaX) == abs(DeltaY))
	{
		//Are we moving positively in X? (Right)
		int XModifier = (DeltaX < 0 ? 1 : -1);

		//Are we moving positively in Y? (Down)
		int YModifier = (DeltaY < 0 ? 1 : -1);

		for (int i = 0; i < abs(DeltaX); ++i)
		{
			ChessPiece* PieceOnSquare = Board->GetSquare(Origin.x + (i * XModifier), Origin.y + (i * YModifier))->GetPieceOccupyingSquare();
			if (PieceOnSquare)
				return false;
		}
		return true;
	}

	return false;
}

Bishop::Bishop()
{
}


Bishop::~Bishop()
{
}
