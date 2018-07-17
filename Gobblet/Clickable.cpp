#include "Clickable.h"

Clickable::Clickable() {
}

void Clickable::newButton(std::string in1, std::string in2, sf::Vector2f in3) {
	text = in1;
	event = in2;
	position = in3;
}

void Clickable::drawButton(sf::RenderWindow& window) {

}

bool Clickable::getBound(int x, int y) {
	return false;
}

