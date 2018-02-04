#include "Player.hpp"
#include <iostream>

Player::Player(int playerNumber)
{
	// Just this line is needed if you remove int playerNumber from the argument list
	sf::String fileName = "../Resources/player1.png";
	
	// Load a different sprite sheet based on what player number is chosen. Remove this if
	// you only have one player.
	if (playerNumber == 1)
		fileName = "../Resources/player1.png";
	else if (playerNumber == 2)
		fileName = "../Resources/player2.png";

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!mTexture.loadFromFile(fileName))
	{
		// Handle error: Print error message.
		std::cout << "ERROR: Player image could not be loaded.\n---" << std::endl;
	}
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// Initialise animation variables.
	mCurrentKeyFrame = sf::Vector2i(0, 0);
	mKeyFrameSize = sf::Vector2i(32, 32);
	mSpriteSheetWidth = 4;
	mAnimationSpeed = 0.2f;
	mKeyFrameDuration = 0.0f;
}

void Player::Update(float DeltaTime)
{
	sf::Vector2f direction(0.0f, 0.0f);

	// Handle input from arrow keys and update direction and animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = -1.0f;
		mKeyFrameDuration += DeltaTime;
		mCurrentKeyFrame.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = 1.0f;
		mKeyFrameDuration += DeltaTime;
		mCurrentKeyFrame.y = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.y = 1.0f;
		mKeyFrameDuration += DeltaTime;
		mCurrentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.y = -1.0f;
		mKeyFrameDuration += DeltaTime;
		mCurrentKeyFrame.y = 3;
	}

	// Check to start jumping
	bool isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	if (isSpacePressed && !mWasSpacePressed && !mIsJumping)
	{
		mIsJumping = true;
		mStartY = mSpriteSheet.getPosition().y;
		mJumpSpeed = -3.0f;
	}

	// Update jump
	if (mIsJumping)
	{
		direction.y = mJumpSpeed;
		mJumpSpeed += mGravity * DeltaTime;

		// Check to see if jump is finished and if so, clean up.
		if (mSpriteSheet.getPosition().y > mStartY)
		{
			mIsJumping = false;
			mSpriteSheet.setPosition(mSpriteSheet.getPosition().x, mStartY);
			mJumpSpeed = 0.0f;
		}
	}

	mSpriteSheet.move(direction * mSpeed * DeltaTime);

	// Update animation
	if (mKeyFrameDuration >= mAnimationSpeed)
	{
		mCurrentKeyFrame.x++;

		if (mCurrentKeyFrame.x >= mSpriteSheetWidth)
			mCurrentKeyFrame.x = 0;

		mSpriteSheet.setTextureRect(sf::IntRect(mCurrentKeyFrame.x * mKeyFrameSize.x,
			mCurrentKeyFrame.y * mKeyFrameSize.y, mKeyFrameSize.x, mKeyFrameSize.y));
		mKeyFrameDuration = 0.0f;
	}

	mWasSpacePressed = isSpacePressed;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}