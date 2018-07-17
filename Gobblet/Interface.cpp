#include "Interface.h"

Interface::Interface(sf::RenderWindow& m_window) {
	window = &m_window;
}

void Interface::drawMenu() {
	drawBG();
}

void Interface::initMenu() {
	
}

void Interface::drawGameInterface() {
	drawBG();
}

void Interface::initGameInterface() {

}

void Interface::drawBG() {
	background.drawBG(*window);
}

void Interface::drawButton() {

}

std::string Interface::onMouseClick(int x, int y) {
	return "";
}