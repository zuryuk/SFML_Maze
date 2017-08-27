#include "tile.h"
struct cell {
};


tile::tile()
{
}

tile::tile(Textures &t,int x, int y)
{
	pos_x = x;
	pos_y = y;
	s_top.setTexture(t.t_top);
	s_bot.setTexture(t.t_bot);
	s_rgt.setTexture(t.t_rgt);
	s_lft.setTexture(t.t_lft);
	s_top.setPosition(x, y);
	s_bot.setPosition(x, y);
	s_rgt.setPosition(x, y);
	s_lft.setPosition(x, y);
	visited = false;

}


tile::~tile()
{
}

void tile::draw(sf::RenderWindow *window){
	if ((walls & WALL_NORTH) != 0) {
		window->draw(s_top);
	}
	if ((walls & WALL_EAST) != 0) {
		window->draw(s_rgt);
	}	
	if ((walls & WALL_WEST) != 0) {
		window->draw(s_lft);
	}	
	if ((walls & WALL_SOUTH) != 0) {
		window->draw(s_bot);
	}
}

void tile::setTile(int w)
{
	walls = w & WALL_ALL;
}

void tile::removeWall(const int w) {
	if (w != WALL_NORTH && w != WALL_EAST && w != WALL_SOUTH && w != WALL_WEST)
		throw std::string("Illegal wall argument");
	walls -= w;
	std::cout << "Walls: " << walls << std::endl;;
}

void tile::setPos(int x, int y)
{
	pos_x = x;
	pos_y = y;
}
bool tile::isVisited() {
	return visited;
}
bool tile::getWalls(){
	return walls == WALL_ALL;
}
