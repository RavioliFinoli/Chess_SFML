#include "Timer.h"
#include <iomanip> // setprecision
#include <sstream> // stringstream



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

		std::stringstream stream;
		stream << std::fixed << std::setprecision(1) << mTimeLeft.asSeconds();
		std::string s = stream.str();

		mTimeText.setString(s.c_str());
		mClock.restart();
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
