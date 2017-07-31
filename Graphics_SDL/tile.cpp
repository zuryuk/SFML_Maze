#include "tile.h"



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
	top = false; bottom = false; right = false; left = false;

}


tile::~tile()
{
}

void tile::draw(sf::RenderWindow *window)
{ 
	if (top) {
		window->draw(s_top);
	}
	if (bottom) {
		window->draw(s_bot);
	}
	if (right) {
		window->draw(s_rgt);
	}
	if (left) {
		window->draw(s_lft);
	}
}

void tile::setTile(bool b_top, bool b_bot, bool b_rgt, bool b_lft)
{
	top = b_top;
	bottom = b_bot;
	right = b_rgt;
	left = b_lft;
}
