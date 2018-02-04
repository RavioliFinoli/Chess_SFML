#pragma once
#include <SFML\Graphics.hpp>

class ChessPiece;

class ChessSquare :
	public sf::Drawable
{
public:
	ChessSquare();
	~ChessSquare();
	void Initialize(sf::Color inColor, sf::Vector2u inPositionIndex, sf::Vector2f inPosition, ChessPiece* inPieceOccupying = nullptr);
public:

	ChessPiece* GetPieceOccupyingSquare();
	void SetPieceOccupyingSquare(ChessPiece* inPiece);
	sf::Vector2f GetPosition();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RectangleShape mSprite;

	ChessPiece* PieceOccupyingSquare = nullptr;
	sf::Vector2u PositionIndex;
	sf::Vector2f Position;
};

