#pragma once
#include "SFML\Graphics.hpp"
class tile
{
public:
	tile();
	~tile();
	void draw(sf::RenderWindow *w);
private:
	sf::Sprite sprite;
};

