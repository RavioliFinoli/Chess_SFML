#include <SFML/Graphics.hpp>
#include "Game.hpp"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "Game Window");
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