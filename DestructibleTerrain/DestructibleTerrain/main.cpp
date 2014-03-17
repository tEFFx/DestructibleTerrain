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
	EntityTool::newBazooka(sf::Vector2f(800, 200));

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
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && click == false)
			{
				//Terrain::getInstance().createHole(sf::Vector2f(sf::Mouse::getPosition(window)), 100);
				EntityTool::newBomb(sf::Vector2f(sf::Mouse::getPosition(window)));
				click = true;
			}

			else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				click = false;
			}

			EntityTool::update();

			window.clear();
			window.draw(sf::Sprite(bgTexture));
			Terrain::getInstance().draw(window);
			EntityTool::draw(window);
			window.display();
		}
    }

    return 0;
}