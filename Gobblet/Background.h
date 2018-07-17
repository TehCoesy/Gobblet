#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SFML/Graphics.hpp"

class Background {
public:
	Background();
	void drawBG(sf::RenderWindow& window);
private:
	sf::Texture textureBG;
	sf::Sprite background;
};

#endif // !BACKGROUND_H
