#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Defines.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(LEFT_SIDE_OFFSET + (8 * SQUARE_SIZE),(8 * SQUARE_SIZE)), "Game Window");
	Game game;
	game.SetWindow(&window);
	sf::Clock gameTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update()
		game.Update(gameTime.restart().asSeconds());

		// Draw()
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}