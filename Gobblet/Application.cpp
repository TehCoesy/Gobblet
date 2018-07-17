#include "Application.h"

Application::Application() {
	setting.antialiasingLevel = 4;
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gobblets!", sf::Style::Close, setting);
	m_window.setFramerateLimit(60);
	onStart();
}

void Application::runLoop() {
	sf::Event eventMain;
	while (m_window.isOpen()) {
		m_window.pollEvent(eventMain);

		if (eventMain.type == sf::Event::Closed) {
			m_window.close();
			break;
		}

		if (eventMain.type == sf::Event::MouseButtonPressed) {
			if (!mouseClick) {
				onMouseClick();
				mouseClick = true;
			}
		}

		if (eventMain.type == sf::Event::MouseButtonReleased) {
			mouseClick = false;
		}

		m_window.clear();
		ui.drawMenu();
		if (gameState == 1) {
			game.update();
			game.drawGame(m_window);
		}
		m_window.display();
	}
}

void Application::onMouseClick() {
	sf::Vector2i input = mouse.getPosition(m_window);
	std::cout << "Mouse Click! X Y " << input.x << " " << input.y << " ";
	game.onMouseClick(input.x, input.y);
	checkInput(ui.onMouseClick(input.x, input.y));
	std::cout << std::endl;
}

void Application::checkInput(std::string input) {

}

void Application::onStart() {
	game.newGame();
}