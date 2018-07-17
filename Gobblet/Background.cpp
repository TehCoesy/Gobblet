#include "Background.h"

Background::Background() {
	if (!textureBG.loadFromFile("Resources/Texture/background_texture.jpg")) {
		throw "Failed to load background_texture.jpg";
	}
	background.setTexture(textureBG);
	background.setTextureRect(sf::IntRect(0, 0, 800, 800));
}

void Background::drawBG(sf::RenderWindow& window) {
	window.draw(background);
}