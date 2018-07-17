#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window/Mouse.hpp"

#include "Game.h"
#include "Interface.h"

#define WINDOW_WIDTH 624
#define WINDOW_HEIGHT 624

class Application {
public:
	Application();

	void runLoop();
	void onMouseClick();
private:
	sf::ContextSettings setting;
	sf::RenderWindow m_window;
	sf::Mouse mouse;

	Game game;
	Interface ui = Interface(m_window);

	int gameState = 1;
	bool mouseClick = false;

	void checkInput(std::string input);
	void onStart();
};

#endif // !APPLICATION_H
