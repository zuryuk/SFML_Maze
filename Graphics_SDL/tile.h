#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
struct Textures {
	sf::Texture t_top, t_bot, t_rgt, t_lft;
};
class tile
{
public:
	tile();
	tile(Textures &t, int x, int y);
	~tile();
	void draw(sf::RenderWindow *w);
	void setTile(bool b_top, bool b_bot, bool b_rgt, bool b_lft);
private:
	int pos_x, pos_y;
	sf::Sprite s_top,s_bot,s_rgt,s_lft;
	bool top, bottom, right, left;
};

