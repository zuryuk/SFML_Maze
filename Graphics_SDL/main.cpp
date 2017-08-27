#include <iostream>
#include "SFML/Graphics.hpp"
#include "tile.h"
#include <time.h>
#include <vector>

#define TILE_SIZE 40
enum DIR { NORTH, SOUTH, WEST, EAST};
struct COORD {
	int x;
	int y;
} trail_crd;
const int ROWS = 9;
const int COLS = 9;

int main() {
	//RNG
	int rng_dir;
	srand(time(NULL));
	//Maze generation
	int curX;
	int curY;
	std::vector<COORD> trail;
	std::vector<DIR> live;
	//Textures
	sf::RenderWindow window(sf::VideoMode(600, 600), "TEST");
	Textures t_tile; //Defined in tile.h
	sf::Texture x;
	sf::Sprite x_sprite;
	if (!(t_tile.t_top.loadFromFile("Resources/Top.png"))) {
	}
	if (!(t_tile.t_bot.loadFromFile("Resources/Bottom.png"))) {
	}
	if (!(t_tile.t_rgt.loadFromFile("Resources/Left.png"))) {
	}
	if (!(t_tile.t_lft.loadFromFile("Resources/Right.png"))) {
	}
	if (!(x.loadFromFile("Resources/x.png"))) {
	}
	x_sprite.setTexture(x);
	std::vector<std::vector<tile>> maze;
	for (int j = 0; j < 10; j++) {
		std::vector<tile> tile_vec;
		for (int i = 0; i < 10; i++) {
			tile_vec.push_back(tile(t_tile, 100 + i * TILE_SIZE, 100 + j* TILE_SIZE));
			tile_vec.at(i).setTile(WALL_ALL);
		}
		maze.push_back(tile_vec);
	}
	curX = rand() % ROWS;
	curY = rand() % COLS;
	trail_crd.x = curX;
	trail_crd.y = curY;
	x_sprite.setPosition(100 + TILE_SIZE * curX, 100 + TILE_SIZE * curY);
	trail.push_back(trail_crd);
	while (trail.empty() == false) {
		window.clear();
		window.draw(x_sprite);
		//Drawing here
		for (auto col = maze.begin(); col != maze.end(); ++col) {
			for (auto row = col->begin(); row != col->end(); ++row) {
				row->draw(&window);
			}
		}
		window.display();
		std::cout << "X: " <<  curX << ", Y: " << curY << std::endl;
		std::cout << "Trail not empty" << std::endl;
		live.clear();

		if (curY > 0) 
			if (maze[curY - 1][curX].getWalls()) 
				live.push_back(NORTH);
		if (curY < ROWS) 
			if (maze[curY + 1][curX].getWalls()) 
				live.push_back(SOUTH);
		if (curX > 0) 
			if (maze[curY][curX - 1].getWalls()) 
				live.push_back(WEST);
		if (curX < COLS) 
			if (maze[curX + 1][curY].getWalls()) 
				live.push_back(EAST);
		std::cout << "Live size: "<< live.size() << std::endl;
		for (auto &i : live) {
			std::cout << i;
		}
		system("pause");
		if (live.size() != 0) {
			switch (live[rand() % live.size()]) {
			case 0:
				curY--;
				break;
			case 1:
				curY++;
				break;
			case 2:
				curX--;
				break;
			case 3:
				curX++;
				break;
			}
			x_sprite.setPosition(100 + TILE_SIZE * curX, 100 + TILE_SIZE * curY);
		}
		else {
			trail.pop_back();
			if (trail.empty() == false) {
				curX = trail.back().x;
				curY = trail.back().y;
			}
		}
	}
	bool direction = true;
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
		window.draw(x_sprite);
		//Drawing here
		for (auto col = maze.begin(); col != maze.end(); ++col) {
			for (auto row = col->begin(); row != col -> end(); ++row) {
				row->draw(&window);
			}
		}
		window.display();		
	}
	return 0;
}