#include <SFML/Graphics.hpp>
#include "ResourceTracker.h"
#include <iostream>

int main()
{
	ResourceTracker::getInstance();

	sf::Texture texture;
	if (!texture.loadFromFile("Test.png"))
	{
		std::cout << "Failed to load Test.png\n";
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}