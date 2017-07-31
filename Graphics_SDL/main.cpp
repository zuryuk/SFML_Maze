#include <iostream>
#include "SFML/Graphics.hpp"
#include "maze.h"
#include "tile.h"
#include <vector>

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "TEST");
	Textures t_tile;
	if (!(t_tile.t_top.loadFromFile("Resources/Top.png"))) {
	}
	if (!(t_tile.t_bot.loadFromFile("Resources/Bottom.png"))) {
	}
	if (!(t_tile.t_rgt.loadFromFile("Resources/Left.png"))) {
	}
	if (!(t_tile.t_lft.loadFromFile("Resources/Right.png"))) {
	}
	std::vector<tile> tile_vec;
	for (int i = 0; i < 10; i++) {
		tile_vec.push_back(tile(t_tile, i * 35, 0));
		tile_vec.at(i).setTile(true, true, false, false);
	}
	bool direction = true;
	maze maze;
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
					}
					break;
				case 1:
					std::cout << "RMB pressed" << std::endl;
					if (!direction) {
					}
					break;
				}
			}
		}
		window.clear();
		//Drawing here
		for (std::vector<tile>::iterator it = tile_vec.begin(); it != tile_vec.end(); ++it) {
			std::cout << "iteration";
			it->draw(&window);
		}
		window.display();		
		std::cin.get();
	}
	return 0;
}