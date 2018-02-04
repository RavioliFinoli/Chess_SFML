#pragma once
#include <SFML\Graphics.hpp>

class ChessBoard;

class ChessPiece :
	public sf::Drawable
{
public:
	ChessPiece();
	~ChessPiece();
	virtual void Initialize(sf::Color PlayerColor, sf::Vector2f Position) = 0;

protected:

	sf::Color mColor;
	sf::RectangleShape mSprite;
	sf::Texture mTexture;
	bool bHasMoved = false;

public:
	virtual bool IsMoveLegal(ChessBoard* Board, sf::Vector2u Origin, sf::Vector2u Destination) = 0;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	void SetPosition(sf::Vector2f inPosition);
	void SetHasMoved(bool Value);
	sf::Color GetColor();
};

