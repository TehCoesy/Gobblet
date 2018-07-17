#ifndef INTERFACE_H
#define INTERFACE_H

#include "SFML/Graphics.hpp"

#include "Background.h"
#include "Clickable.h"

#include <vector>

class Interface {
public:
	Interface(sf::RenderWindow& m_window);

	void drawMenu();
	void initMenu();

	void drawGameInterface();
	void initGameInterface();

	std::string onMouseClick(int x, int y);
private:
	void drawBG();
	void drawButton();

	std::vector<Clickable> arrButton;
	Background background;
	sf::RenderWindow* window;
};
#endif // !INTERFACE_H
