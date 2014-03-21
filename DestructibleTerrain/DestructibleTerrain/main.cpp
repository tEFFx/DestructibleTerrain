#include <SFML/Graphics.hpp>
#include "Terrain.h"
#include "EntityTool.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Destructible Terrain");
	window.setFramerateLimit(60);
	sf::Texture bgTexture;
	bgTexture.loadFromFile("background.png");
	bool click = false;
	bool focus = true;

	Entity* player = EntityTool::newPlayer();
	EntityTool::newBazooka(sf::Vector2f(700, 200));
	EntityTool::newMachinegun(sf::Vector2f(1000, 100));

    while (window.isOpen())
    {
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
			
			if(event.type == sf::Event::LostFocus)
			{
				focus = false;
			}

			else if(event.type == sf::Event::GainedFocus)
			{
				focus = true;
			}
        }

		if(focus == true)
		{
			EntityTool::update();

			window.clear();
			window.draw(sf::Sprite(bgTexture));
			Terrain::getInstance().draw(window);
			EntityTool::draw(window);
			window.display();

			if(player->getBox()->getPosition().y > 720 ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				EntityTool::reset();
				Terrain::getInstance().reset();
			}
		}
    }

    return 0;
}