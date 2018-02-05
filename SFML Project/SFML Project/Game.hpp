#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "ChessBoard.h"
#include "Pawn.h"
#include "Timer.h"

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float DeltaTime);
	void SetWindow(sf::RenderWindow* inWindow);

	void EndTurn();
private:
	sf::RenderWindow* mWindow;

	sf::Texture mBackgroundTex;
	sf::Text mPlayerTurnText;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;

	sf::Font mTimerFont;
	Timer* BlackTimer;
	Timer* WhiteTimer;

	sf::Color mColorOfCurrentPlayer = WHITE;

	ChessBoard mChessBoard;
	ChessPiece* mHeldPiece = nullptr;
	sf::Vector2u mHeldPieceOrigin = sf::Vector2u();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif