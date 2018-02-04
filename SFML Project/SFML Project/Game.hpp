#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "ChessBoard.h"
#include "Pawn.h"

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float DeltaTime);
	void SetWindow(sf::RenderWindow* inWindow);
private:
	sf::RenderWindow* mWindow;

	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;


	ChessBoard mChessBoard;

	ChessPiece* mHeldPiece = nullptr;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif