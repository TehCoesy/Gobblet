#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include "SFML/Graphics.hpp"
#include <vector>

class MessageBoard {
public:
	MessageBoard();
	void drawMB(sf::RenderWindow& window);
	void update(std::string message);

private:
	std::vector<std::string> messages[5];
};

#endif MESSAGEBOARD_H