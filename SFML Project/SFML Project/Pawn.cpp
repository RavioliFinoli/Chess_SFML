#include "Pawn.h"
#include "ChessBoard.h"


void Pawn::Initialize(sf::Color PlayerColor, sf::Vector2f Position)
{
	sf::String fileName = "../Resources/PawnTexture_";
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

bool Pawn::IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination)
{
	//Check if Origin and Destination are equal; if so, act as if move is illegal
	{
		if (Origin == Destination)
			return false;
	}
	//Check if moving "forward"
	int DeltaX = Origin.x - Destination.x;
	int DeltaY = Origin.y - Destination.y;

	int ColorMultiplier = (mColor == WHITE ? 1 : -1);

	
	//White pieces move "up" to go forward, black moves down
	if (IsWithinRange(DeltaY*ColorMultiplier, 0, 2 - bHasMoved) && (DeltaX) == 0)
	{
		return true;
	}
	else if (DeltaY == ColorMultiplier && abs(DeltaX) == 1)
	{
		ChessPiece* PieceOnDestination = Board->GetSquare(Destination.x, Destination.y)->GetPieceOccupyingSquare();
		sf::Color ColorOfPieceOnDestination;
		if (PieceOnDestination)
		{
			ColorOfPieceOnDestination = PieceOnDestination->GetColor();
			if (ColorOfPieceOnDestination != mColor)
				return true;
			else return false;
		}
		else return false;
	}
	else
	{
		return false;
	}
}

Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}
