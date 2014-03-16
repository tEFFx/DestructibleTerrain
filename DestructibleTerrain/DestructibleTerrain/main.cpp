#include <SFML/Graphics.hpp>
#include "Terrain.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Destructible Terrain");
	sf::Texture bgTexture;
	bgTexture.loadFromFile("background.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Terrain::getInstance().createHole(sf::Vector2f(sf::Mouse::getPosition(window)), 100);
		}

        window.clear();
		window.draw(sf::Sprite(bgTexture));
		Terrain::getInstance().draw(window);
        window.display();
    }

    return 0;
}