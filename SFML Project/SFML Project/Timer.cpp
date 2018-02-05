#include "Timer.h"



void Timer::Start()
{
	bTicking = true;
	mClock.restart();
}

void Timer::Pause()
{
	bTicking = false;
}

void Timer::Update()
{
	if (bTicking)
	{
		mTimeLeft -= mClock.getElapsedTime();
		mTimeText.setString(std::to_string(mTimeLeft.asSeconds()));
	}
}

void Timer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mTimeText);
}

Timer::Timer(const sf::Font& inFont, sf::Vector2f inPosition)
{
	mTimeText.setPosition(inPosition);
	mTimeText.setFont(inFont);
	mTimeText.setCharacterSize(40);
	mTimeText.setFillColor(sf::Color::Red);
}


Timer::~Timer()
{
}
