#include "Pawn.h"



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

bool Pawn::IsMoveLegal(sf::Vector2u Origin, sf::Vector2u Destination)
{
	//Check if moving "forward"
	int DeltaX = Origin.x - Destination.x;
	int DeltaY = Origin.y - Destination.y;

	int ColorMultiplier = (mColor == WHITE ? 1 : 1);

	
	//White pieces move "up" to go forward, black moves down
	if (IsWithinRange(DeltaY * ColorMultiplier, 0, 2*ColorMultiplier) && (DeltaX) == 0)
	{
		return true;
	}
	else if (DeltaY == 1 && abs(DeltaX) == 1)
	{
		return true;
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
