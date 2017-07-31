#include <iostream>
#include "SFML/Graphics.hpp"
#include "maze.h"
#include "tile.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "TEST");
	sf::Texture texture;
	tile tile;
	bool direction = true;
	maze maze;
	if (!texture.loadFromFile("Resources/Test.png")) {
	std::cout << "Error loading resources" << std::endl;
	}
	sf::Sprite sprite(texture);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::KeyPressed:
				switch (event.key.code){
				case sf::Keyboard::Space:
					std::cout << "Space pressed" << std::endl;
					direction = !direction;
				}
			case sf::Event::MouseButtonPressed:
				switch (event.key.code) {
				case 0:
					std::cout << "LMB pressed" << std::endl;
					if (direction) {
						sprite.setPosition((sf::Vector2f) sf::Mouse::getPosition(window));
					}
					break;
				case 1:
					std::cout << "RMB pressed" << std::endl;
					if (!direction) {
						sprite.setPosition((sf::Vector2f) sf::Mouse::getPosition(window));
					}
					break;
				}
			}
		}
		window.clear();
		tile.draw(&window);
		//Drawing here
		window.display();
	}
	return 0;
}