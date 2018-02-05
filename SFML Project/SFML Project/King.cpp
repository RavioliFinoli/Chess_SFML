#include "King.h"
#include "Defines.h"
#include "ChessBoard.h"


void King::Initialize(sf::Color PlayerColor, sf::Vector2f Position)
{
	sf::String fileName = "../Resources/KingTexture_";
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

bool King::IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination)
{
	//Check if Origin and Destination are equal; if so, act as if move is illegal
	{
		if (Origin == Destination)
			return false;
	}

	int DeltaX = Origin.x - Destination.x;
	int DeltaY = Origin.y - Destination.y;

	if (abs(DeltaX) > 1 || abs(DeltaY) > 1)
		return false;
	else return true;
}


King::King()
{
}


King::~King()
{
}
