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
	return false;
}

Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}
