#pragma once
#include "SFML\Graphics.hpp"

class Timer :
	public sf::Drawable
{
public:
	sf::Time mTimeLeft = sf::Time(sf::seconds(300));
	sf::Clock mClock;
	sf::Text mTimeText;

	bool bTicking = false;

	void Start();
	void Pause();
	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Timer(const sf::Font& inFont, sf::Vector2f inPosition);
	~Timer();
};

