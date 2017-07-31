#include "tile.h"



tile::tile()
{
	sf::Texture texture;
	if (!texture.loadFromFile("Resources/Test.png")) {
	}
	sprite.setTexture(texture);
}


tile::~tile()
{
}

void tile::draw(sf::RenderWindow *window)
{ 
	sprite.setPosition(100, 100);
	window->draw(sprite);
}
