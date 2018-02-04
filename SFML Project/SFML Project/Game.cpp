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
	mPlayerTurnText.setString(sf::String("White's turn"));
	mPlayerTurnText.setPosition(sf::Vector2f(0.0, 0.0));
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
			if (SquareIndexIsValid(Index))
			{
				ChessSquare* Square = mChessBoard.GetSquare(Index.x, Index.y);
				ChessPiece* Piece = Square->GetPieceOccupyingSquare();
				if (Piece && Piece->GetColor() == mColorOfCurrentPlayer)
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
			NewPosition.x = MousePosition.x - (SQUARE_SIZE / 2.0f);
			NewPosition.y = MousePosition.y - (SQUARE_SIZE / 2.0f);
			mHeldPiece->SetPosition(NewPosition);
		}
	}
	else
	{
		if (mHeldPiece)
		{
			//Drop piece

			if (SquareIndexIsValid(Index))
			{
				if ( mHeldPiece->IsMoveLegal(&mChessBoard, mHeldPieceOrigin, sf::Vector2u(Index.x, Index.y)) )
				{
					ChessSquare* Square = mChessBoard.GetSquare(Index.x, Index.y);
					ChessPiece* Piece = Square->GetPieceOccupyingSquare();

					if (!Piece)
					{
						mHeldPiece->SetPosition(Square->GetPosition());
						mHeldPiece->SetHasMoved(true);
						Square->SetPieceOccupyingSquare(mHeldPiece);
						mHeldPiece = nullptr;
						
						EndTurn();
					}
					else //there's a piece on destination square; check if it's opponents piece
						 //and if so, capture it.
					{
						if (Piece->GetColor() != mColorOfCurrentPlayer)
						{
							std::vector<ChessPiece*>* Pieces = mChessBoard.GetPiecesVector();
							RemovePiece(Pieces, Piece);
							mHeldPiece->SetPosition(Square->GetPosition());
							mHeldPiece->SetHasMoved(true);
							Square->SetPieceOccupyingSquare(mHeldPiece);
							mHeldPiece = nullptr;

							EndTurn();
						}
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
			else //if we are holding a piece but SquareIndex is not legal
			{
				ChessSquare* Square = mChessBoard.GetSquare(mHeldPieceOrigin.x, mHeldPieceOrigin.y);
				mHeldPiece->SetPosition(Square->GetPosition());
				Square->SetPieceOccupyingSquare(mHeldPiece);
				mHeldPiece = nullptr;
			}
		}
	}
}

void Game::SetWindow(sf::RenderWindow* inWindow)
{
	mWindow = inWindow;
}

void Game::EndTurn()
{
	mColorOfCurrentPlayer = (mColorOfCurrentPlayer == WHITE ? BLACK : WHITE);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	//target.draw(mBackgroundSprite, states);
	//target.draw(mPlayer, states);
	target.draw(mChessBoard);
	target.draw(mPlayerTurnText);
}