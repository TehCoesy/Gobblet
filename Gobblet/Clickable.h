#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "SFML/Graphics.hpp"

class Clickable {
public:
	Clickable();

	void newButton(std::string in1, std::string in2, sf::Vector2f in3);

	void drawButton(sf::RenderWindow& window);
	bool getBound(int x, int y);

	sf::Vector2f position;
private:
	int state = 0;
	std::string text;
	std::string event;
};

#endif // !CLICKABLE_H
