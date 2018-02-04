#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}


ChessPiece::~ChessPiece()
{
}

void ChessPiece::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void ChessPiece::SetPosition(sf::Vector2f inPosition)
{
	mSprite.setPosition(inPosition);
}

void ChessPiece::SetHasMoved(bool Value)
{
	bHasMoved = Value;
}

sf::Color ChessPiece::GetColor()
{
	return mColor;
}
