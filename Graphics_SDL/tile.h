#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
struct Textures {
	sf::Texture t_top, t_bot, t_rgt, t_lft;
};
enum WALL {
	WALL_NORTH = 0x0008, WALL_EAST = 0x0004,
	WALL_SOUTH = 0x0002, WALL_WEST = 0x0001,
	WALL_ALL = 0x000f, WALL_NONE = 0x0000
};
class tile
{
public:
	tile();
	tile(Textures &t, int x, int y);
	~tile();
	void draw(sf::RenderWindow *w);
	void setTile(int w);
	void removeWall(int w);
	void setPos(int x, int y);
	bool isVisited();
	void toggleVisited();
	int getX();
	int getY();
	bool getWalls();
private:
	int walls;
	int pos_x, pos_y;
	bool visited;
	sf::Sprite s_top,s_bot,s_rgt,s_lft;
};

