#include "Game.hpp"
#include <iostream>

Game::Game() :mPlayer(1)
{
	if (!mBackgroundTex.loadFromFile("../Resources/background.jpg"))
	{
		// Handle error: Print error message.
		std::cout << "ERROR: Background image could not be loaded.\n---" << std::endl;
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
}

void Game::Update(float DeltaTime)
{
	// Make sure everything in the game is updated (if needed).
	mPlayer.Update(DeltaTime);

	sf::Vector2i Index = GetSquareIndexUnderMouse(sf::Vector2i(0, 0), *mWindow);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!mHeldPiece)
		{
			if (Index.x < 8 && Index.y < 8 && Index.x > -1 && Index.y > -1)
			{
				ChessSquare* Square = mChessBoard.GetSquare(Index.x, Index.y);
				ChessPiece* Piece = Square->GetPieceOccupyingSquare();
				if (Piece)
				{
					Square->SetPieceOccupyingSquare(nullptr);
					mHeldPiece = Piece;
					mHeldPieceOrigin = sf::Vector2u(Index.x, Index.y);
				}
			}
		}
		else
		{
			auto MousePosition = sf::Mouse::getPosition(*mWindow);
			sf::Vector2f NewPosition;
			NewPosition.x = MousePosition.x;
			NewPosition.y = MousePosition.y;
			mHeldPiece->SetPosition(NewPosition);
		}
	}
	else
	{
		if (mHeldPiece)
		{
			//Drop piece

			if (Index.x < 8 && Index.y < 8 && Index.x > -1 && Index.y > -1)
			{
				if ( mHeldPiece->IsMoveLegal(mHeldPieceOrigin, sf::Vector2u(Index.x, Index.y)) )
				{
					ChessSquare* Square = mChessBoard.GetSquare(Index.x, Index.y);
					ChessPiece* Piece = Square->GetPieceOccupyingSquare();

					if (!Piece)
					{
						mHeldPiece->SetPosition(Square->GetPosition());
						Square->SetPieceOccupyingSquare(mHeldPiece);
						mHeldPiece = nullptr;
					}
				}
				else //if move isnt legal, return piece to its origin
				{
					ChessSquare* Square = mChessBoard.GetSquare(mHeldPieceOrigin.x, mHeldPieceOrigin.y);
					mHeldPiece->SetPosition(Square->GetPosition());
					Square->SetPieceOccupyingSquare(mHeldPiece);
					mHeldPiece = nullptr;
				}
			}
		}
	}
}

void Game::SetWindow(sf::RenderWindow* inWindow)
{
	mWindow = inWindow;
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	//target.draw(mBackgroundSprite, states);
	//target.draw(mPlayer, states);
	target.draw(mChessBoard);
}