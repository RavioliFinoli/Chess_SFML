#include "Rook.h"
#include "ChessBoard.h"


void Rook::Initialize(sf::Color PlayerColor, sf::Vector2f Position)
{
	sf::String fileName = "../Resources/RookTexture_";
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

bool Rook::IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination)
{
	//Check if Origin and Destination are equal; if so, act as if move is illegal
	{
		if (Origin == Destination)
			return false;
	}

	int DeltaX = Origin.x - Destination.x;
	int DeltaY = Origin.y - Destination.y;

	//Early return; Rooks can only move in one axis at a time
	{
		if (DeltaX != 0 && DeltaY != 0)
			return false;
	}

	//Check if any pieces are blocking our path
	{

		//Moving vertically (column)
		if (DeltaY != 0)
		{
			int DirectionMultiplier = (DeltaY > 0 ? -1 : 1);
			for (int i = 0; i < abs(DeltaY); i++)
			{
				ChessPiece* PieceOnSquare = Board->GetSquare(Origin.x, Origin.y + (i * DirectionMultiplier))->GetPieceOccupyingSquare();
				if (PieceOnSquare)
					return false;
			}
		}
		else
		{
			int DirectionMultiplier = (DeltaX > 0 ? -1 : 1);
			for (int i = 0; i < abs(DeltaX); i++)
			{
				ChessPiece* PieceOnSquare = Board->GetSquare(Origin.x + (i * DirectionMultiplier), Origin.y)->GetPieceOccupyingSquare();
				if (PieceOnSquare)
					return false;
			}
		}
		return true;
	}
	
}

Rook::Rook()
{
}


Rook::~Rook()
{
}
